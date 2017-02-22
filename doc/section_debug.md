# Отладка

## Отладка в QEMU
Для отладки приложения нужно открыть две вкладки терминала (или два окна) в директории приложения,
затем в одной из них выполнить команду `scons rundbg`, а в другой `scons debug`.
В результате в первой вкладке будет запущена система в эмуляторе QEMU, а во второй — отладчик, настроенный на взаимодействие с QEMU.
Обратите внимание: BSP, указанный при сборке, должен совпадать с BSP, указанным при запуске.
Обратите внимание: при перезапуске QEMU отладчик тоже должен быть перезапущен.

Чтобы получить доступ к отладочной информации раздела, выполните в окне отладчика команду

    add-symbol-file <путь_к_ELF-файлу> 0x80001000
    
Например:

    add-symbol-file P1/build/e500mc/part.elf 0x80001000.
    
*Обратите внимание*: невозможно подключить данный отладчик более чем к одному разделу одновременно.
Таким образом, при попытке подключения нескольких разделов отладочная информация будет доступна только для раздела, подключенного последним.

## Использование встроенного отладчика
Для отладки приложений с помощью встроенного отладчика, поддерживающего многопроцессорность и переключение между разделами, нужно запустить систему через команду

    scons run-gdb
    
в одном окне терминала, а в другом запустить GDB через команду

    scons debug-gdb

Систему можно заставить ждать подключения GDB-клиента, остановив её во время загрузки.
Для этого система должна быть собрана с флагом компилятора POK_NEEDS_WAIT_FOR_GDB.
Флаг включается следующим образом: найдите в SConstruct приложения строку 

    cflags = ''

и замените её на

    cflags = '-D POK_NEEDS_WAIT_FOR_GDB'

(см. [Параметры сборки](#параметры-сборки)).

В отладчике реализована поддержка *inferiors* (каждый из них связан с одним разделом), с помощью которых можно переключаться между разными разделами и выполнять для них различные действия.

Переключение между разделами возможно с помощью команды

    inferior N

где N — это номер раздела (разделы нумеруются с 1, причем 1-й раздел — это системный раздел ядра, 2-й раздел — это раздел 1-го пользовательского раздела, 3-й — 2-го и так далее).

В отладчике доступны все те же функции, что и в стандартном GDB, и вызываются они соответствующими командами:

 - Создание точек останова.
Нужно учитывать, что при наличии нескольких функций с одинаковым названием в пользовательских разделах точки останова будут созданы для каждой из этих функций.
В случае, если требуется останавливаться только в определённом разделе, создайте точку останова для нужного процесса этого раздела
(команда `break ADDR thread N` создаст точку останова во всех этих разделах, но остановка будет происходить лишь в выбранном процессе).

 - Просмотр состояния процессов (используется стандартная команда `info threads`).
В перечне процессов номер процесса состоит из двух цифр, разделённых точкой — номера раздела и номера процесса в системе. Пример вывода команды:

        Id   Target Id                     Frame
        30   Thread 1.27 (* P0 Stopped) pok_trap_addr ()
            at /home/freescale/work/chpok/kernel/arch/ppc/entry.S:424

    Здесь *30* — номер процесса в клиентской части отладчика (именно его нужно указывать в команде `thread N`, чтобы переключиться на этот процесс).
    *1.27* — это 27-й процесс системы, находящийся в 1-м разделе (в ядре системы).
    В скобках после номера процесса находится информация о его состоянии (Stopped) и номере раздела (0), а символ '*' означает,
    что именно на этом процессе произошло прерывание в системе и выполнение продолжится именно с него.
    Раздел Frame показывает текущую функцию и файл, в котором эта функция находится.

 - Просмотр состояния разделов, а также возможность узнать, какой раздел является текущим, с помощью команды `info inferiors`.

 - Переключение между процессами и разделами с помощью команд `thread N` и `inferior N` соответственно.
 
 - Просмотр памяти. Поддерживаются все инструкции стандартного отладчика GDB.
Например, команда `x/10i 0xN` выдаст 10 инструкций по адресу 0xN.
Нужно учитывать, что память показывается только для текущего раздела; для просмотра памяти в другом разделе используйте команду переключения между разделами.

 - Возможность перемещения по коду по одной инструкции (single step) поддерживается с помощью стандартной команды `s`. Во время пошагового выполнения все прерывания в системе отключаются.
 
 - Продолжение работы системы возможно с помощью команды `continue` (или сокращённого её варианта `c`).
 
 - Во время работы системы поддерживается остановка системы и переключение в отладчик с помощью нажатия сочетания клавиш Ctrl+C в окне отладчика GDB.
 
 - Удаление точек останова выполняется с помощью стандартной команды `delete`, а их просмотр — с помощью команды `info breakpoints`.

 - Просмотр состояния регистров осуществляется командой info registers.
 
*Обратите внимание*: важно, чтобы в момент использования команды continue отладчик находился в том же разделе, что и во время его остановки, иначе это может вызвать ошибку GDB наподобие такой:

    internal-error: skip_inline_frames: Assertion `find_inline_frame_state (ptid) == NULL' failed.
        
Далее последует запрос об остановке сессии отладки, на что следует ответить отрицательно (на вопрос о создании core-файла также ответьте нет), переключиться на нужный раздел и продолжить работу.
Эта ошибка никак не влияет на работу отладчика, так что можно безбоязненно продолжать отладку.
В случае вылета или критической ошибки со стороны клиента GDB с последующим его завершением система продолжит работу, однако полная её работоспособность не гарантируется,
так как, например, уже поставленные точки останова не удаляются автоматически.
Обратите внимание: при перезапуске QEMU отладчик тоже должен быть перезапущен.
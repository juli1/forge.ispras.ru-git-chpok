#include <types.h>
#include "mmu.h"
#include "reg.h"

/*
 *  Quotes from the manual:
 *
 *      64-entry, fully-associative unified (for instruction and data accesses) L2 TLB array (TLB1)
 *      supports the 11 VSP page sizes shown in Section 6.2.3, “Variable-Sized Pages.”
 *
 * TODO: document parameters
 */
void pok_ppc_insert_tlb1(
        uint32_t virtual, 
        uint64_t physical, 
        unsigned pgsize_enum, 
        unsigned permissions,
        unsigned wimge,
        unsigned pid,
        unsigned entry
        )
{
    /*
     * TLB1 can be written by first writing the necessary information into MAS0–MAS3, MAS5, MAS7, and
     * MAS8 using mtspr and then executing the tlbwe instruction. To write an entry into TLB1,
     * MAS0[TLBSEL] must be equal to 1, and MAS0[ESEL] must point to the desired entry. When the tlbwe
     * instruction is executed, the TLB entry information stored in MAS0–MAS3, MAS5, MAS7, and MAS8 is
     * written into the selected TLB entry in the TLB1 array.
     */
    
    uint32_t mas0, mas1, mas2, mas3, mas7;

    mas0 = MAS0_TLBSEL(1) | MAS0_ESEL(entry);
    mas1 = MAS1_VALID | MAS1_TID(pid) | MAS1_TSIZE(pgsize_enum);
    mas2 = (virtual & MAS2_EPN) | wimge;
    mas3 = (physical & MAS3_RPN) | permissions; 
    mas7 = physical >> 32;

    mtspr(SPRN_MAS0, mas0); 
    mtspr(SPRN_MAS1, mas1); 
    mtspr(SPRN_MAS2, mas2);
    mtspr(SPRN_MAS3, mas3);
    mtspr(SPRN_MAS7, mas7);

    asm volatile("isync; tlbwe; isync":::"memory");
}

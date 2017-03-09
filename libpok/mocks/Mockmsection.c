/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <unity/unity.h>
#include <unity/cmock.h>
#include <mocks/Mockmsection.h>

static const char* CMockString_is_all = "is_all";
static const char* CMockString_msection_enter = "msection_enter";
static const char* CMockString_msection_init = "msection_init";
static const char* CMockString_msection_leave = "msection_leave";
static const char* CMockString_msection_notify = "msection_notify";
static const char* CMockString_msection_wait = "msection_wait";
static const char* CMockString_msection_wq_add = "msection_wq_add";
static const char* CMockString_msection_wq_add_after = "msection_wq_add_after";
static const char* CMockString_msection_wq_del = "msection_wq_del";
static const char* CMockString_msection_wq_init = "msection_wq_init";
static const char* CMockString_msection_wq_notify = "msection_wq_notify";
static const char* CMockString_msection_wq_size = "msection_wq_size";
static const char* CMockString_next = "next";
static const char* CMockString_prev = "prev";
static const char* CMockString_section = "section";
static const char* CMockString_thread = "thread";
static const char* CMockString_thread_id = "thread_id";
static const char* CMockString_timeout = "timeout";
static const char* CMockString_wq = "wq";

typedef struct _CMOCK_msection_init_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  struct msection* Expected_section;

} CMOCK_msection_init_CALL_INSTANCE;

typedef struct _CMOCK_msection_enter_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  struct msection* Expected_section;

} CMOCK_msection_enter_CALL_INSTANCE;

typedef struct _CMOCK_msection_leave_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  struct msection* Expected_section;

} CMOCK_msection_leave_CALL_INSTANCE;

typedef struct _CMOCK_msection_wait_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  pok_ret_t ReturnVal;
  struct msection* Expected_section;
  pok_time_t Expected_timeout;

} CMOCK_msection_wait_CALL_INSTANCE;

typedef struct _CMOCK_msection_notify_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  pok_ret_t ReturnVal;
  struct msection* Expected_section;
  pok_thread_id_t Expected_thread_id;

} CMOCK_msection_notify_CALL_INSTANCE;

typedef struct _CMOCK_msection_wq_init_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  struct msection_wq* Expected_wq;

} CMOCK_msection_wq_init_CALL_INSTANCE;

typedef struct _CMOCK_msection_wq_add_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  struct msection_wq* Expected_wq;
  pok_thread_id_t Expected_next;

} CMOCK_msection_wq_add_CALL_INSTANCE;

typedef struct _CMOCK_msection_wq_add_after_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  struct msection_wq* Expected_wq;
  pok_thread_id_t Expected_prev;

} CMOCK_msection_wq_add_after_CALL_INSTANCE;

typedef struct _CMOCK_msection_wq_del_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  struct msection_wq* Expected_wq;
  pok_thread_id_t Expected_thread;

} CMOCK_msection_wq_del_CALL_INSTANCE;

typedef struct _CMOCK_msection_wq_notify_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  pok_ret_t ReturnVal;
  struct msection* Expected_section;
  struct msection_wq* Expected_wq;
  pok_bool_t Expected_is_all;

} CMOCK_msection_wq_notify_CALL_INSTANCE;

typedef struct _CMOCK_msection_wq_size_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  size_t ReturnVal;
  struct msection* Expected_section;
  struct msection_wq* Expected_wq;

} CMOCK_msection_wq_size_CALL_INSTANCE;

static struct MockmsectionInstance
{
  CMOCK_MEM_INDEX_TYPE msection_init_CallInstance;
  CMOCK_MEM_INDEX_TYPE msection_enter_CallInstance;
  CMOCK_MEM_INDEX_TYPE msection_leave_CallInstance;
  CMOCK_MEM_INDEX_TYPE msection_wait_CallInstance;
  CMOCK_MEM_INDEX_TYPE msection_notify_CallInstance;
  CMOCK_MEM_INDEX_TYPE msection_wq_init_CallInstance;
  CMOCK_MEM_INDEX_TYPE msection_wq_add_CallInstance;
  CMOCK_MEM_INDEX_TYPE msection_wq_add_after_CallInstance;
  CMOCK_MEM_INDEX_TYPE msection_wq_del_CallInstance;
  CMOCK_MEM_INDEX_TYPE msection_wq_notify_CallInstance;
  CMOCK_MEM_INDEX_TYPE msection_wq_size_CallInstance;
} Mock;


void Mockmsection_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  UNITY_SET_DETAIL(CMockString_msection_init);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.msection_init_CallInstance, cmock_line, CMockStringCalledLess);
  UNITY_SET_DETAIL(CMockString_msection_enter);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.msection_enter_CallInstance, cmock_line, CMockStringCalledLess);
  UNITY_SET_DETAIL(CMockString_msection_leave);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.msection_leave_CallInstance, cmock_line, CMockStringCalledLess);
  UNITY_SET_DETAIL(CMockString_msection_wait);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.msection_wait_CallInstance, cmock_line, CMockStringCalledLess);
  UNITY_SET_DETAIL(CMockString_msection_notify);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.msection_notify_CallInstance, cmock_line, CMockStringCalledLess);
  UNITY_SET_DETAIL(CMockString_msection_wq_init);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.msection_wq_init_CallInstance, cmock_line, CMockStringCalledLess);
  UNITY_SET_DETAIL(CMockString_msection_wq_add);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.msection_wq_add_CallInstance, cmock_line, CMockStringCalledLess);
  UNITY_SET_DETAIL(CMockString_msection_wq_add_after);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.msection_wq_add_after_CallInstance, cmock_line, CMockStringCalledLess);
  UNITY_SET_DETAIL(CMockString_msection_wq_del);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.msection_wq_del_CallInstance, cmock_line, CMockStringCalledLess);
  UNITY_SET_DETAIL(CMockString_msection_wq_notify);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.msection_wq_notify_CallInstance, cmock_line, CMockStringCalledLess);
  UNITY_SET_DETAIL(CMockString_msection_wq_size);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.msection_wq_size_CallInstance, cmock_line, CMockStringCalledLess);
}

void Mockmsection_Init(void)
{
  Mockmsection_Destroy();
}

void Mockmsection_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
}

void msection_init(struct msection* section)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_msection_init_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_msection_init);
  cmock_call_instance = (CMOCK_msection_init_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.msection_init_CallInstance);
  Mock.msection_init_CallInstance = CMock_Guts_MemNext(Mock.msection_init_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_msection_init,CMockString_section);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_section), (void*)(section), sizeof(struct msection), cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_msection_init(CMOCK_msection_init_CALL_INSTANCE* cmock_call_instance, struct msection* section)
{
  cmock_call_instance->Expected_section = section;
}

void msection_init_CMockExpect(UNITY_LINE_TYPE cmock_line, struct msection* section)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_msection_init_CALL_INSTANCE));
  CMOCK_msection_init_CALL_INSTANCE* cmock_call_instance = (CMOCK_msection_init_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.msection_init_CallInstance = CMock_Guts_MemChain(Mock.msection_init_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_msection_init(cmock_call_instance, section);
  UNITY_CLR_DETAILS();
}

void msection_enter(struct msection* section)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_msection_enter_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_msection_enter);
  cmock_call_instance = (CMOCK_msection_enter_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.msection_enter_CallInstance);
  Mock.msection_enter_CallInstance = CMock_Guts_MemNext(Mock.msection_enter_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_msection_enter,CMockString_section);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_section), (void*)(section), sizeof(struct msection), cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_msection_enter(CMOCK_msection_enter_CALL_INSTANCE* cmock_call_instance, struct msection* section)
{
  cmock_call_instance->Expected_section = section;
}

void msection_enter_CMockExpect(UNITY_LINE_TYPE cmock_line, struct msection* section)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_msection_enter_CALL_INSTANCE));
  CMOCK_msection_enter_CALL_INSTANCE* cmock_call_instance = (CMOCK_msection_enter_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.msection_enter_CallInstance = CMock_Guts_MemChain(Mock.msection_enter_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_msection_enter(cmock_call_instance, section);
  UNITY_CLR_DETAILS();
}

void msection_leave(struct msection* section)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_msection_leave_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_msection_leave);
  cmock_call_instance = (CMOCK_msection_leave_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.msection_leave_CallInstance);
  Mock.msection_leave_CallInstance = CMock_Guts_MemNext(Mock.msection_leave_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_msection_leave,CMockString_section);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_section), (void*)(section), sizeof(struct msection), cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_msection_leave(CMOCK_msection_leave_CALL_INSTANCE* cmock_call_instance, struct msection* section)
{
  cmock_call_instance->Expected_section = section;
}

void msection_leave_CMockExpect(UNITY_LINE_TYPE cmock_line, struct msection* section)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_msection_leave_CALL_INSTANCE));
  CMOCK_msection_leave_CALL_INSTANCE* cmock_call_instance = (CMOCK_msection_leave_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.msection_leave_CallInstance = CMock_Guts_MemChain(Mock.msection_leave_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_msection_leave(cmock_call_instance, section);
  UNITY_CLR_DETAILS();
}

pok_ret_t msection_wait(struct msection* section, pok_time_t timeout)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_msection_wait_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_msection_wait);
  cmock_call_instance = (CMOCK_msection_wait_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.msection_wait_CallInstance);
  Mock.msection_wait_CallInstance = CMock_Guts_MemNext(Mock.msection_wait_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_msection_wait,CMockString_section);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_section), (void*)(section), sizeof(struct msection), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_msection_wait,CMockString_timeout);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_timeout), (void*)(&timeout), sizeof(pok_time_t), cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_msection_wait(CMOCK_msection_wait_CALL_INSTANCE* cmock_call_instance, struct msection* section, pok_time_t timeout)
{
  cmock_call_instance->Expected_section = section;
  memcpy(&cmock_call_instance->Expected_timeout, &timeout, sizeof(pok_time_t));
}

void msection_wait_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, struct msection* section, pok_time_t timeout, pok_ret_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_msection_wait_CALL_INSTANCE));
  CMOCK_msection_wait_CALL_INSTANCE* cmock_call_instance = (CMOCK_msection_wait_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.msection_wait_CallInstance = CMock_Guts_MemChain(Mock.msection_wait_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_msection_wait(cmock_call_instance, section, timeout);
  memcpy(&cmock_call_instance->ReturnVal, &cmock_to_return, sizeof(pok_ret_t));
  UNITY_CLR_DETAILS();
}

pok_ret_t msection_notify(struct msection* section, pok_thread_id_t thread_id)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_msection_notify_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_msection_notify);
  cmock_call_instance = (CMOCK_msection_notify_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.msection_notify_CallInstance);
  Mock.msection_notify_CallInstance = CMock_Guts_MemNext(Mock.msection_notify_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_msection_notify,CMockString_section);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_section), (void*)(section), sizeof(struct msection), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_msection_notify,CMockString_thread_id);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_thread_id), (void*)(&thread_id), sizeof(pok_thread_id_t), cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_msection_notify(CMOCK_msection_notify_CALL_INSTANCE* cmock_call_instance, struct msection* section, pok_thread_id_t thread_id)
{
  cmock_call_instance->Expected_section = section;
  memcpy(&cmock_call_instance->Expected_thread_id, &thread_id, sizeof(pok_thread_id_t));
}

void msection_notify_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, struct msection* section, pok_thread_id_t thread_id, pok_ret_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_msection_notify_CALL_INSTANCE));
  CMOCK_msection_notify_CALL_INSTANCE* cmock_call_instance = (CMOCK_msection_notify_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.msection_notify_CallInstance = CMock_Guts_MemChain(Mock.msection_notify_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_msection_notify(cmock_call_instance, section, thread_id);
  memcpy(&cmock_call_instance->ReturnVal, &cmock_to_return, sizeof(pok_ret_t));
  UNITY_CLR_DETAILS();
}

void msection_wq_init(struct msection_wq* wq)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_msection_wq_init_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_msection_wq_init);
  cmock_call_instance = (CMOCK_msection_wq_init_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.msection_wq_init_CallInstance);
  Mock.msection_wq_init_CallInstance = CMock_Guts_MemNext(Mock.msection_wq_init_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_msection_wq_init,CMockString_wq);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_wq), (void*)(wq), sizeof(struct msection_wq), cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_msection_wq_init(CMOCK_msection_wq_init_CALL_INSTANCE* cmock_call_instance, struct msection_wq* wq)
{
  cmock_call_instance->Expected_wq = wq;
}

void msection_wq_init_CMockExpect(UNITY_LINE_TYPE cmock_line, struct msection_wq* wq)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_msection_wq_init_CALL_INSTANCE));
  CMOCK_msection_wq_init_CALL_INSTANCE* cmock_call_instance = (CMOCK_msection_wq_init_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.msection_wq_init_CallInstance = CMock_Guts_MemChain(Mock.msection_wq_init_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_msection_wq_init(cmock_call_instance, wq);
  UNITY_CLR_DETAILS();
}

void msection_wq_add(struct msection_wq* wq, pok_thread_id_t next)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_msection_wq_add_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_msection_wq_add);
  cmock_call_instance = (CMOCK_msection_wq_add_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.msection_wq_add_CallInstance);
  Mock.msection_wq_add_CallInstance = CMock_Guts_MemNext(Mock.msection_wq_add_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_msection_wq_add,CMockString_wq);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_wq), (void*)(wq), sizeof(struct msection_wq), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_msection_wq_add,CMockString_next);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_next), (void*)(&next), sizeof(pok_thread_id_t), cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_msection_wq_add(CMOCK_msection_wq_add_CALL_INSTANCE* cmock_call_instance, struct msection_wq* wq, pok_thread_id_t next)
{
  cmock_call_instance->Expected_wq = wq;
  memcpy(&cmock_call_instance->Expected_next, &next, sizeof(pok_thread_id_t));
}

void msection_wq_add_CMockExpect(UNITY_LINE_TYPE cmock_line, struct msection_wq* wq, pok_thread_id_t next)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_msection_wq_add_CALL_INSTANCE));
  CMOCK_msection_wq_add_CALL_INSTANCE* cmock_call_instance = (CMOCK_msection_wq_add_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.msection_wq_add_CallInstance = CMock_Guts_MemChain(Mock.msection_wq_add_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_msection_wq_add(cmock_call_instance, wq, next);
  UNITY_CLR_DETAILS();
}

void msection_wq_add_after(struct msection_wq* wq, pok_thread_id_t prev)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_msection_wq_add_after_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_msection_wq_add_after);
  cmock_call_instance = (CMOCK_msection_wq_add_after_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.msection_wq_add_after_CallInstance);
  Mock.msection_wq_add_after_CallInstance = CMock_Guts_MemNext(Mock.msection_wq_add_after_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_msection_wq_add_after,CMockString_wq);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_wq), (void*)(wq), sizeof(struct msection_wq), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_msection_wq_add_after,CMockString_prev);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_prev), (void*)(&prev), sizeof(pok_thread_id_t), cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_msection_wq_add_after(CMOCK_msection_wq_add_after_CALL_INSTANCE* cmock_call_instance, struct msection_wq* wq, pok_thread_id_t prev)
{
  cmock_call_instance->Expected_wq = wq;
  memcpy(&cmock_call_instance->Expected_prev, &prev, sizeof(pok_thread_id_t));
}

void msection_wq_add_after_CMockExpect(UNITY_LINE_TYPE cmock_line, struct msection_wq* wq, pok_thread_id_t prev)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_msection_wq_add_after_CALL_INSTANCE));
  CMOCK_msection_wq_add_after_CALL_INSTANCE* cmock_call_instance = (CMOCK_msection_wq_add_after_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.msection_wq_add_after_CallInstance = CMock_Guts_MemChain(Mock.msection_wq_add_after_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_msection_wq_add_after(cmock_call_instance, wq, prev);
  UNITY_CLR_DETAILS();
}

void msection_wq_del(struct msection_wq* wq, pok_thread_id_t thread)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_msection_wq_del_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_msection_wq_del);
  cmock_call_instance = (CMOCK_msection_wq_del_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.msection_wq_del_CallInstance);
  Mock.msection_wq_del_CallInstance = CMock_Guts_MemNext(Mock.msection_wq_del_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_msection_wq_del,CMockString_wq);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_wq), (void*)(wq), sizeof(struct msection_wq), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_msection_wq_del,CMockString_thread);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_thread), (void*)(&thread), sizeof(pok_thread_id_t), cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_msection_wq_del(CMOCK_msection_wq_del_CALL_INSTANCE* cmock_call_instance, struct msection_wq* wq, pok_thread_id_t thread)
{
  cmock_call_instance->Expected_wq = wq;
  memcpy(&cmock_call_instance->Expected_thread, &thread, sizeof(pok_thread_id_t));
}

void msection_wq_del_CMockExpect(UNITY_LINE_TYPE cmock_line, struct msection_wq* wq, pok_thread_id_t thread)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_msection_wq_del_CALL_INSTANCE));
  CMOCK_msection_wq_del_CALL_INSTANCE* cmock_call_instance = (CMOCK_msection_wq_del_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.msection_wq_del_CallInstance = CMock_Guts_MemChain(Mock.msection_wq_del_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_msection_wq_del(cmock_call_instance, wq, thread);
  UNITY_CLR_DETAILS();
}

pok_ret_t msection_wq_notify(struct msection* section, struct msection_wq* wq, pok_bool_t is_all)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_msection_wq_notify_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_msection_wq_notify);
  cmock_call_instance = (CMOCK_msection_wq_notify_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.msection_wq_notify_CallInstance);
  Mock.msection_wq_notify_CallInstance = CMock_Guts_MemNext(Mock.msection_wq_notify_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_msection_wq_notify,CMockString_section);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_section), (void*)(section), sizeof(struct msection), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_msection_wq_notify,CMockString_wq);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_wq), (void*)(wq), sizeof(struct msection_wq), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_msection_wq_notify,CMockString_is_all);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_is_all), (void*)(&is_all), sizeof(pok_bool_t), cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_msection_wq_notify(CMOCK_msection_wq_notify_CALL_INSTANCE* cmock_call_instance, struct msection* section, struct msection_wq* wq, pok_bool_t is_all)
{
  cmock_call_instance->Expected_section = section;
  cmock_call_instance->Expected_wq = wq;
  memcpy(&cmock_call_instance->Expected_is_all, &is_all, sizeof(pok_bool_t));
}

void msection_wq_notify_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, struct msection* section, struct msection_wq* wq, pok_bool_t is_all, pok_ret_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_msection_wq_notify_CALL_INSTANCE));
  CMOCK_msection_wq_notify_CALL_INSTANCE* cmock_call_instance = (CMOCK_msection_wq_notify_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.msection_wq_notify_CallInstance = CMock_Guts_MemChain(Mock.msection_wq_notify_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_msection_wq_notify(cmock_call_instance, section, wq, is_all);
  memcpy(&cmock_call_instance->ReturnVal, &cmock_to_return, sizeof(pok_ret_t));
  UNITY_CLR_DETAILS();
}

size_t msection_wq_size(struct msection* section, struct msection_wq* wq)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_msection_wq_size_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_msection_wq_size);
  cmock_call_instance = (CMOCK_msection_wq_size_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.msection_wq_size_CallInstance);
  Mock.msection_wq_size_CallInstance = CMock_Guts_MemNext(Mock.msection_wq_size_CallInstance);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_msection_wq_size,CMockString_section);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_section), (void*)(section), sizeof(struct msection), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_msection_wq_size,CMockString_wq);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_wq), (void*)(wq), sizeof(struct msection_wq), cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_msection_wq_size(CMOCK_msection_wq_size_CALL_INSTANCE* cmock_call_instance, struct msection* section, struct msection_wq* wq)
{
  cmock_call_instance->Expected_section = section;
  cmock_call_instance->Expected_wq = wq;
}

void msection_wq_size_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, struct msection* section, struct msection_wq* wq, size_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_msection_wq_size_CALL_INSTANCE));
  CMOCK_msection_wq_size_CALL_INSTANCE* cmock_call_instance = (CMOCK_msection_wq_size_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.msection_wq_size_CallInstance = CMock_Guts_MemChain(Mock.msection_wq_size_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_msection_wq_size(cmock_call_instance, section, wq);
  memcpy(&cmock_call_instance->ReturnVal, &cmock_to_return, sizeof(size_t));
  UNITY_CLR_DETAILS();
}


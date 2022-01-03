
#ifndef __PUBLIC_PROGRAMMANAGER__
#define __PUBLIC_PROGRAMMANAGER__

#include "DataTypes.h"

#include "Types/DataTypes_Exception.h"
#include "Types/DataTypes_GarbageCollection.h"
#include "Types/DataTypes_InputSystem.h"
#include "Types/DataTypes_ProcessEvent.h"

struct ProgramManager {
  // [*] 프로세스 이벤트
  /** @brief 프로세스 이벤트 주기 */
  struct {
    /** @brief 이벤트들 */
    ProcessEvent Events[8];

    /** @brief 업데이트 주기용 CPU */
    pthread_t UpdateThread;
    /** @brief 고정된 업데이트 주기용 CPU */
    pthread_t FixedUpdateThread;
    /** @brief 고정된 업데이트 주기 */
    unsigned int FixedUpdateTime;

    struct {
      /** @brief 프로그램 초기화 여부 */
      bool IsInitialized;
      /** @brief 프로그램 시작 여부 */
      bool IsStarted;
      /** @brief 업데이트 여부 */
      bool IsUpdated;
      /** @brief 고정된 업데이트 여부 */
      bool IsFixedUpdated;
    } Status;

  } ProcessEvent;

  // [*] 가비지 컬렉션
  // 가비지 컬렉션
  struct {
    /** @brief 현재 가지고 있는 메모리의 총 개수 */
    Length UsedMemoryLength;
    /** @brief 현재 가지고 있는 메모리 페이지의 총 개수 */
    Length UsedMemoryPageLength;

    /** @brief 메모리 페이지 노드 */
    MemoryPage Pages;

    /** @brief 가비지 컬렉션용 메소드들 */
    struct {
      // clang-format off
        struct 
        {
          /**
           * @brief 메모리 생성
           * @param Length 생성할 크기
           * @return void* - 생성된 메모리 주소
           */
          void *(*Create)       (Length);
          /**
           * @brief 수정이 불가능한 메모리 생성
           * @param Length 생성할 크기
           * @return void* - 생성된 메모리 주소
           */
          void *(*ConstCreate)  (Length);
          /**
           * @brief 메모리 소멸
           * @param void** 생성된 메모리의 주소
           * @return None - 없음
           */
          void  (*Remove)       (void **);
          /**
           * @brief 메모리 설정
           * @param void* 수정할 메모리 주소
           * @param int 수정할 값
           * @param Length 수정할 값의 자료형 크기
           * @param Length 수정할 길이
           * @return None - 없음
           */
          void  (*Set)          (void *, int, Length, Length);
          /**
           * @brief 메모리 복사
           * @param void* 복사할 주소
           * @param void* 복사할 값
           * @param Length 복사할 길이
           * @return None - 없음
           */
          void  (*Copy)         (void *, void *, Length);
          /**
           * @brief 메모리 이동
           * @param void* 이동할 주소
           * @param void* 이동할 값
           * @param Length 이동할 길이
           * @return None - 없음
           */
          void  (*Move)         (void *, void *, Length);
          /**
           * @brief 메모리 교환
           * @param void* 교환할 주소.1
           * @param void* 교환할 주소.2
           * @param Length 교환할 주소의 크기
           * @return None - 없음
           */
          void  (*Swap)         (void *, void *, Length);
          /**
           * @brief 메모리 비교
           * @param void* 기준으로 사용할 값이 있는 주소
           * @param void* 비교할 값이 있는 주소
           * @param Length 비교할 크기
           * @return bool - 비교 여부
           */
          bool  (*Compare)      (void *, void *, Length);
          /**
           * @brief 메모리 길이
           * @param void * 찾을 값이 있는 주소
           * @return Length - 생성된 메모리의 길이
           */
          Length (*Length)      (void *);
          /**
           * @brief 메모리 정보
           * @param Length 찾을 값이 있는 주소
           * @return MemoryInfo - 메모리의 대한 정보
           */
          MemoryInfo (*Info)    (void *);
        } Memory;
        
        
        struct 
        {
          /**
           * @brief 메모리 정보
           * @param Length 찾을 값이 있는 주소
           * @return MemoryInfo - 메모리의 대한 정보
           */
          bool (*Policy)              (void *, MemoryPolicy);
          /**
           * @brief 메모리 정보
           * @param Length 찾을 값이 있는 주소
           * @return MemoryInfo - 메모리의 대한 정보
           */
          void (*PolicyAppend)        (void *, MemoryPolicy);
          /**
           * @brief 메모리 정보
           * @param Length 찾을 값이 있는 주소
           * @return MemoryInfo - 메모리의 대한 정보
           */
          void (*PolicyRemove)        (void *, MemoryPolicy);
        } Policy;

      // clang-format on
    } Method;
  } GarbageCollection;

  // [*] 인풋 시스템
  /** @brief */
  struct {
    /** @brief */
    Input Input;
    /** @brief */
    Output Output;
    /** @brief */
    ErrorOutput Error;
  } InputSystem;

  // [*] 오류 처리
  // 오류 처리
  struct {
    ProgramError ErrorCode;
  } Exception;

  // [*] 메소드
  // 메소드
  struct {
    // clang-format off
    /**
     * @brief 프로그램 초기화
     * @param None 없음
     * @return None - 없음
     */
    void (*ProgramInit)         ();
    /**
     * @brief 프로그램 시작
     * @param None 없음
     * @return None - 없음
     */
    void (*ProgramStart)        ();
    /**
     * @brief 프로그램 종료
     * @param None 없음
     * @return None - 없음
     */
    void (*ProgramQuit)         ();

    struct 
    {
      /**
       * @brief 프로그램 종료
       * @param None 없음
       * @return None - 없음
       */
      void (*UpdateStart) ();
      /**
       * @brief 프로그램 종료
       * @param None 없음
       * @return None - 없음
       */
      void (*UpdateStop) ();
      /**
       * @brief 프로그램 종료
       * @param None 없음
       * @return None - 없음
       */
      void (*FixedUpdateStart) ();
      /**
       * @brief 프로그램 종료
       * @param None 없음
       * @return None - 없음
       */
      void (*FixedUpdateStop) ();
    } UpdateMethod;

    // clang-format on
  } Method;
};

/**
 * @brief 프로그램 관리자 및 프로그램 지원 기능
 */
extern struct ProgramManager Program;

void ProgramManager_Init();

#endif
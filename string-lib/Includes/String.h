
#ifndef __NUGUNGA_STRING_HEADER__
#define __NUGUNGA_STRING_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "StringType.h"                     // 문자열 구조체 정의
#include "DMem.h"                           // 동적 메모리 호출

/*
    TODO 주석 작업
    TODO 실재 구현
*/


/** 문자열 객체 생성자
 * @brief <Constructor> : 문자열 객체 생성자
 * 
 * @param ary 데이터
 * @return String 생성된 값
 */
String String_Constructor(const char *data);
/** 문자열 객체 생성
 * @brief <Constructor> : 문자열 공백 객체 생성자
 * 
 * @return String 생성된 값
 */
String String_Constructor_n();
/** 문자열 객체 생성
 * @brief <Constructor> : 문자열 객체 생성자
 * 
 * @param ary 데이터
 * @return String 생성된 값
 */
String String_Constructor_wc(const wchar_t *data);
/** 문자열 객체 소멸
 * @brief <Desctructor> : 문자열 객체 소멸자
 * 
 * @param obj 소멸할 데이터
 */
void String_Desctructor(String obj);
/** 문자열 getter
 * @brief <Getter> obj의 value을 반환합니다.
 * 
 * @param obj 대상 오브젝트
 * @return wchar_t* obj value 값
 */
wchar_t* String_get(const String obj);
/** 문자열 setter
 * @brief <Setter> obj의 value값을 수정합니다.
 * 
 * @param obj 대상 오브젝트
 * @param data 변경할 데이터
 */
void String_set(String obj, const String data);
/** 문자열 setter
 * @brief <Setter> obj의 value값을 수정합니다.
 * 
 * @param obj 대상 오브젝트
 * @param data 변경할 데이터
 */
void String_set_c(String obj, const char *data);
/** 문자열 setter
 * @brief <Setter> obj의 value값을 수정합니다.
 * 
 * @param obj 대상 오브젝트
 * @param data 변경할 데이터
 */
void String_set_wc(String obj, const wchar_t *data);
/** 비교 연산자 
 * @brief <Operator> obj1과 obj2의 value을 비교합니다.
 * 
 * @param obj1 대상 오브젝트
 * @param obj2 대상 오브젝트
 * @return <true/false> value의 값이 같은가?
 */
bool String_equal(const String obj1, const String obj2);
/** 비교 연산자 
 * @brief <Operator> obj1과 obj2의 value을 비교합니다.
 * 
 * @param obj1 대상 오브젝트
 * @param obj2 대상 오브젝트
 * @return <true/false> value의 값이 틀린가?
 */
bool String_notEqueal(const String obj1, const String obj2);
/** 문자열 안에 있는지 확인
 * @brief <Func> obj에 pivot이 있는지 확인합니다.
 * 
 * @param obj 기반 오브젝트
 * @param pivot 기준 오브젝트
 * @return <true/false> obj에 pivot이 있다면?
 */
bool String_contains(const String obj, const String pivot);
/** 문자열이 비어 있는지 확인
 * @brief <Func> obj가 비어있는지 확인합니다.
 * 
 * @param obj 대상 오브젝트
 * @return <true/false> obj가 비어있다면? 
 */
bool String_isEmpty(const String obj);
/** 문자열 안에 문자열이 몇번째 반복되는지 계산
 * @brief <Func> obj안에 pivot이 몇개가 존재하는 지 확인합니다.
 * 
 * @param obj 기반 오브젝트
 * @param pivot 기준 오브젝트
 * @return unsigned int pivot이 들어 있는 횟수
 */
unsigned int String_count(const String obj, const String pivot);
/**
 * @brief 
 * 
 * @param obj 
 * @param data 
 * @return String 
 */
String String_join(const String obj, const String data);
/**
 * @brief 
 * 
 * @param obj 
 * @param chr 
 * @return int
 */
int String_index(const String obj, wchar_t chr);

void String_append(String obj, const String data);
unsigned int String_length(const String obj);
String String_subString(const String obj, const String pivot);
StringAry String_split(const String obj, const String pivot);
String String_upper(const String obj);
String String_lower(const String obj);
String String_loop(const String obj, unsigned int loopCount);

#endif // !__NUGUNGA_STRING_HEADER__
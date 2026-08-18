#pragma once

/*
	Global.h 자료형 선언하고 관리하는 헤더
*/

// Operation 연산하는 행위
enum Operation {
	NONE,
	PLUS,
	MINUS,
	MULT,
	DIVI,
	MOD,
	POW,
	SQRT,
	LAST_LIST
};

// 함수 포인터라고 부릅니다.
// 함수 포인터 = 함수의 주소를 가르키는 포인터 변수
typedef double (*FunctionPointer)(int, int);

// Keyword = 키워드, 핵심 단어
struct KeyWordTable {
	// 연산자의 이름
	const char* Name; // 배열라는 의미인데 우리는 이제부터 2개 이상 문자를 가지는 명령어를 지원할겁니다.
	// 그 해당 연산자가 호출하는 함수.
	FunctionPointer CallbackMethod;
};
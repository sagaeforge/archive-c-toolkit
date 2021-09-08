
#ifndef __NUGUNGA_STRING_TYPE_HEADER__
#define __NUGUNGA_STRING_TYPE_HEADER__

// * 문자열 객체
typedef struct Struct_String
{
    // + length(int) : 문자열 길이
    unsigned int length;
    // + value(wchar_t *) : 문자열 데이터
    wchar_t *value;
} String_Value, *String;

// * 문자열 배열 객체
typedef struct Struct_StringAry
{
    // + length(int) : 문자열 배열 길이
    unsigned int length;
    // + start(Struct_StringAryNode *) : 문자열 배열 노드
    struct Struct_StringAryNode
    {
        // + value(String) : 문자열 객체
        String value;
        // + next(Struct_StringAryNode *) : 다음 노드 위치 
        struct Struct_StringAryNode *next;
    } *start;
} *StringAry;


#endif // !__NUGUNGA_STRING_TYPE_HEADER__
#include <iostream>
#include <locale>

#include "JString.hpp"
#include "JSON.hpp"

using namespace std;

void Initalized()
{
    setlocale(LC_ALL, "");
}

int main()
{
    Initalized();

    #pragma region Description
    // JSON을 생성하려면 크게 4가지로 JSON을 생성함.
    /*
        JSON Temp = new JSON() // 1
        JSON Temp = new JSON(문자열) // 2
        JSON Temp = new JSON(파일) // 3
        JSON Temp = new JSON(JSON객체) // 4
    */

    
    // JSON을 사용할때는 2가지 방법으로 사용이 가능함.
    /*
        // 1
        Temp.insert("가나다", "value")
        auto _var = Temp.get("가나다")

        // 2
        Temp["가나다"] = "Value"
    */

    // JString을 사용하려면 크게 6가지 방법으로 사용할 수 있어야함.
    /*
        JString Str = "가나다";                // 기본형
        JString Str = L"가나다";               // wchar_t형
        JString Str = JString("가나다");       // 클론형
        JString Str = 3.1425;                  // 실수형
        JString Str = 1004;                    // 정수형
        JString Str = true;                    // 논리형
    */

    
    // 이렇게 사용자가 편하도록 개발하면됨.
    // 또한 궁금한 사항이 있을 땐 기획자 최진원을 찾아오면 됨.
    // 또한 이거는 집에 가서도 해라, 하면 할 수 록 실력이 많이 늘거임.
    #pragma endregion

    JString test1 = new JString("Test1 ");
    JString test2 = new JString("Test2 ");

    JString result = test1.Join(test1, test2);
    cout << result.ToString(result);
;}

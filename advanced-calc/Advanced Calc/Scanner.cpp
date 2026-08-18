
#include <iostream>

#include "Utility.h"

// 지역 함수
// 지역 함수 = 이 파일내에서만 호출할 수 있는 함수.
static bool _isDigit(int pCh) {
	return pCh >= '0' && pCh <= '9';
}
static bool _isAlpha(int pCh) {
	return islower(pCh) || isupper(pCh);
}
static bool _isSpace(int pCh) {
	return (pCh >= 9 && pCh <= 13) || pCh == 32;
}
static bool _isOperation(int pCh) {
	return (pCh >= 33  && pCh <= 47) ||
		   (pCh >= 58  && pCh <= 64) ||
		   (pCh >= 91  && pCh <= 96) ||
		   (pCh >= 123 && pCh <= 126);
}

std::vector<std::string> Scanner(const char* Input) {
	std::vector<std::string> Ret;

	// strlen = 문자열의 길이를 알려줍니다.
	for (size_t i = 0; i < strlen(Input); i++)
	{
		if (_isSpace(Input[i])) continue;
		if (_isOperation(Input[i])) {
			char _temp_ary[2];
			_temp_ary[0] = Input[i];
			_temp_ary[1] = '\0';
			Ret.push_back(std::string(_temp_ary));
			continue;
		}
		// TODO: 나중에 기능 업데이트
		if (_isAlpha(Input[i])) continue;
		
		if (_isDigit(Input[i])) {
			long total = Input[i] - '0';
			i += 1;
			if (i <= strlen(Input)) {
				while (_isDigit(Input[i])) {
					total *= 10;
					total += Input[i] - '0';
					i++;
				}
			}
			i -= 1; // 반복문이 끝나면 1이 추가되지?
					// 그런데 나는 이 문자를 한번 더 검사하고 싶은거야.

			Ret.push_back(std::string(std::to_string(total)));
			continue;
		}

		// 지원하지 않는 문자열입니다.
		std::cout << "지원하지 않는 문자열입니다." << std::endl;
	}

	return Ret; // Ret => Return, 반환하는 것.
}
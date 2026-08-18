#include <iostream>
#include <string>
#include "Global.h"
#include "Command.h"
#include "Utility.h"

using namespace std;

struct KeyWordTable OpertorTable[LAST_LIST] = {
	{ "+", Plus },
	{ "-", Minus },
	{ "*", Mult },
	{ "/", Divi },
	{ "%", Mod },
	{ "^", Pow },
	{ "&", Sqrt },
	{ "ENDLIST", NULL },
};

int main()
{
	string op;
	getline(cin, op);
	// word = 한 단어
	auto word = Scanner(op.c_str());
	double sum = -1;
	for (auto var : OpertorTable) {
		if (word[1] == var.Name) {
			sum = var.CallbackMethod(stoi(word[0]), stoi(word[2]));
			break; // < 반복문 멈춰!
		}
		else if (var.Name == "ENDLIST") {
			cerr << "지원하지 않는 명령어입니다." << endl;
			// cerr : console Error라고 부릅니다.
			// 문제가 생겼을 때 운영체제 알리기 쓰는 경우가 있으며
			// 유저에게 문제가 있음을 알릴 때 쓉니다.
			return -1;
		}
	}
	cout << sum << endl;

	return 0;
}

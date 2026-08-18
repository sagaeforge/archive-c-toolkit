
#include "Command.h"

// a = นุ
// b = ม๖ผ๖
double Pow(int a, int b) {
	long Ret = 1;
	for (int i = 0; i < b; i++)
		Ret *= a;
	return b == 0 ? 1 : Ret;
}
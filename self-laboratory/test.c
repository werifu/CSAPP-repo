#include<stdio.h>

int switch_func(int x) {
	int result = 15;
	switch (x) {
	case 1:
		result++;
		break;
	case 2:
		result = 2;
		break;
    case 3:
		result++;
	case 4: 
		result = 4;
		break;
	case 10: 
		result = 10;
	default:
		result = 100;
		break;
	}
	return result;
}
int main() {
	int i = switch_func(233);
	return 0;
}

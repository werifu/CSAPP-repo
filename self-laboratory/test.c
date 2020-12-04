#include<stdio.h>

int main() {
	int x = 3, y;
	for (int i = 0; i < 5; i++) {
    		y = i * (x + 2);
		printf("%d\n", y);
  	}  
	return 0;
}

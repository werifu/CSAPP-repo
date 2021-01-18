#include<stdio.h>

int add(int x, int y) {
    return x+y;
}
int main() {
    int a = 5;
    int b = add(a, 15);
    char ch = 'c';
    char str[5] = "abcd";
    ch = str[10];
    str[4] = '2';
    for (int i = 0; i < 10; i++) {
        ch ++;
    }
    printf("a:%d, c:%c\n", a, ch);
    printf("hello world\n");
    return 0;
}

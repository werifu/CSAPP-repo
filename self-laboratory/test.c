#include<stdio.h>

struct A {
    int a[2];
    int b;
};
int f(int i) {
    struct A s;
    s.b = 0x114514;
    s.a[i] = 0xffff;
	printf("i=%d,b=%d\n", i, s.b);
    return s.b;
}
int main() {
    f(10);
    return 0;
}

#include<stdio.h>
char f(char* str) {
    int v = 1;
    return str[v];
}
int main() {
    char str[20] = "test string\n";
    char a = f(str);
    printf("%c\n", a);
    return 0;
}

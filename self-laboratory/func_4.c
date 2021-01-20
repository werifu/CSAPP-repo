#include<stdio.h>

int func_4(int edx, int esi, int edi) {
    int eax = edx;
    eax -= esi;
    int ecx = eax;
    ecx >> 31;
    eax += ecx;
    eax /= 2;
    ecx = eax + esi;
    if (ecx <= edi) {
        eax = 0;
        if (ecx >= edi) return eax;
               
    }
}

#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

jmp_buf jump;

void segv(int sig) {
    sig = 1;
    longjmp(jump, sig);
}

int mx_is_illegal_memory(void *x) {
    volatile char c;
    int illegal = 0;
    signal(SIGSEGV, segv);
    if (!setjmp(jump))
        c = *(char *)(x);
    else
        illegal = 1;
    signal(SIGSEGV, SIG_DFL);
    return illegal;
}

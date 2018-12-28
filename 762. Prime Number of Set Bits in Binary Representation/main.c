#include <stdio.h>

int MAGIC = 1 << 2 | 1 << 3 | 1 << 5 | 1 << 7 | 1 << 11 | 1 << 13 | 1 << 17 | 1 << 19;

int getNumOfSetBits(int n) {
    int c = 0;
    while (n > 0) {
        n = n & (n - 1);
        c++;
    }
    return c;
}

int isPrime(int n) {
    return (n == 2 || n == 3 || n == 5 || n == 7 
            ||n == 11 || n == 13 || n == 17 || n == 19) ? 1: 0;
}

int isPrimePro(int n) {
    return MAGIC & (1 << n) ? 1 : 0;
}

int countPrimeSetBits(int L, int R) {
    int i, c = 0, n = 0;
    for (i = L; i <= R; i++) {
        n = getNumOfSetBits(i);
        c = c + isPrimePro(n);
    }
    return c;
}

int main(void) {
    int L = 800, R = 900, n;

    n = countPrimeSetBits(800, 900);
    printf("[%d, %d] --> %d\n", L, R, n);

    return 0;
}

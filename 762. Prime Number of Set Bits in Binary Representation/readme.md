762. Prime Number of Set Bits in Binary Representation
---

**Easy**

1. Problem
Given two integers **L** and **R**, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. 
For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)

>Example 1:

    Input: L = 6, R = 10
    Output: 4
    Explanation:
    6 -> 110 (2 set bits, 2 is prime)
    7 -> 111 (3 set bits, 3 is prime)
    9 -> 1001 (2 set bits , 2 is prime)
    10->1010 (2 set bits , 2 is prime)

>Example 2:

    Input: L = 10, R = 15
    Output: 5
    Explanation:
    10 -> 1010 (2 set bits, 2 is prime)
    11 -> 1011 (3 set bits, 3 is prime)
    12 -> 1100 (2 set bits, 2 is prime)
    13 -> 1101 (3 set bits, 3 is prime)
    14 -> 1110 (3 set bits, 3 is prime)
    15 -> 1111 (4 set bits, 4 is not prime)

> Note:
    L, R will be integers L <= R in the range [1, 10^6].  R - L will be at most 10000.


2. Analysis
The problem can be divided into two sub-problems:
- How to get the number of bits for an given integer
- How to check whether the given number is prime number or not

2.1 Get number of set bits in given integer
You can check bit by bit with constant time as following:
```c
int setBits(int n) {
    int i, c = 0;
    for (i = 0; i < N; i++) {
        c += n & (1 << i) ? 1 : 0;
    }
    return c;
}
```
Or much more efficiently:
```c
int setBits(int n) {
    int c = 0;
    while (n > 0) {
        n = n & (n - 1);
        c++;
    }
    return c;
}
```

2.2 Check primer number
There are many ways to check given integer is primer or not. You can refer to (1) for details.
We have constaints in this problem, that is L, R in range __[1, 10^6]__, that is
__2^0 < L <= R < 2^20__, so the bits number is in range __[1, 19]__.
It's a short range, we can just enumerate them as `2, 3, 5, 7, 11, 13, 17, 19`.
We can check as following:
```c
int isPrime(int n) {
    return (n == 2 || n == 3 || n == 5 || n == 7 
            ||n == 11 || n == 13 || n == 17 || n == 19);
}
```
To make it more elegent, we can define a magic to combine all conditions check:
```c
int MAGIC = 1 << 2 | 1 << 3 | 1 << 5 | 1 << 7 | 1 << 11 | 1 << 13 | 1 << 17 | 1 << 19;
int isPrime(int n) {
    return MAGIC & (1 << n);
}

```


3. Reference
- [1. Fun With Prime Numbers](http://www.troubleshooters.com/codecorn/primenumbers/primenumbers.htm)

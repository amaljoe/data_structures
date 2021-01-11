#include <stdio.h>
#include <stdbool.h>
#define SIZE 100

int hash_table[SIZE];
int length;
int n;

bool isPrime(int);
void findN();

void main() {
    printf("Enter the number of elements:\n");
    scanf("%d", &length);
    findN();
    printf("%d", n);
}

void findN() {
    n = length;
    while(!isPrime(n)) {
        n++;
    }
}

bool isPrime(int n) {
    for(int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void linearProbing() {
    for(int i = 0; i < SIZE; i++) {
        hash_table[i] = NULL;
        printf("%d\n", hash_table[i]);
    }
}
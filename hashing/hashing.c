#include <stdio.h>
#include <stdbool.h>
#define SIZE 100

int hash_table[SIZE];
int length;
int n;

bool isPrime(int);
void findN();
int hashing(int);
void input();
void linearProbing(int, int);
void display();

void main() {
    for(int i = 0; i < SIZE; i++) {
        hash_table[i] = -1;
    }
    printf("Enter the number of elements:\n");
    scanf("%d", &length);
    findN();
    input();
    display();
}

void findN() {
    n = length;
    while(!isPrime(n)) {
        n++;
    }
}

bool isPrime(int num) {
    for(int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int hashing(int num) {
    return num % n;
}

void input() {
    printf("Enter the elements:\n");
    for(int i = 0; i < length; i++) {
        int num;
        scanf("%d", &num);
        int hash = hashing(num);
        linearProbing(hash, num);
    }
}

void linearProbing(int hash, int num) {
    while(hash_table[hash] != -1) {
        hash = ++hash % n;
    }
    hash_table[hash] = num;
}

void display() {
    printf("Hash table:\n");
    for(int i = 0; i < n; i++) {
        printf("%d -> %d\n", i, hash_table[i]);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(long long int a, long long int b);
unsigned int countBits(unsigned int n);

int gcd(long long int a, long long int b){
    long long int g, t;
    g = 1;
    while(a % 2 == 0 && b % 2 == 0){
        a = a / 2;
        b = b / 2;
        g = g * 2;
    }
    while (a != 0){
        while(a % 2 == 0){
           a = a / 2; 
        }
        while(b % 2 == 0){
           b = b / 2;  
        }
        t = a - b;
        if (t >= 0) {
            a = t;
        } else {
            b = -t; // Make b positive counterpart of the difference
        }
    }
    return g * b;
}

unsigned int countBits(unsigned int n) 
{ 
   unsigned int count = 0; 
   while (n) 
   { 
        count++; 
        n >>= 1; 
    } 
    return count; 
} 

int main(int argc, char *argv[]){
    char *err;
    long long int a, b, f;
    int bits;

    a = strtoll(argv[1], &err, 10);
    b = strtoll(argv[2], &err, 10); 

    if(b > a){
        long long int temp = a;
        a = b;
        b = temp;
    }

    bits = countBits(a) + countBits(b);

    clock_t begin = clock(); // Records the start time of the program   
    f = gcd(a, b);
    clock_t end = clock();  // Records the stop time of the program
    float time = ( double )( end - begin ) / CLOCKS_PER_SEC;  // Calculates the elapsed time in seconds

    printf("%i\t", bits);
    //printf("%lli\t", f);
    printf("%f\n", time);
    return 0;
}

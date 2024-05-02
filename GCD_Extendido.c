#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void gcd(long long int a, long long int b);

void gcd(long long int a, long long int b){
    long long int d, x, y;
    if (b == 0){
        d = a;
        x = 1;
        y = 0;
        printf("%lli  %lli  %lli\n", d, x, y);
    }
    else{
        long long int x1, x2, y1, y2;
        long long int q, r;
        x1 = 0;
        x2 = 1;
        y1 = 1;
        y2 = 0;
        while (b > 0){
            q = floor(a / b);
            r = a - q * b;
            x = x2 - q * x1;
            y = y2 - q * y1;
            a = b;
            b = r;
            x2 = x1;
            x1 = x;
            y2 = y1;
            y1 = y;
        }
        d = a;
        x = x2;
        y = y2;
        printf("%lli  %lli  %lli\n", d, x, y);
    }
}

int main(int argc, char* argv[]){
    char *err;
    long long int a, b;

    a = strtoll(argv[1], &err, 10);
    b = strtoll(argv[2], &err, 10); 

    if(b > a){
        long long int temp = a;
        a = b;
        b = temp;
    }

    clock_t begin = clock(); // Records the start time of the program   
    gcd(a, b);
    clock_t end = clock();  // Records the stop time of the program
    float time = ( double )( end - begin ) / CLOCKS_PER_SEC;  // Calculates the elapsed time in seconds

    printf("%f\n", time) ;// Prints out the two numbers separated by a space and followed by a newline

    return 0;
}
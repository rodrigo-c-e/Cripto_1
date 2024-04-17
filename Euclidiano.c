#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(long long int a, long long int b);
int gcd(long long int a, long long int b){
    long long int r;
    while (b != 0){
        r = a % b; 
        a = b;
        b = r;
    }
    return a;
}

int main(int argc, char *argv[]){
    char *err;
    long long int a, b, f;

    a = strtoll(argv[1], &err, 10);
    b = strtoll(argv[2], &err, 10); 

    clock_t begin = clock(); // Records the start time of the program   
    f = gcd(a, b);
    clock_t end = clock();  // Records the stop time of the program

    float time = ( double )( end - begin ) / CLOCKS_PER_SEC;  // Calculates the elapsed time in seconds
    printf("%lli  %f\n", f, time) ;// Prints out the two numbers separated by a space and followed by a newline

    return 0;
}
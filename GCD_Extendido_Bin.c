#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gcd1(long long int  x, long long int y, long long int u, long long int v, long long int A, long long int B, long long int C, long long int D, long long int PivoteX, long long int Pivotey, long long int g);
unsigned int countBits(unsigned int n) ;

void gcd1(long long int x,long long int y, long long int u, long long int v, long long int A, long long int B, long long int C, long long int D, long long int PivoteX, long long int  Pivotey, long long int g){
    long long int a, b;

    while( u % 2 == 0 ){
        u = u / 2;
        if(A % 2 == 0 && B % 2 == 0){
            A = A / 2;
            B = B / 2;
        }
        else{
            A = ( A + y ) / 2;
            B = ( B - x ) / 2;
        }
    }
    while( v % 2 == 0 ){
        v = v / 2;
        if( C % 2 == 0 && D % 2 == 0 ){
            C = C / 2;
            D = D / 2;
        }
        else{
            C = ( C + y ) / 2;
            D = ( D - x ) / 2;
        }
    }

    if( u >= v ){
        u = u - v;
        A = A - C;
        B = B - D;
    }
    else{
        v = v - u;
        C = C - A;
        D = D - B;
    }
    if( u == 0 ){
        a = C;
        b = D;
        g = g * v;
        //printf("%lld    %lld    %lld    ", g, a, b);
    }
    else{
        gcd1(x, y, u, v, A, B, C, D, PivoteX, Pivotey, g);
    }

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
    long long int x, y, g, u, v, A, B, C, D, PivoteX, PivoteY;
    long long int bits;

    g = 1;
    x = strtoll(argv[1], &err, 10);
    y = strtoll(argv[2], &err, 10);

    if( y > x ){
        long long int temp = x;
        x = y;
        y = temp;
    }

    bits = countBits(x) + countBits(y);

    PivoteX = x;
    PivoteY = y;

    while( x % 2 == 0 && y % 2 == 0 ){
        x = x / 2;
        y = y / 2;
        g = 2 * g;
    }
    u = x;
    v = y;
    A = 1;
    B = 0;
    C = 0;
    D = 1;

    clock_t begin = clock(); // Records the start time of the program 
    gcd1(x, y, u, v, A, B, C, D, PivoteX, PivoteY, g);
    clock_t end = clock();  // Records the stop time of the program
    float time = ( double )( end - begin ) / CLOCKS_PER_SEC;  // Calculates the elapsed time in seconds

    printf("%lli\t", bits);
    printf("%f\n", time) ;// Prints out the two numbers separated by a space and followed by a newline
    return 0;
}
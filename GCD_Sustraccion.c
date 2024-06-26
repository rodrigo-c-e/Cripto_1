#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int a, int b);
unsigned int countBits(unsigned int n);

int gcd(int a, int b) {
    int r;
    while (b != 0){
        r  = a - b;      //* The reminder of the division between a & b
        if (r > b){
            a = r;       //* If the reminder is greater than b then we set a equal to that value
        } else {
            a = b;        //* If not then we set a equal to b
            b = r;        //* And set b equal to the reminder
        }
    }   
    return a;          //* Returns the GCD which is stored in variable 'a'
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

int main(int argc, char* argv[]){
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

    bits = countBits(a) - countBits(b);

    clock_t begin = clock(); // Records the start time of the program   
    f = gcd(a, b);
    clock_t end = clock();  // Records the stop time of the program
    float time = ( double )( end - begin ) / CLOCKS_PER_SEC;  // Calculates the elapsed time in seconds
    
    printf("%i\t", bits);
    //printf("%lli\t", f);
    printf("%f\n", time);
    return 0;
}

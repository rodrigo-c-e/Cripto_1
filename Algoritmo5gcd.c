#include <stdio.h>
#include <stdlib.h>

void gcd1(long x,long y,long u,long v, long A, long B, long C, long D, long PivoteX, long Pivotey, long g);

void gcd1(long x,long y, long u, long v, long A, long B, long C, long D, long PivoteX, long Pivotey, long g){
    long a,b;

    while(u%2==0){
        u=u/2;
        if(A %2==0 && B%2==0){
            A = A/2;
            B = B/2;
        }
        else{
            A=(A+y)/2;
            B=(B-x)/2;
        }
    }
    while(v%2==0){
        v=v/2;
        if(C%2==0 && D%2==0){
            C=C/2;
            D=D/2;
        }
        else{
            C=(C+y)/2;
            D=(D-x)/2;
        }
    }

    if(u>=v){
        u=u-v;
        A=A-C;
        B=B-D;
    }
    else{
        v=v-u;
        C=C-A;
        D=D-B;
    }
    if(u==0){
        a = C;
        b=D;
        g=g*v;
        printf("%ld * %ld + %ld * %ld = %ld", a,PivoteX,b, Pivotey,g);
    }
    else{
        gcd1(x, y, u, v, A, B, C, D, PivoteX, Pivotey, v);
    }

}

int main(int argc, char *argv[]){
    long x,y,g, u, v, A, B, C, D, PivoteX, PivoteY;
    
    g=1;
    x = atol(argv[1]);
    y = atol(argv[2]);

    PivoteX=x;
    PivoteY=y;

    while(x %2==0 && y%2==0){
        x = x/2;
        y=y/2;
        g=2*g;
    }
    u=x;
    v=y;
    A=1;
    B=0;
    C=0;
    D=1;

    gcd1(x,y, u, v, A, B, C, D, PivoteX, PivoteY, g);

    return 0;
    
}
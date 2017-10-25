#include <stdio.h>

int count = 0;

void BitQueen(unsigned char A, unsigned char B, unsigned char C){
    if(B==0XFF){
        count ++;
        return;
    }
    unsigned char D = ~(A|B|C);
    while(D){
        unsigned char bit = D & (-D);
        D -= bit;
        BitQueen((A|bit)<<1, B|bit, (C|bit)>>1);
    }
}

int main(int argc, char* argv[]){
    BitQueen(0, 0, 0);
    printf("%d\n", count);
    return 0;
}

#include <stdio.h>
int majority(int x,int y,int z){
        if (x+y+z<2) {
                return 0;
        }else
                return 1;
}
int initBit(int x){
        if( x%2 == 0) {
                return 0;
        }
        else return 1;
}
int A51(int *X,int *Y,int *Z){
        int output=initBit(X[18]+Y[21]+Z[22]);
        int maj=majority(X[8],Y[10],Z[10]);
        if (X[8]==maj) {
                int firstBit = initBit(X[13]+X[16]+X[17]+X[18]);
                for (int i = 18; i > 1; i--) {
                        X[i+1]=X[i];
                }
                X[0]=firstBit;
        }
        if (Y[10]==maj) {
                int firstBit = initBit(Y[20]+Y[21]);
                for (int j = 21; j > 1; j--) {
                        Y[j+1]=Y[j];
                }
                Y[0]=firstBit;
        }
        if (Z[10]==maj) {
                int firstBit = initBit(Z[20]+Z[21]+Z[22]);
                for (int t = 22; t > 1; t--) {
                        Z[t+1]=Z[t];
                }
                Z[0]=firstBit;
        }
        return output;
}
int main() {
        int X[] = {1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
        int Y[] = {1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1};
        int Z[] = {1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0};
        for(int i=0; i<10; i++) {
                printf("%d",A51(X,Y,Z));
        }
        return 0;
}

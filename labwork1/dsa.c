//
// Created by huannguyen on 27/10/2019.
//
#include <stdio.h>
#include <stdlib.h>
int modInverse(int a, int m){ //find Ke^-1 and s_-1
        a = a%m;
        for (int x=1; x<m; x++)
                if ((a*x) % m == 1)
                        return x;
}
int i = 0;
int *transBinary(int x,int size){
        int *arr = malloc(size);
        i = 0;
        while (x>0) {
                arr[i]=x%2;
                x=x/2;
                i++;
        }
        return arr;
}
int square_multiply(int x,int e,int m){ // x^e mod m
        int finalVal=1;
        int *temp = transBinary(e,100);
        int first = x % m;
        int modArr[100] = {first};
        for (int j = 1; j < i; j++) {
                modArr[j]= (first*first) % m;
                first = (first*first) % m;
        }
        for (int j = 0; j < i; j++) {
                if (temp[j] == 1) {
                        finalVal = (finalVal * modArr[j]) % m;
                }
        }
        return finalVal % m;
}
int cal_beta(int alpha,int d,int p){ // beta = alpha^d mod p;
        return square_multiply(alpha,d,p);
}
// signature generation
int cal_r(int alpha,int Ke,int p,int q){ //r = (alpha^Ke mod p) mod q
        int temp = square_multiply(alpha,Ke,p);
        return temp % q;
}
int cal_s(int Hx,int d,int r,int Ke,int q){ // s = (Hx + d*r)*Ke^-1 mod q
        int temp = Hx + d * r;
        int inverse = modInverse(Ke,q); //find modular inverse of Ke
        return (temp * inverse) % q;
}
// signature verification
int sig_verifi(int p,int q,int s,int Hx,int r,int alpha,int beta){
        int w = modInverse(s,q); //w = s^-1 mod q
        int u1 = (w * Hx) % q;
        int u2 = (w *r) % q;
        int temp1 = square_multiply(alpha,u1,p); // v = (alpha^u1 * beta^u2 mod p) mod q
        int temp2 = square_multiply(beta,u2,p);
        return ((temp1 * temp2) % p) % q;
}
void check(int v,int r, int q){
        if (v == r % q) {
                printf("valid signature!\n");
        } else {
                printf("invalid signature!\n");
        }
}
int main(){
        int Hx=26, p=59, q=29, alpha=3, d=7, Ke=10;
        int beta = cal_beta(alpha,d,p);
        int r =cal_r(alpha,Ke,p,q);
        printf("r is %d\n",r);
        int s = cal_s(Hx,d,r,Ke,q);
        printf("s is %d\n",s);
        int v = sig_verifi(p,q,s,Hx,r,alpha,beta);
        printf("Kpub = (p,q,alpha,beta)\n");
        printf("Kpri = d\n");
        printf("signature verification is %d\n",v );
        check(v,r,q);
        return 0;
}

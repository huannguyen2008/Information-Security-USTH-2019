#include <stdio.h>
#include <stdlib.h>
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
int square(int x,int e,int m){
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
int findLCM(int n1,int n2){
        int minMultiple = (n1>n2) ? n1 : n2;
        while(1)
        {
                if( minMultiple%n1==0 && minMultiple%n2==0 )
                {break;}
                ++minMultiple;
        }
        return minMultiple;
}
int modInverse(int e, int p, int q){
        int ld = findLCM(p-1,q-1);
        e = e % ld;
        for (int d = 1; d < ld; d++)
                if ((e * d) % ld == 1)
                        return d;
}
int decrypt(int p,int q,int e,int m){
        int n=q*p;
        int c = square(m,e,n);
        int d = modInverse(e,p,q);
        return square(c,d,n);
}
int main() {
        int p = 5, q = 11, e = 3, m=9;
        int n = p*q;
        printf("encrypt is : %d\n",square(m,e,n));
        printf("decrypt is : %d\n",decrypt(p,q,e,m) );
        return 0;
}

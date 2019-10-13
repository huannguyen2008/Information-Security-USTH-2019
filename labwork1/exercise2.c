#include <stdio.h>
#include <stdlib.h>
int i = 0;
int *transBinary(int x,int size){
        int *arr = malloc(size);
        i = 0;
        while (x>0) {
                arr[i]=x%2;
                // printf("%d",x%2 );
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
                // printf("%d\n",first );
                modArr[j]= (first*first) % m;
                first = (first*first) % m;

        }
        for (int j = 0; j < i; j++) {
                // printf("%d\n",temp[j]);
                if (temp[j] == 1) {
                        printf("%d\n",modArr[j] );
                        finalVal = (finalVal * modArr[j]) % m;
                }
        }
        printf("final answer is : %d",finalVal % m);

}
int main() {
        int x = 14;
        int e = 7;
        int m = 55;
        square(x,e,m);
        return 0;
}

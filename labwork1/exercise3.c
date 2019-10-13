#include <stdio.h>
#include <stdlib.h>
int i = 0;
int findLCM(int n1,int n2){
        // maximum number between n1 and n2 is stored in minMultiple
        int minMultiple = (n1>n2) ? n1 : n2;
        // Always true
        while(1)
        {
                if( minMultiple%n1==0 && minMultiple%n2==0 )
                {
                        printf("The LCM of %d and %d is %d.", n1, n2,minMultiple);
                        break;
                }
                ++minMultiple;
        }
}
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
                        printf("%d\n",modArr[j] );
                        finalVal = (finalVal * modArr[j]) % m;
                }
        }
        printf("final answer is : %d",finalVal % m);

}
int main() {
  int n1 = 5;
  int n2 = 10;
  findLCM(n1,n2);
  return 0;
}

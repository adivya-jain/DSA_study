#include<stdio.h>

int main() {

   int arr[10], s, k, w;

   printf("Enter size of an array:");
   scanf("%d", &s);

   printf("Enter array elements:");
   for (int i = 0; i < s; i++) {
       scanf("%d", &arr[i]);
   }

   printf("Prime numbers are :");
   for (int i = 0; i < s; i++) {
       k = 2;
       w= 1;
       while (k < arr[i]) {
           if (arr[i] % k == 0) {
               w = 0;
               break;
           }
           k++;
       }
       if (w == 1) {
           if(arr[i]==1)
           {
               continue;
           }
           else{
           printf("%d ", arr[i]);
           }
       }
   }
   return 0;

}
#include <stdio.h>
//sum of first and last digit of n number
int main()
{
  printf("\a");
  int i, num, last, sum = 0, n;
  printf("how many number u want to enter");
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    printf("enter a number");
    scanf("%d", &num);
    last = num % 10;

    while (num >= 10)
    {
      num = num / 10;
    }
    printf("first digit is %d", num);
    printf("\nlast digit is %d", last);
    sum = num + last;
    printf("\n sum is %d", sum);
  }

  return 0;
}
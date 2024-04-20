#include <stdio.h>
int main()
{
  printf("enter the no of digits you want to write, which should be equal or greater then 8 ");
  int a, p = 0, q = 0, x = 0, z = 0;
  scanf("%d", &a);
  if (a < 8)
  {
    while (a < 8)
    {
      printf("plz enter the value which is greater or equals to 8");
      scanf("%d", &a);
    }
  }
  int arr[a];
  printf("Write the number");
  for (int i = 0; i < a; i++)
  {
    scanf("%d", &arr[i]);
  }
  for (int j = 0; j < a; j++)
  {

    if (arr[j] % 2 == 0)
    {
      p = p + arr[j];
      q = q + 1;
      if (q == 2)
      {
        break;
      }
    }
  }
  for (int k = (a - 1); k >= 0; k--)
  {
    if (arr[k] % 2 != 0)
    {
      x = x + arr[k];
      z = z + 1;
      if (z == 2)
      {
        break;
      }
    }
  }

  printf("sum of first 2 even number is %d", p);
  printf("\n sum of last 2 odd number is %d", x);
  printf("\n sum is %d", p + x);
  return 0;
}
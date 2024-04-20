#include <stdio.h>
int fibonacci(int n)
{
    int term1 = 0, term2 = 1, next_term;
    next_term = term1 + term2;
    // fabbonaccic series :-sum of previous two terms is third term

    for (int i = 0; i < n - 2; i++)
    {
        printf(",%d\t", next_term);
        term1 = term2;
        term2 = next_term;
        next_term = term1 + term2;
    }
}

int main()
{

    int term1 = 0, term2 = 1, next_term;
    int n;
    

    printf("eneter the number of terms:");
    scanf("%d", &n);
    printf("fibonacci series %d , %d", term1, term2);
    fibonacci(n);

    return 0;
}
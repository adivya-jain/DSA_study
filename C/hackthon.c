#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int Possibility (int N, int M, long long* A) {

   
   
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        scanf("%d", &N);
        int M;
        scanf("%d", &M);
        int i_A;
        long long A = (long long*)malloc(sizeof(long long)(N));
        for(i_A = 0; i_A < N; i_A++)
        	scanf("%lld",&A[i_A]);

        int out_ = Possibility(N, M, A);
        printf("%d", out_);
        printf("\n");
    }
}
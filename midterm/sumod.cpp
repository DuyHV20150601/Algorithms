#include <stdio.h>
#define MAX 100000

int N;
int a[MAX];
int p = 1000000007;
int S;

int main()
{
    scanf("%d", &N);
    S = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        a[i] = a[i] % p;
    }
    for (int i = 0; i < N; i++)
    {
        S = (S + a[i]) % p;
    }
    printf("%d", S);
}
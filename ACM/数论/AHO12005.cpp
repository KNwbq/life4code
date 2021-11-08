#include<stdio.h>

int main()
{
    long long n, ans = 0;
    scanf("%lld", &n);
    for (int i = 1, j; i <= n; i = j + 1)
    {
        j = n / (n / i);
        ans += (n / i) * (j - i + 1);
    }
    printf("%lld", ans);
    return 0;
}
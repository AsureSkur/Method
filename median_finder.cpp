#include <cmath>  
#include <queue>  
#include <vector>  
#include<list>  
#include <cstdio>  
#include <string>  
#include <cstring>  
#include <iomanip>  
#include <iostream>  
#include <algorithm>  
using namespace std;

long long int a[2000005];

int cmp(const void* a, const void* b)
{
    long long int re = *(long long int*)a - *(long long int*)b;
    if (re > 0)
    {
        return 1;
    }
    else if (re == 0)
    {
        return 0;
    }
    else return -1;
}

long long int Partion(long long int p, long long int r, long long int x)
{
    long long int i = p - 1;
    long long int j = r + 1;
    while (1)
    {
        while (a[++i] < x && i < r);
        while (a[--j] > x);
        if (i >= j)break;
        swap(a[i], a[j]);

    }
    return j - 1;
}
long long int select(long long int p, long long int r, long long int k)
{
    if (r - p < 75)
    {
        qsort(&a[p], r - p + 1, sizeof(long long int), cmp);
        return a[p + k - 1];
    }
    long long int i, j, p1, p2, temp;
    for (i = 0; i < (r - p - 4) / 5; i++)
    {
        p1 = p + 5 * i;
        p2 = p1 + 4;
        qsort(&a[p1], p2 - p1 + 1, sizeof(long long int), cmp);
        temp = a[p + i];
        a[p + i] = a[p1 + 2];
        a[p1 + 2] = temp;
    }
    long long int x = select(p, p + (r - p - 4) / 5, (r - p - 4) / 10);
    i = Partion(p, r, x);
    j = i - p + 1;
    if (k <= j) return select(p, i, k);
    else return select(i + 1, r, k - j);
}

int main()
{
    long long int n = 0;
    long long int x;
    while (scanf("%lld,%lld ", &x, &a[n]) != EOF)
    {
        n++;
    }
    if (n % 2 == 1)
    {
        x = select(0, n - 1, (n / 2) + 1);
    }
    else
    {
        x = select(0, n - 1, (n / 2) - 1);
    }
    printf("%lld\n", x);
}
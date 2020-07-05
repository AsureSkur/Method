#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<cassert>
#include<cstddef>

using namespace std;

long long int Cost[10010];
long long int Y[10010];

bool Costcmp(long long int i,long long int j,long long int s);
long long int Costsum(long long int n,long long int s);

int main()
{
	long long int num, store;
	long long int i;
	long long int res;
	scanf("%lld %lld", &num, &store);
	getchar();
	for (i = 0; i < num; i++)
	{
		scanf("%lld %lld", &Cost[i], &Y[i]);
		getchar();
	}
	res = Costsum(num, store);
	printf("%lld\n", res);
}
long long int Costsum(long long int n, long long int s)
{
	long long int res = 0;
	long long int last = 0;
	long long int i;
	for (i = 0; i < n; i++)
	{
		if (Costcmp(last, i, s) == 1)
		{
			res += (Cost[last]+ (i - last) * s) * Y[i];
		}
		else
		{
			res += Cost[i] * Y[i];
			last = i;
		}
	}
	return res;
}
bool Costcmp(long long int i, long long int j, long long int s)
{
	if (Cost[i] + s * (j - i) < Cost[j])
	{
		return 1;
	}
	else return 0;
}
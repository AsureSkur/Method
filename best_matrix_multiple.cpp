#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<cassert>
#include<cstddef>

using namespace std;

long long int m[110][110];	//最优值dp数组
long long int s[110][110];	//最优分段点
long long int q[110];

long long int calculate(long long int num);
void track_back(long long int i, long long int j);

int main()
{
	long long int n, i;
	long long int res;
	scanf("%lld", &n);
	getchar();
	for (i = 1; i <= n + 1; i++)
	{
		scanf("%lld", &q[i]);
		getchar();
	}
	printf("%lld\n",calculate(n));
	if (n == 1)
	{
		printf("(A1)\n");
	}
	else
	{
		track_back(1, n);
		printf("\n");

	}
}
long long int calculate(long long int num)
{
	long long int i, j, k, d;
	for (i = 1; i <= num; i++)
	{
		m[i][i] = 0;
	}
	for (i = 1; i <= num - 1; i++)		//未考虑num=1，2
	{
		m[i][i + 1] = q[i] * q[i + 1] * q[i + 2];
	}
	for (d = 2; d < num; d++)
	{
		for (i = 1; i <= num - d; i++)
		{
			j = i + d;
			m[i][j] = 1000000000000000000;
			for (k = i; k < j; k++)
			{
				if (m[i][j] > m[i][k] + m[k + 1][j] + q[i] * q[k + 1] * q[j + 1])
				{
					m[i][j] = m[i][k] + m[k + 1][j] + q[i] * q[k + 1] * q[j + 1];
					s[i][j] = k;
				}
			}
		}
	}
	return m[1][num];
}

void track_back(long long int i, long long int j)
{
	if (i == j)
	{
		printf("A%lld", i);

	}
	else if (i == j - 1)
	{
		printf("(A%lldA%lld)", i, j);
	}
	else
	{
		printf("(");
		track_back(i, s[i][j]);
		track_back(s[i][j] + 1, j);
		printf(")");
	}
}
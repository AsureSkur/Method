#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<cassert>
#include<cstddef>

using namespace std;

long long int up[21][21];
long long int down[21][21];

long long int* arrfind(long long int, long long int);

int main()
{
	long long int k, n, c;
	int i, j, m;

	up[1][1] = 1;
	down[1][1] = 1;

	for (i = 2; i <= 20; i++)
	{
		for (j = 1; j <= i; j++)
		{
			for (m = j; m < i; m++)
			{
				up[i][j] += down[i - 1][m];
			}
			for (m = 1; m < j; m++)
			{
				down[i][j] += up[i - 1][m];
			}
		}
	}
	scanf("%lld", &k);
	getchar();

	for (i = 0; i < k; i++)
	{
		scanf("%lld %lld", &n, &c);
		getchar();

		arrfind(n, c);

	}
}
long long int* arrfind(long long int n, long long int c)
{
	long long int ans[21];
	long long int vis[21];
	memset(ans, 0, sizeof(ans));
	memset(vis, 0, sizeof(vis));
	long long int i, j;
	long long int temp = 0;
	long long int count;
	for (i = n; i > 0; i--)
	{
		count = 0;
		for (j = 1; j < n; j++)
		{
			if (vis[j] == 0)
			{
				count++;
				if (i == n)
				{
					temp += up[i][j] + down[i][j];
				}
				else if(j > ans[n-i-1])
				{
					if (i == n - 1 || ans[n - i - 2] > ans[n - i - 1])
					{
						temp += down[i][count];
					}
				}
				else if(j < ans[n - i - 1])
				{
					if (i == n - 1 || ans[n - i - 2] < ans[n - i - 1])
					{
						temp += up[i][count];
					}
				}

				if (temp >= c)
				{
					temp = 0;
					break;
				}
				else
				{
					c -= temp;
					temp = 0;
				}

			}
		}
		vis[j] = 1;
		ans[n - i] = j;

	}
	for (j = 0; j < n; j++)
	{
		if (j != 0)
		{
			printf(" ");
		}
		printf("%lld", ans[j]);
	}
	printf("\n");
	return ans;
}



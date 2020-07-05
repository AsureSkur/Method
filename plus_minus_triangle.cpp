#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

void backtrack(int t, int n, int& ans);

int triangle[30][30];

int cnt = 0;

int main()
{
	int n, sum = 0;

	while (scanf("%d", &n) != EOF)
	{
		sum = 0;
		cnt=0;
		if (n * (n + 1) / 2 % 2 == 1)
		{
			sum = 0;
		}
		else
		{
			int temp = sizeof(triangle);
			memset(triangle, 0, sizeof(triangle));

			backtrack(0, n, sum);

		}

		printf("%d\n", sum);
	}

}

void backtrack(int t, int n,int& ans)
{
	int sum = 0;
	if (t >= n)
	{
		ans++;
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		triangle[0][t] = i;
		cnt += i;
		int half = n * (n + 1) / 4;
		for (int j = 1; j <= t; j++)
		{
			triangle[j][t - j] = triangle[j - 1][t - j] ^ triangle[j - 1][t - j + 1];
			cnt += triangle[j][t - j];
		}
		if (cnt <= half && (t + 2) * (t + 1) / 2 - cnt <= half)
		{
			backtrack(t + 1, n, ans);
		}
		
		for (int j = 0; j <= t; j++)
		{
			cnt -= triangle[j][t - j];
		}
	}
	return;
}


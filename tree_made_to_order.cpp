#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<cstdlib>

using namespace std;

long long int catalan[30];
long long int sum[30];

long long int cal_catalan(int n)
{
	long long int res = 1;
	if (n == 0 || n == 1)
	{
		return res;
	}
	else
	{
		res = catalan[n - 1] * (4 * (long long int)n - 2) / ((long long int)n + 1);
		return res;
	}
}

void sum_catalan()
{
	sum[0] = 0;
	for (int i = 1; i < 30; i++)
	{
		sum[i] = sum[i - 1] + catalan[i];
	}
}

void create_tree(int node, long long int order);
int find_node(long long int num);

int main()
{
	for (int i = 0; i <= 29; i++)
	{
		catalan[i] = cal_catalan(i);
	}
	sum_catalan();
	long long int n;
	while (scanf("%lld", &n) != EOF && n)
	{
		int m = find_node(n);
		create_tree(m, n - sum[m - 1]);
		printf("\n");
	}
	return 0;
}

int find_node(long long int order)
{
	for (int i = 1; i < 30; i++)
	{
		if (sum[i] >= order)
		{
			return i;
		}
	}
	return -1;
}

int find_left(int node, long long int order)
{
	long long int temp = 0;
	for (int i = 0; i < node; i++)
	{
		temp += catalan[i] * catalan[node - i - 1];
		if (temp >= order)
		{
			return i;
		}
	}
}

void create_tree(int node, long long int order)
{
	int left = find_left(node, order);
	int right = node - 1 - left;
	for (int i = 0; i < left; i++)
	{
		order -= catalan[i] * catalan[node - 1 - i];
	}
	if (left)
	{
		printf("(");
		create_tree(left, (order + catalan[right] - 1) / catalan[right]);
		printf(")");
	}
	printf("X");
	if (right)
	{
		printf("(");
		create_tree(right, (order - 1) % catalan[right] + 1);
		printf(")");
	}
}
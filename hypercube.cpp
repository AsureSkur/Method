#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;

class Point
{
public:
	vector<int>line;
	int inTree;
	Point()
	{
		inTree = 0;
	}
	int& operator[](int i)
	{
		return line[i];
	}
	friend int check_path(int i, int j);
};

vector<Point>graph;
int check_path(int i, int j);
int quick_pow(int);

int main()
{
	int temp;
	int sum = 0;
	int n;
	scanf("%d", &n);
	int total = quick_pow(n);
	for (int i = 0; i < total ; i++)
	{
		graph.push_back(Point());
		for (int j = 0; j < total; j++)
		{
			graph[i].line.push_back(0);
		}
	}
	for (int i = 0; i < total; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (check_path(i, j) == 1)
			{
				graph[i][j] = 1;
				graph[j][i] = 1;
			}
		}
	}
	vector<int>arr;
	for (int i = 0; i < total; i++)
	{
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	int x, y;
	for (int i = 0; i < total; i++)
	{
		x = arr[i];
		for (int j = 0; j < total; j++)
		{
			if (j != 0)
			{
				printf(" ");
			}
			y = arr[j];
			printf("%d", graph[x][y]);
		}
		printf("\n");
	}
}
int quick_pow(int times)
{
	int x = 2;
	int res = 1;
	while (times)
	{
		if (times & 1)
		{
			res = x * res;
		}
		x = x * x;
		times >>= 1;
	}
	return res;
}

int check_path(int i, int j)
{
	int temp = i ^ j;
	int cnt = 0;
	while (temp)
	{
		cnt += temp & 1;
		temp >>= 1;
	}
	if (cnt == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
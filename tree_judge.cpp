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
	friend void visit_tree(int node);
};

vector<Point>graph;
void visit_tree(int node);
int main()
{
	int temp;
	int sum = 0;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		graph.push_back(Point());
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &temp);
			graph[i].line.push_back(temp);
			sum += temp;
		}
	}
	if (sum == 2 * n - 2)
	{
		for (int i = 0; i < n; i++)
		{
			if (graph[i][i] == 1)
			{
				printf("no\n");
				return 0;
			}
		}
		visit_tree(0);
		for (int i = 0; i < n; i++)
		{
			if (graph[i].inTree == 0)
			{
				printf("no\n");
				return 0;
			}
		}
		printf("yes\n");
	}
	else
	{
		printf("no\n");
		return 0;
	}
	
}
void visit_tree(int node)
{
	graph[node].inTree = 1;
	for (int i = 0; i < graph[node].line.size(); i++)
	{
		if (graph[i].inTree == 0 && graph[node][i] == 1)
		{
			visit_tree(i);
		}
	}
	return;
}
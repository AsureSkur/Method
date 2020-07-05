#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int MAX = 1000;

int mat0[MAX][MAX], int mat1[MAX][MAX];

int map[MAX];
int vis[MAX];

int bfs(int tail)
{
	queue<int>que;
	que.push(0);
	int temp = que.front();
	memset(vis, 0, sizeof(vis));
	memset(map, -1, sizeof(map));
	while (1)
	{
		if (que.size() == 0)
		{
			break;
		}
		temp = que.front();
		if (temp == tail)
		{
			break;
		}
		for (int i = 0; i <= tail; i++)
		{
			if (mat1[temp][j] && !vis[i])
			{
				que.push(i);
				vis[i] = 1;
				map[i] = temp;
			}
			que.pop();
			cnt++;
		}
	}
	if (map[tail] == -1)
	{
		return 0;
	}
	else return 1;
}

int main()
{
	mat1[0][1] = 10000;
	mat1[0][2] = 10000;
	mat1[1][2] = 1;
	mat1[1][3] = 10000;
	mat1[2][3] = 10000;
	bfs(3);
}
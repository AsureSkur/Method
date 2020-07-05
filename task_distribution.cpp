/* each worker is needed to be distributed a task, calculate the min cost needed.

4
3 8 4 12
9 12 13 5
8 7 9 3
12 7 6 8

21
*/


#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

const int maxn = 100 + 5, INF = 0x3f3f3f3f;

int n; //number of workers

int weight[maxn][maxn];	//the time which the i-th worker do the j-th task needed.

int kmw[maxn][maxn]; 
//KM weight, KM theory is used to calculate the max perfect matching path, so we needed to change origin value into minus

int mat[maxn], lx[maxn], ly[maxn], slack[maxn];
//mat: matching signal;lx,ly: point value; slack: each time lx,ly should be changed. 

bool S[maxn], T[maxn];
//record the point in x, y which has been placed in the path

bool dfs(int u)
{
	S[u] = 1;
	for (int v = 0; v < n; v++)
	{
		if (T[v]) continue;
		int t = lx[u] + ly[v] - kmw[u][v];
		if (!t)
		{
			T[v] = 1;
			if (mat[v] == -1 || dfs(mat[v]))
			{
				mat[v] = u;
				return 1;
			}
		}
		else
		{
			slack[v] = slack[v] < t ? slack[v] : t;
		}
	}
	return 0;
}

void KM()
{
	for (int i = 0; i < n; i++)
	{
		lx[i] = -INF;
		ly[i] = 0;
		mat[i] = -1;
		for (int j = 0; j < n; j++)
		{
			lx[i] = max(lx[i], kmw[i][j]);	//init lx[i] as the min weight
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			slack[j] = INF;		//init slack
		}
		while (1)
		{
			for (int j = 0; j < n; j++)
			{
				S[j] = 0;
				T[j] = 0;
			}
			if (dfs(i))
			{
				break;
			}
			else
			{
				int d = INF;
				for (int k = 0; k < n; k++)
				{
					if (!T[k])
					{
						d = d < slack[k] ? d : slack[k];
					}
				}
				for (int k = 0; k < n; k++)
				{
					if (S[k])
					{
						lx[k] -= d;
					}
					if (T[k])
					{
						ly[k] += d;
					}
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &weight[i][j]);
			kmw[i][j] = -weight[i][j];
			getchar();
		}
	}

	KM();

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += weight[mat[i]][i];
	}

	printf("%d\n", sum);

}

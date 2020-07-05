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
	int match;
	int check;
	int height;
	char sex;
	string music_style;
	string game_liked;
	vector<int>link;
	Point(int h, char s, string m, string g) :height(h), sex(s), music_style(m), game_liked(g)
	{
		match = -1;
		check = 0;
	}
	int& operator[](int i)
	{
		if (i < link.size())
		{
			return link[i];
		}
		return link[link.size() - 1];
	}
	void push(int i)
	{
		link.push_back(i);
	}
	friend bool check_relation(int i, int j);
	friend int hungarian();
	friend bool dfs(int u);
};
vector<Point>pupil;

bool check_relation(int i,int j);
int hungarian();
bool dfs(int u);

int main()
{
	int t, n;
	int h_t;
	char c_t;
	int temp;
	int ans;
	int sum;
	string ms_t, g_t;
	scanf("%d", &t);
	getchar();
	for (int i = 0; i < t; i++)
	{
		sum = 0;
		pupil.clear();
		temp=scanf("%d", &n);
		temp=getchar();
		for (int j = 0; j < n; j++)
		{
			temp=scanf("%d %c",&h_t,&c_t);
			temp=getchar();
			cin >> ms_t >> g_t;
			pupil.push_back(Point(h_t, c_t, ms_t, g_t));
			for (int k = 0; k < j; k++)
			{
				if (check_relation(k, j))
				{
					pupil[k].push(j);
					pupil[j].push(k);
				}
			}
		}
		ans = n - hungarian();
		printf("%d\n", ans);

	}
}
bool check_relation(int i, int j)
{
	if (pupil[i].sex == pupil[j].sex)
	{
		return false;
	}
	else
	{
		if (abs(pupil[i].height - pupil[j].height) > 40)
		{
			return false;
		}
		else
		{
			if (pupil[i].music_style != pupil[j].music_style)
			{
				return false;
			}
			else
			{
				if (pupil[i].game_liked == pupil[j].game_liked)
				{
					return false;
				}
				else return true;
			}
		}
	}
}

int hungarian()
{
	int ans = 0;
	for (int i = 0; i < pupil.size(); i++)
	{
		if (pupil[i].sex == 'M')
		{
			for (int j = 0; j < pupil.size(); j++)
			{
				pupil[j].check = 0;
			}
			if (dfs(i))
			{
				ans++;
			}
		}
	}
	return ans;
}

bool dfs(int u)
{
	for (int i = 0; i < pupil[u].link.size(); i++)
	{
		int v = pupil[u][i];
		if (!pupil[v].check)
		{
			pupil[v].check = true;
			if (pupil[v].match == -1 || dfs(pupil[v].match))
			{
				pupil[v].match = u;
				return true;
			}
		}
	}
	return false;
}
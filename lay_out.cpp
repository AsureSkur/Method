#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<list>

using namespace std;

class Relation
{
public:
	int target;
	int weight;
	Relation(int n, int w)
	{
		target = n;
		weight = w;
	}
};

class Point
{
public:
	int dist;
	int times;
	int flag;	//judge whehter it is in the queue
	vector<Relation>line;
	Point()
	{
		dist = -1;
		times = 0;
		flag = 0;
	}
};

vector<Point>cow;

int spfa(int num);	//graphic visit

int main()
{
	int temp;
	int n, ml, md;
	int i;
	int head, tail;

	Point point;	//init cow array
	temp = scanf("%d %d %d", &n, &ml, &md);
	temp = getchar();
	for (i = 0; i < n; i++)
	{
		cow.push_back(point);
	}

	Relation relation(0, 0);	//init relation in each cow
	for (i = 0; i < ml; i++)
	{
		temp = scanf("%d %d %d", &head, &relation.target, &relation.weight);
		temp = getchar();
		relation.target -= 1;
		cow[head - 1].line.push_back(relation);
	}
	for (i = 0; i < md; i++)
	{
		temp = scanf("%d %d %d", &relation.target, &head, &relation.weight);
		temp = getchar();
		relation.target -= 1;
		relation.weight = -relation.weight;
		cow[head - 1].line.push_back(relation);
	}

	int ans = spfa(n);	//spfa visit each cow and return the shortest path

	printf("%d\n", ans);
}

int spfa(int num)
{
	list<int>path;
	
	path.push_back(0);

	cow[0].dist = 0;
	cow[0].times = 1;
	cow[0].flag = 1;
	while (1)
	{
		if (path.size() == 0)
		{
			break;
		}
		for (int i = 0; i < cow[path.front()].line.size(); i++)
		{
			int t = cow[path.front()].line[i].target;
			int w = cow[path.front()].line[i].weight;
			if (cow[t].dist == -1 || cow[t].dist > cow[path.front()].dist + w)	
			{//cow[t] changed, so push it into queue

				cow[t].dist = cow[path.front()].dist + w;
				if (cow[t].flag == 0)		//push cow[t] into queue
				{
					cow[t].times += 1;
					if (cow[t].times > num)
					{
						return -1;
					}
					cow[t].flag = 1;
					path.push_back(t);
				}
			}
		}
		cow[path.front()].flag = 0;		//pop the front of queue, refresh flag
		path.pop_front();
	}
	if (cow[num - 1].dist == -1)
	{
		return -2;
	}
	else return cow[num - 1].dist;
}
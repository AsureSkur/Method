#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

//calculate 4 num into 24 with +-*/, while each num can be only used once, check the possibility with yes or no

class Ccheck_24
{
public:
	double num_arr[4];
	bool selected[4];
	bool flag;

	Ccheck_24(double* p)
	{
		flag = 0;
		for (int i = 0; i < 4; i++)
		{
			num_arr[i] = *(p + i);
			selected[i] = 0;
		}
	}
	bool check_24();

	void dfs(double last, int depth);
};


int main()
{
	double num_arr[4];
	Ccheck_24* p;
	while (scanf("%lf %lf %lf %lf",&num_arr[0],&num_arr[1],&num_arr[2],&num_arr[3]) != EOF)
	{
		p = new Ccheck_24(num_arr);
		if (p->check_24())
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
		delete p;
	}
}

bool Ccheck_24::check_24()
{
	int temp = sizeof(selected);
	memset(selected, 0, sizeof(selected));

	for (int i = 0; i < 4; i++)
	{
		selected[i] = 1;
		dfs(num_arr[i], 2);
		selected[i] = 0;

	}
	if (flag)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Ccheck_24::dfs(double last, int depth)
{
	if (flag)
	{
		return;
	}
	if (depth == 5)
	{
		if (fabs(last - 24) < 0.00001)
		{
			flag = 1;
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (selected[i] == 1)
		{
			continue;
		}
		selected[i] = 1;
		dfs(last + num_arr[i], depth + 1);
		dfs(last - num_arr[i], depth + 1);
		dfs(num_arr[i] - last, depth + 1);
		dfs(last * num_arr[i], depth + 1);
		dfs(last / num_arr[i], depth + 1);
		if (last)
		{
			dfs(num_arr[i] / last, depth + 1);
		}
		selected[i] = 0;
	}

	if (depth == 3)
	{
		double t1 = 0, t2 = 0;
		for (int i = 0; i < 4; i++)
		{
			if (!selected[i])
			{
				if (!t1)
				{
					t1 = num_arr[i];
				}
				else
				{
					t2 = num_arr[i];
					break;
				}
			}
		}

		dfs(last + (t1 * t2), depth + 2);
		dfs(last + (t1 / t2), depth + 2);
		dfs(last + (t2 / t1), depth + 2);

		dfs(last - (t1 * t2), depth + 2);
		dfs(last - (t1 / t2), depth + 2);
		dfs(last - (t2 / t1), depth + 2);
		dfs(-last + (t1 * t2), depth + 2);
		dfs(-last + (t1 / t2), depth + 2);
		dfs(-last + (t2 / t1), depth + 2);

		dfs(last * (t1 + t2), depth + 2);
		dfs(last * (t1 - t2), depth + 2);
		dfs(last * (t2 - t1), depth + 2);

		dfs(last / (t1 + t2), depth + 2);

		if (t1 != t2)
		{
			dfs(last / (t1 - t2), depth + 2);
			dfs(last / (t2 - t1), depth + 2);
		}

		if (last)
		{
			dfs((t1 + t2) / last, depth + 2);
			dfs((t1 - t2) / last, depth + 2);
			dfs((t2 - t1) / last, depth + 2);
		}

	}

}

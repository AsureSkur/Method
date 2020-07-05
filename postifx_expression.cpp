#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<cstdlib>
#include<stack>;
using namespace std;

stack<int>opnr;

int calculator(char op, int& flag);

int main()
{
	char op;
	int res = 0;
	int flag = 1;
	while (scanf("%c", &op) != EOF)
	{
		if (op == '\n')
		{
			break;
		}
		if (op >= '0' && op <= '9')
		{
			opnr.push(op - '0');
		}
		else
		{
			res = calculator(op, flag);
			if (flag == -1)
			{
				printf("ERROR!\n");
				return 0;
			}
			else if (flag == -2)
			{
				printf("DIV0!\n");
				return 0;
			}
			else
			{
				opnr.push(res);
			}
		}
	}
	if (opnr.size() == 1)
	{
		printf("%d\n", opnr.top());
	}
	else
	{
		printf("ERROR!\n");
	}
}

int calculator(char op,int& flag)
{
	int num1, num2;
	if (opnr.size() < 2)
	{
		flag = -1;
		return 0;
	}
	if (op == '+')
	{
		num1 = opnr.top();
		opnr.pop();
		num2 = opnr.top();
		opnr.pop();
		return num1 + num2;
	}
	else if (op == '-')
	{
		num1 = opnr.top();
		opnr.pop();
		num2 = opnr.top();
		opnr.pop();
		return num2 - num1;
	}
	else if (op == '*')
	{
		num1 = opnr.top();
		opnr.pop();
		num2 = opnr.top();
		opnr.pop();
		return num1 * num2;
	}
	else if (op == '/')
	{
		num1 = opnr.top();
		opnr.pop();
		num2 = opnr.top();
		opnr.pop();
		if (num1 == 0)
		{
			flag = -2;
			return 0;
		}
		return num2 / num1;
	}
}
#include<math.h>     
#include<stdlib.h>     
#include<locale.h>  
#include<stdio.h>  
#include<string.h>  
  
static char str1[210000], str2[210000];  
  
static long long int a[20000], b[20000], c[40010];  
  
const long long int judge = -2000000;  
  
void operate(long long int*, long long int*, long long int*, char);  
  
long long int* short_down(char*, long long int*);  
  
int main()  
{  
    char op;  
    long long int* p1, * p2;  
    while (1)  
    {  
        if (scanf("%s %s", str1,str2) == EOF)  
        {  
            break;  
        }  
        getchar();  
  
  
  
        p1 = short_down(str1, a);  
  
        p2 = short_down(str2, b);  
  
        operate(p1, p2, c, '*');  
  
    }  
}  
  
long long int* short_down(char* s, long long int* desti)  
{  
    char* p;  
    long long int* numb;  
    int count = 0;  
    p = s;  
    numb = desti;  
    *numb = 0;  
    while (1)  
    {  
        if (*p == '\0')  
        {  
            break;  
        }  
        p++;  
    }  
    p--;  
    while (1)  
    {  
        if (p < s)  
        {  
            *(numb + 1) = judge;  
            break;  
        }  
        if (count == 6)  
        {  
            numb++;  
            *numb = 0;  
            count = 0;  
        }  
        else  
        {  
            *numb = *numb + (*p - '0') * pow(10, count);  
            count++;  
            p--;  
        }  
    }  
    return desti;  
  
}  
  
void operate(long long int* num1, long long int* num2, long long int* desti, char oper)  
{  
    const long long int mod = 1000000;  
    long long int* num3;  
    long long int* p1, * p2, * p3;  
    long long int temp;  
    long long int i = 0;  
    long long int exad = 0;  
    int flag = 0, out = 0;  
    p1 = num1;  
    p2 = num2;  
    p3 = desti;  
    num3 = desti;  
    if (oper == '+')  
    {  
        while (1)  
        {  
            if (*num1 == judge && *num2 == judge)  
            {  
                if (exad != 0)  
                {  
                    *num3 = exad % mod;  
                    exad = exad / mod;  
                    num3++;  
                }  
                *num3 = judge;  
                break;  
            }  
            else if (*num1 == judge)  
            {  
                *num3 = (*num2 + exad) % mod;  
                exad = (*num2 + exad) / mod;  
                num3++;  
                num2++;  
            }  
            else if (*num2 == judge)  
            {  
                *num3 = (*num1 + exad) % mod;  
                exad = (*num1 + exad) / mod;  
                num3++;  
                num1++;  
            }  
            else if (*num1 != judge && *num2 != judge)  
            {  
                *num3 = (*num1 + *num2 + exad) % mod;  
                exad = (*num1 + *num2 + exad) / mod;  
                num3++;  
                num2++;  
                num1++;  
            }  
        }  
        while (1)  
        {  
            if (num3 < desti)  
            {  
                break;  
            }  
            if (*num3 != judge)  
            {  
  
                if (*(num3 + 1) == judge || out == 0)  
                {  
                    if (*num3 != 0)  
                    {  
                        printf("%lld", *num3);  
                        out = 1;  
                    }  
                    else if (num3 == desti)  
                    {  
                        printf("%lld", *num3);  
                    }  
  
                }  
                else if (*(num3 + 1) != judge)  
                {  
                    printf("%06lld", *num3);  
                }  
  
            }  
            num3--;  
        }  
        printf("\n");  
    }  
    else if (oper == '-')  
    {  
        while (1)  
        {  
            if (flag == 2)  
            {  
                break;  
            }  
            else if (flag == 1)  
            {  
                memset(desti, 0, sizeof(c));  
                num3 = desti;  
                while (1)  
                {  
                    if (*p1 == judge && *p2 == judge)  
                    {  
                        if (exad == -1)  
                        {  
                            *num3 = 1;  
                            flag = 1;  
                            exad = 0;  
                            num3++;  
                        }  
                        *num3 = judge;  
                        break;  
                    }  
                    else if (*p1 == judge)  
                    {  
                        if (*p2 + exad < 0)  
                        {  
                            *num3 = (*p2 + mod + exad) % mod;  
                            exad = -1;  
                        }  
                        else  
                        {  
                            *num3 = (*p2 + exad) % mod;  
                            exad = 0;  
                        }  
                        num3++;  
                        p2++;  
                    }  
                    else if (*p2 != judge && *p1 != judge)  
                    {  
                        if (*p2 + exad >= *p1)  
                        {  
                            *num3 = (*p2 + exad - *p1) % mod;  
                            exad = 0;  
                        }  
                        else if (*p2 + exad < *p1 && *(p2 + 1) != judge)  
                        {  
                            *num3 = (*p2 + mod - *p1 + exad) % mod;  
                            exad = -1;  
                        }  
  
                        num3++;  
                        p1++;  
                        p2++;  
                    }  
                }  
                flag = 2;  
                break;  
            }  
            else if (*num1 == judge && *num2 == judge)  
            {  
                if (exad == -1)  
                {  
                    *num3 = 1;  
                    flag = 1;  
                    exad = 0;  
                    num3++;  
                }  
                *num3 = judge;  
                break;  
            }  
            else if (*num1 == judge)  
            {  
                flag = 1;  
            }  
            else if (*num2 == judge)  
            {  
                if (*num1 + exad < 0)  
                {  
                    *num3 = (*num1 + mod + exad) % mod;  
                    exad = -1;  
                }  
                else  
                {  
                    *num3 = (*num1 + exad) % mod;  
                    exad = 0;  
                }  
                num3++;  
                num1++;  
            }  
            else if (*num1 != judge && *num2 != judge)  
            {  
                if (*num1 + exad >= *num2)  
                {  
                    *num3 = (*num1 + exad - *num2) % mod;  
                    exad = 0;  
                }  
                else if (*num1 + exad < *num2 && *(num1 + 1) != judge)  
                {  
                    *num3 = (*num1 + mod - *num2 + exad) % mod;  
                    exad = -1;  
                }  
                else if (*num1 + exad < *num2 && *(num1 + 1) == judge)  
                {  
                    *num3 = (*num2 - *num1 - exad) % mod;  
                    exad = -((*num2 - *num1 - exad) / mod);  
                    flag = 1;  
                }  
  
                num3++;  
                num2++;  
                num1++;  
            }  
        }  
        while (1)  
        {  
            if (num3 < desti)  
            {  
                break;  
            }  
            if (flag == 1 || flag == 2)  
            {  
                printf("%c", '-');  
                flag = 0;  
            }  
            if (*num3 != judge)  
            {  
                if (*(num3 + 1) == judge || out == 0)  
                {  
                    if (*num3 != 0)  
                    {  
                        printf("%lld", *num3);  
                        out = 1;  
                    }  
                    else if (num3 == desti)  
                    {  
                        printf("%lld", *num3);  
                    }  
                }  
                else if (*(num3 + 1) != judge)  
                {  
                    printf("%06lld", *num3);  
                }  
  
            }  
            num3--;  
        }  
        printf("\n");  
    }  
    else if (oper == '*')  
    {  
        memset(desti, 0, sizeof(c));  
        while (1)  
        {  
            if (*num2 == judge)  
            {  
                num3 = p3;  
                *num3 = judge;  
                break;  
            }  
            else if (*num1 == judge)  
            {  
                num1 = p1;  
                num2++;  
                i++;  
                p3 = num3;  
                num3 = desti + i;  
            }  
            else if (*num1 != judge)  
            {  
                *num3 = *num3 + (*num1) * (*num2);  
                num1++;  
                num3++;  
            }  
        }  
        exad = 0;  
        num3 = desti;  
        while (1)  
        {  
            if (*num3 == judge)  
            {  
                while (1)  
                {  
                    if (exad == 0) break;  
                    *num3 = exad % mod;  
                    exad = exad / mod;  
                    num3++;  
                    *num3 = judge;  
                }  
                break;  
            }  
            else  
            {  
                temp = *num3;  
                *num3 = (*num3 + exad) % mod;  
                exad = (temp + exad) / mod;  
                num3++;  
            }  
        }  
  
  
        while (1)  
        {  
            if (num3 < desti)  
            {  
                break;  
            }  
            if (*num3 != judge)  
            {  
                if (*(num3 + 1) == judge || out == 0)  
                {  
                    if (*num3 != 0)  
                    {  
                        printf("%lld", *num3);  
                        out = 1;  
                    }  
                    else if (num3 == desti)  
                    {  
                        printf("%lld", *num3);  
                    }  
                }  
                else if (*(num3 + 1) != judge)  
                {  
                    printf("%06lld", *num3);  
                }  
            }  
            num3--;  
        }  
        printf("\n");  
  
    }  
}  
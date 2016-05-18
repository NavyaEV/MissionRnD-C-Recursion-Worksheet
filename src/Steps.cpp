/*

You have N steps to climb .
You can either take one step or two steps at a time .
You need to find the total number of ways you can reach N steps .

Example : For N=4 , You can either reach 4 steps in following ways
->1111
->112
->121
->211
->22
So total number of ways is 5

Input : A Integer denoting N (number of steps )
Output : Return an Integer denoting the number of ways to reach N steps

Example Input : get_steps(5)
Example Output : Returns 8

Note : Test Cases would be small <25.

*/
#include "stdafx.h"
int count_steps(int, int);
int fact(int);

int get_steps(int s)
{
	if (s % 2 == 1)
		return count_steps(s / 2, 1);
	else
		return count_steps(s / 2, 0);
}
int count_steps(int t, int o)
{
	if (t == 0)
		return 1;
	else
		return (fact(t + o) / (fact(t)*fact(o))) + count_steps(t - 1, o + 2);
}
int fact(int n)
{
	if ((n == 0) || (n == 1))
		return 1;
	else
		return n*fact(n - 1);
}
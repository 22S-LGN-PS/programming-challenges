#include <bits/stdc++.h>
using namespace std;

unsigned int GetReversedNum(unsigned int num)
{
	unsigned int reversed_num = 0;
	while (num > 0)
	{
		reversed_num = reversed_num * 10 + num % 10;
		num /= 10;
	}
	return reversed_num;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		unsigned int p;
		cin >> p;
		int step = 0;
		while (true)
		{
			p += GetReversedNum(p);
			step++;
			if (p == GetReversedNum(p))
				break;
		}
		cout << step << " " << p << endl;
	}
	return 0;
}
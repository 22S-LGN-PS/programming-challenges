#include "bits/stdc++.h"
using namespace std;
#define M 1000

struct Shoe
{
	int i;
	int t;
	int s;
};

void MakeShoes()
{
	Shoe shoes[M + 1];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		shoes[i].i = i + 1;
		cin >> shoes[i].t >> shoes[i].s;
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; i + j < N; j++)
		{
			// j before j+1
			int fine1 = shoes[j].t * shoes[j + 1].s;

			// j+1 before j
			int fine2 = shoes[j + 1].t * shoes[j].s;

			// case for swap
			if (fine2 < fine1)
			{
				swap(shoes[j], shoes[j + 1]);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << shoes[i].i << " ";
	}
	cout << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		MakeShoes();
	}
	return 0;
}
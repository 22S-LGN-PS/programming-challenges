#include <bits/stdc++.h>
using namespace std;
#define M 200
string turtles[M + 1];
map<string, int> turtle_map;

void ShellSort()
{
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string status[M + 1];
	for (int i = 0; i < n; i++)
		getline(cin, status[i]);

	for (int i = 0; i < n; i++)
	{
		getline(cin, turtles[i]);
		turtle_map[turtles[i]] = i;
	}

	stack<int> S;
	for (int i = 0; i < n; i++)
		S.push(turtle_map[status[i]]);

	int turtles_to_move = n - 1;
	while (!S.empty())
	{
		if (S.top() == turtles_to_move)
			turtles_to_move--;
		S.pop();
	}

	for (int i = turtles_to_move; i >= 0; i--)
		cout << turtles[i] << endl;

	cout << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		ShellSort();
	}
	return 0;
}
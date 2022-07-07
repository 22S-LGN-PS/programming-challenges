#include <bits/stdc++.h>
using namespace std;
map<int, int> collatz;

int ThreeNPlusOne(int n)
{
    if (collatz[n] == 0)
    {
        if (n == 1)
            collatz[n] = 1;
        else if (n % 2)
            collatz[n] = ThreeNPlusOne(n * 3 + 1) + 1;
        else
            collatz[n] = ThreeNPlusOne(n / 2) + 1;
    }
    return collatz[n];
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int len = 0;
        cout << n << " " << m << " ";
        for (int i = min(n, m); i <= max(n, m); i++)
        {
            len = max(len, ThreeNPlusOne(i));
        }
        cout << len << endl;
    }
    return 0;
}
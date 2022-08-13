#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int len = abs(x - y);
        if (len < 2)
            cout << len << endl;
        else
            cout << (len + 1) / 2 + 1 << endl;
    }

    return 0;
}
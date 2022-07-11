// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=30&page=show_problem&problem=979
#include <bits/stdc++.h>
using namespace std;
map<long long, bool> jolly;

bool Jolly(int n)
{
    int flag = true;
    jolly.clear();
    int prev, curr;
    for (int i = 0; i < n; i++)
    {
        prev = curr;
        cin >> curr;
        if (i)
        {
            int gap = abs(prev - curr);
            if (gap > 0 && gap < n)
            {
                if (jolly[gap])
                    flag = false;
                jolly[gap] = true;
            }
            else
                flag = false;
        }
    }
    return flag;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << (Jolly(n) ? "Jolly" : "Not Jolly") << endl;
    }
    return 0;
}
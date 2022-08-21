// UVa ID: 861

#include <bits/stdc++.h>

#define MAX_BIS 64

using namespace std;

int n, k, num = 0;
// num: how many bishops on the board until now

int pos[MAX_BIS + 1][2]; // record pos of bishops

bool possible(int x, int y)
{
    for (int i = 0; i < num; i++)
    {
        if (abs(pos[num][0] - x) == abs(pos[num][1] - y))
        {
            return false;
        }
    }
    return true;
}

long long bishop(int x, int y)
{
    if (x == n)
        return 0;
    if (num == k)
        return 1;
    long long ans = 0;
    if (possible(x, y))
    {
        pos[num][0] = x;
        pos[num][1] = y;
        num++;
        ans = (y + 1 == n) ? bishop(x + 1, 0) : bishop(x, y + 1);
        num--;
    }
    ans += (y + 1 == n) ? bishop(x + 1, 0) : bishop(x, y + 1);
    return ans;
}

int main()
{
    while (cin >> n >> k)
    {
        if (n == 0 && k == 0)
            break;
        printf("%lld\n", bishop(0, 0));
    }
    return 0;
}
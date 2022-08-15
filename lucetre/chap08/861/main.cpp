#include <bits/stdc++.h>
#define N 8
using namespace std;

bool sub_diagonal[2 * N];
bool add_diagonal[2 * N];
int n, k;
long long res;

void FindAvailableBishopPositions(int pos, int lev)
{
    if (lev == k)
    {
        res++;
        return;
    }
    if (pos < n * n)
    {
        int row = pos / n;
        int col = pos % n;
        if (!sub_diagonal[row - col + (n - 1)] && !add_diagonal[row + col])
        {
            sub_diagonal[row - col + (n - 1)] = add_diagonal[row + col] = true;
            FindAvailableBishopPositions(pos + 1, lev + 1);
            sub_diagonal[row - col + (n - 1)] = add_diagonal[row + col] = false;
        }
        FindAvailableBishopPositions(pos + 1, lev);
    }
}

int main()
{
    while (cin >> n >> k && (n != 0 || k != 0))
    {
        res = 0;
        for (int i = 0; i < 2 * N; i++)
            sub_diagonal[i] = add_diagonal[i] = 0;
        FindAvailableBishopPositions(0, 0);
        cout << res << endl;
    }
    return 0;
}
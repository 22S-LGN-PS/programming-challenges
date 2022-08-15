#include <bits/stdc++.h>
#define N 8
using namespace std;

bool sub_diagonal[2 * N];
bool add_diagonal[2 * N];
int n, k;
long long res;
vector<vector<int>> bishops = {
    {},
    {1, 1, 0},
    {1, 4, 4, 0, 0},
    {1, 9, 26, 26, 8, 0, 0},
    {1, 16, 92, 232, 260, 112, 16, 0, 0},
    {1, 25, 240, 1124, 2728, 3368, 1960, 440, 32, 0, 0},
    {1, 36, 520, 3896, 16428, 39680, 53744, 38368, 12944, 1600, 64, 0, 0},
    {1, 49, 994, 10894, 70792, 282248, 692320, 1022320, 867328, 389312, 81184, 5792, 128, 0, 0},
    {1, 64, 1736, 26192, 242856, 1444928, 5599888, 14082528, 22522960, 22057472, 12448832, 3672448, 489536, 20224, 256, 0, 0}};

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
        if (k > 2 * n)
        {
            cout << 0 << endl;
            continue;
        }
        else
        {
            // res = 0;
            // for (int i = 0; i < 2 * n; i++)
            //     sub_diagonal[i] = add_diagonal[i] = 0;
            // FindAvailableBishopPositions(0, 0);
            // cout << res << endl;

            cout << bishops[n][k] << endl;
        }
    }
    return 0;
}
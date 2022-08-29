#include <bits/stdc++.h>
using namespace std;
#define N 300
#define D 150
long long dy[N + 1][D + 1];

int main()
{
    dy[0][0] = 1;
    for (int n = 2; n <= N; n++)
    {
        for (int d = 1; d <= min(n / 2, D); d++)
        {
            dy[n][d] = dy[n - 2][d - 1];
            for (int i = 2; i < n; i++)
            {
                for (int j = 1; j < d; j++)
                {
                    dy[n][d] += dy[n - i][j] * dy[i - 2][d - 1];
                    dy[n][d] += dy[n - i][d] * dy[i - 2][j - 1];
                }
                dy[n][d] += dy[n - i][d] * dy[i - 2][d - 1];
            }
        }
    }

    int n, d;
    while (cin >> n >> d)
        cout << dy[n][d] << endl;

    return 0;
}
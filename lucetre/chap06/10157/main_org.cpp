#include <bits/stdc++.h>
using namespace std;
#define N 300
#define D 150
long long multi[N + 1][D + 1];
long long single[N + 1][D + 1];

int main()
{
    multi[0][0] = single[0][0] = 1;
    for (int n = 2; n <= N; n++)
    {
        for (int d = 1; d <= min(n / 2, D); d++)
        {
            multi[n][d] = single[n][d] = multi[n - 2][d - 1];
            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < d; j++)
                    multi[n][d] += multi[n - i][j] * single[i][d];
                for (int j = 1; j < d; j++)
                    multi[n][d] += multi[n - i][d] * single[i][j];
                multi[n][d] += multi[n - i][d] * single[i][d];
            }
        }
    }

    // for (int n = 2; n <= 10; n++)
    // {
    //     printf("%3d: ", n);
    //     for (int d = 1; d <= min(n / 2, D); d++)
    //         printf("%3lld(%lld)", multi[n][d], single[n][d]);
    //     cout << endl;
    // }

    int n, d;
    while (cin >> n >> d)
        cout << multi[n][d] << endl;

    return 0;
}
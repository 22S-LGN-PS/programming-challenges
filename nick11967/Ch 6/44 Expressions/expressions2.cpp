// UVa ID: 10157
/*
#include <bits/stdc++.h>

using namespace std;

int n, d;
long long result;
long long c[151][151];
long long e[151];
long long f[151][151];

void solve()
{
    int i, j, k;

    e[0] = 1;
    e[1] = 1;
    e[2] = 2;
    for (i = 3; i <= 150; i++)
    {
        e[i] = 0;
        for (j = 1; j <= i; j++)
        {
            e[i] += e[j - 1] * e[i - j];
        }
    }
    for (i = 0; i <= 150; i++)
    {
        for (j = 0; j <= 150; j++)
        {
            if (i == 0 && j == 0)
                f[i][j] = 1;
            else if (i <= j)
                f[i][j] = e[i];
            else if (j == 1)
                f[i][j] = 1;
            else if (j == 0)
                f[i][j] = 0;
            else
            {
                f[i][j] = 0;
                for (k = 1; k <= i; k++)
                {
                    f[i][j] += f[k - 1][j - 1] * f[i - k][j];
                }
            }
        }
    }
}

int main()
{
    solve();

    while (scanf("%d %d", &n, &d) != EOF)
    {
        if (n % 2 == 1)
            printf("0\n");
        else
            printf("%lld\n", f[n / 2][d] - f[n / 2][d - 1]);
    }
    return 0;
}
*/

#include <bits/stdc++.h>

using namespace std;

int n, d;
long long result;
long long c[151][151];
long long f[151][151];

void solve()
{
    int i, j, k;
    for (i = 0; i <= 150; i++)
    {
        for (j = 0; j <= 150; j++)
        {
            if (i == 0 && j == 0)
                f[i][j] = 1;
            else if (i < j)
                f[i][j] = f[i][i];
            else if (j == 1)
                f[i][j] = 1;
            else if (j == 0)
                f[i][j] = 0;
            else
            {
                f[i][j] = 0;
                for (k = 1; k <= i; k++)
                {
                    f[i][j] += f[k - 1][j - 1] * f[i - k][j];
                }
            }
        }
    }
}

int main()
{
    solve();

    while (scanf("%d %d", &n, &d) != EOF)
    {
        if (n % 2 == 1)
            printf("0\n");
        else
            printf("%lld\n", f[n / 2][d] - f[n / 2][d - 1]);
    }
    return 0;
}
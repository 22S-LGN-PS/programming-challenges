#include <bits/stdc++.h>

using namespace std;

long long f[2][100][100], ans;
int tem[100];
int n, k, tol;

void bishops(int x)
{
    tol = 0;
    for (int t = x; t <= n; t += 2)
    {
        tem[++tol] = t;
        if (t != n)
            tem[++tol] = t;
    }
    f[x - 1][0][0] = 1;
    for (int i = 1; i <= tol; i++)
        for (int j = 0; j <= k; j++)
            if (tem[i] >= j)
                f[x - 1][i][j] = f[x - 1][i - 1][j] + f[x - 1][i - 1][j - 1] * (tem[i] - j + 1);
}

int main()
{
    scanf("%d %d", &n, &k);
    bishops(1);
    bishops(2);
    for (int i = 0; i <= k; i++)
    {
        ans += f[1][tol][i] * f[0][2 * n - 1 - tol][k - i];
    }
    printf("%lld", ans);
}
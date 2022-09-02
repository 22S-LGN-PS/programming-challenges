// UVa ID: 10157

#include <bits/stdc++.h>

#define MAX_LEN 300
#define MAX_DEP 150

long long exps[MAX_LEN + 1][MAX_DEP + 1]; // memory
// exp() is exponential function, name 'exp' causes ambiguity!

using namespace std;

long long count(int n, int d)
{
    if (n == 0 && d == 0) // base case
        return 1;
    if (n == d * 2)
        return 1;

    if (n % 2 == 1) // wrong case
        return 0;
    if (n == 0 || d == 0)
        return 0;
    if (n < d * 2)
        return 0;

    if (exps[n][d] != 0) // check memory
        return exps[n][d];

    exps[n][d] += count(n - 2, d - 1); // (A) case

    // AB case
    for (int i = 2; i < n; i += 2) // left side(A)'s len
    {
        for (int j = 1; j < d; j++)
        {
            exps[n][d] += count(i, d) * count(n - i, j);
            exps[n][d] += count(i, j) * count(n - i, d);
        }
        exps[n][d] += count(i, d) * count(n - i, d);
    }

    return exps[n][d];
}

int main()
{
    int n, d;
    while (cin >> n >> d)
    {
        printf("%lld\n", count(n, d));
    }
    return 0;
}
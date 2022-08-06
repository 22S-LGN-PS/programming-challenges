#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> s1;
    scanf("%d", &n);
    int t;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        s1.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        if (s1[i] != t)
        {
            printf("\nError! #%d: %d != %d", i, s1[i], t);
        }
    }
    return 0;
}
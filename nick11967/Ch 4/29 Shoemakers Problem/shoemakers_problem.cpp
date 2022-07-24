#include <bits/stdc++.h>

using namespace std;

#define T first
#define S second

int main()
{
    int c;
    scanf("%d", &c);
    int n;
    vector<pair<int, int>> work;
    while (c--)
    {
        scanf("%d", &n);
        work.clear();
        int t, s;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &t, &s);
            work.push_back(make_pair(t, s));
        }
        }
    return 0;
}
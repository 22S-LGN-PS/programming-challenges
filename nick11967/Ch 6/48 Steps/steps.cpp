// UVa ID: 846

#include <bits/stdc++.h>

using namespace std;

vector<unsigned int> max_len;

int step(int x)
{
    if (x == 0)
        return 0;
    int size = max_len.size();
    for (int i = 1; i < size; i++)
    {
        if (x <= max_len[i])
        {
            return i;
        }
    }
    while (1)
    {
        max_len.push_back(max_len[size - 1] + (size + 1) / 2);
        size++;
        if (x <= max_len[size - 1])
        {
            return size - 1;
        }
    }
}

int main()
{
    int n;
    int x, y;

    scanf("%d", &n);

    max_len.push_back(0);
    max_len.push_back(1);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        int len = abs(y - x);
        printf("%d\n", step(len));
    }
    return 0;
}
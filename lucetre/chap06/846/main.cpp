#include <bits/stdc++.h>
using namespace std;

int get_min_steps_of_length(int len)
{
    int step = 0, total_steps = 0;
    while (total_steps < len)
    {
        step++;
        total_steps += (step + 1) / 2;
    }
    return step;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << get_min_steps_of_length(abs(x - y)) << endl;
    }

    return 0;
}
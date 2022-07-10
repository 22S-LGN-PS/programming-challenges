#include <iostream>

using namespace std;

int main()
{
    bool diff_check[3001];
    int n, pre, cur;
    int diff;
    bool jolly;
    cin >> n;
    while (n != '\n')
    {
        jolly = true;
        for (int i = 0; i <= n; i++)
            diff_check[i] = false;

        cin >> pre;
        for (int i = 2; i <= n; i++)
        {
            cin >> cur;
            diff = pre - cur;
            if (diff < 0)
                diff *= -1;
            diff_check[diff] = true;

            pre = cur;
        }
        for (int i = 1; i <= n - 1; i++)
        {
            if (diff_check[i] == false)
                jolly = false;
        }

        jolly ? cout << "Jolly\n" : cout << "Not Jolly\n";
        cin >> n;
    }
    return 0;
}
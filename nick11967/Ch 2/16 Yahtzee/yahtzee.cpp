#include <iostream>

using namespace std;

int main()
{
    int dice[5], score[15];
    while (dice[0] != '\n')
    {
        for (int i = 1; i <= 13; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> dice[j];
            }
            // do something
        }
        for (int i = 0; i < 15; i++)
        {
            cout << score[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
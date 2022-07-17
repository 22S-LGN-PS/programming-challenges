#include <bits/stdc++.h>

using namespace std;

int dice[13][5];

void invert(string five, int round)
{
    dice[round][0] = five[0] - '0';
    dice[round][1] = five[2] - '0';
    dice[round][2] = five[4] - '0';
    dice[round][3] = five[6] - '0';
    dice[round][4] = five[8] - '0';
}

int main()
{
    int score[15];
    string five_dice;
    while (cin >> five_dice)
    {
        invert(five_dice, 0);
        for (int i = 1; i < 13; i++) // input
        {
            cin >> five_dice;
            invert(five_dice, i);
        }

                for (int i = 0; i < 15; i++) // output
        {
            cout << score[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
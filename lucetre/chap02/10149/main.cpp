#include <bits/stdc++.h>
using namespace std;
#define C 13
#define D 5

enum Yahtzee
{
    ONES = 1,
    TWOS = 2,
    THREES = 3,
    FOURS = 4,
    FIVES = 5,
    SIXES = 6,
    CHANCE,
    THREE_OF_A_KIND,
    FOUR_OF_A_KIND,
    FIVE_OF_A_KIND,
    SHORT_STRAIGHT,
    LONG_STRAIGHT,
    FULL_HOUSE,
};

int dice[C + 1][D + 1];
vector<pair<int, Yahtzee>> possible[C + 1];

void FetchScore()
{
    for (int i = 0; i < C; i++)
    {
        possible[i].clear();
        int chance = 0;
        map<int, int> nmap;
        for (int j = 0; j < D; j++)
        {
            chance += dice[i][j];
            nmap[dice[i][j]]++;
        }
        vector<pair<int, int>> cntDice;
        for (auto np : nmap)
        {
            int cnt = np.second;
            int die = np.first;
            cntDice.push_back(make_pair(cnt, die));
            possible[i].push_back(make_pair(cnt * die, Yahtzee(die)));
        }
        sort(cntDice.begin(), cntDice.end(), greater<pair<int, int>>());

        possible[i].push_back(make_pair(chance, CHANCE));
        if (cntDice[0].first >= 3)
        {
            possible[i].push_back(make_pair(chance, THREE_OF_A_KIND));
            if (cntDice[0].first >= 4)
            {
                possible[i].push_back(make_pair(chance, FOUR_OF_A_KIND));
                if (cntDice[0].first == 5)
                    possible[i].push_back(make_pair(50, FIVE_OF_A_KIND));
            }
            if (cntDice[1].first == 2)
            {
                possible[i].push_back(make_pair(40, FULL_HOUSE));
            }
        }

        for (int j = 1; j <= 3; j++)
        {
            int flag = true;
            for (int k = 0; k < 4; k++)
            {
                if (nmap[j + k] == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                possible[i].push_back(make_pair(25, SHORT_STRAIGHT));
                break;
            }
        }
        for (int j = 1; j <= 2; j++)
        {
            int flag = true;
            for (int k = 0; k < 5; k++)
            {
                if (nmap[j + k] == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                possible[i].push_back(make_pair(35, LONG_STRAIGHT));
                break;
            }
        }
        sort(possible[i].begin(), possible[i].end(), greater<pair<int, int>>());
    }
}

void OptimizeScore()
{
    map<int, pair<int, int>> maxScore[C];
    map<int, int> path[C];
    int state = 0;

    FetchScore();

    // for (int i = 0; i < C; i++)
    // {
    //     for (int j = 0; j < D; j++)
    //     {
    //         cout << dice[i][j];
    //     }
    //     cout << ": ";
    //     for (auto p : possible[i])
    //     {
    //         cout << p.first << "(" << p.second << ") ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for (int i = 0; i < C; i++)
    {
        if (i)
        {
            for (auto ms : maxScore[i - 1])
            {
                maxScore[i][ms.first] = ms.second;
                path[i][ms.first] = ms.first;
            }
        }
        for (auto p : possible[i])
        {
            state = 1 << (p.second - 1);
            int bonus = (p.second <= SIXES) ? p.first : 0;

            maxScore[i][state] = make_pair(p.first, bonus);
            path[i][0] = path[i][state] = 0;

            if (i)
            {
                for (auto ms : maxScore[i - 1])
                {
                    // cout << bitset<C>(ms.first) << ": " << ms.second.first << endl;

                    if ((ms.first & (1 << (p.second - 1))) == 0)
                    {
                        state = ms.first | (1 << (p.second - 1));
                        pair<int, int> score = make_pair(ms.second.first + p.first, ms.second.second + bonus);
                        if (maxScore[i][state] < score)
                        {
                            maxScore[i][state] = score;
                            path[i][state] = ms.first;
                        }
                    }
                }
            }
        }
    }
    // 3 2 6 12 10 12 24 21 0 0 0 35 40 0 165
    int bestI = 0, bestState = 0, bestTotal = 0, bestBonus = 0;
    for (int i = 0; i < C; i++)
    {
        for (auto ms : maxScore[i])
        {
            int bonus = ms.second.second >= 63 ? 35 : 0;
            int total = ms.second.first + bonus;
            // cout << bitset<C>(ms.first) << ": " << total << endl;
            if (bestTotal < total)
            {
                bestTotal = total;
                bestBonus = bonus;
                bestState = ms.first;
                bestI = i;
            }
        }
    }
    // cout << endl;

    int bestScores[C + 2] = {0};
    bestScores[C] = bestBonus;
    bestScores[C + 1] = bestTotal;

    int prev = bestState;
    for (int i = bestI; i >= 0; i--)
    {
        int curr = path[i][prev];
        if (curr ^ prev)
        {
            int yahtzee = log2(curr ^ prev);
            // cout << bitset<C>(curr) << " " << yahtzee << endl;
            for (auto p : possible[i])
            {
                if (p.second - 1 == yahtzee)
                {
                    bestScores[yahtzee] = p.first;
                }
            }
        }
        prev = curr;
    }
    // cout << bitset<C>(bestState) << ": " << bestTotal << "," << bestBonus << endl;

    for (int i = 0; i < C + 2; i++)
    {
        cout << bestScores[i] << " ";
    }
    cout << endl;
}

int main()
{
    while (true)
    {
        int enable = true;
        for (int i = 0; i < C; i++)
        {
            for (int j = 0; j < D; j++)
            {
                if (!(cin >> dice[i][j]))
                {
                    enable = false;
                    break;
                }
            }
            if (!enable)
                break;
        }
        if (!enable)
            break;
        OptimizeScore();
    }
    return 0;
}
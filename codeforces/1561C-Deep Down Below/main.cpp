#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
/* #define DEBUG */

#define MAXLEN = 1e5 + 3
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> vec;
    for (int i = 1; i <= n; i++)
    {
        int k, a;
        cin >> k;
        vector<int> temp;
        for (int j = 1; j <= k; j++)
        {
            cin >> a;
            temp.push_back(a);
        }
        vec.push_back(temp);
    }

    vector<pair<int, int>> minPower;

    for (int i = 0; i < vec.size(); i++)
    {
        int needMinPower = 0;
        int nowPower = 0;
        for (int j = 0; j < vec[i].size(); j++)
        {
            int armor = vec[i][j];
            if (armor >= nowPower)
            {
                int diff = armor - nowPower;
                needMinPower += diff + 1;
                nowPower = armor + 1;
            }
            nowPower++;
        }
        minPower.push_back(pair<int, int>{needMinPower, i});
    }

    sort(minPower.begin(), minPower.end());
    int finalMinPower = 0;
    int nowPower = 0;
    for (int i = 0; i < minPower.size(); i++)
    {
#ifdef DEBUG
        printf("minPower[%d]: %d nowPower: %d finalMinPower: %d\n", i, minPower[i].first, nowPower, finalMinPower);
#endif

        if (nowPower < minPower[i].first)
        {
            finalMinPower += (minPower[i].first - nowPower);
            nowPower = minPower[i].first;
        }
        nowPower += vec[minPower[i].second].size();
    }
    cout << finalMinPower << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
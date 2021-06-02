#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
//#define _DEBUG
//#define _DEBUG_1
//#define _DEBUG_2
using namespace std;
class Solution
{
    const int MAX = 100010;

public:
    vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance)
    {
        memset(idMap, 0, sizeof(idMap));
        int maxID = 0;
        for (auto iter = restaurants.begin(); iter != restaurants.end(); iter++)
        {
            auto now = *iter;
            int id = now[0];
            int rating = now[1];
            int veganFriendly = now[2];
            int price = now[3];
            int distance = now[4];
            if (veganFriendly == 1 && veganFriendly != veganFriendly)
            {
                continue;
            }
            if (price > maxPrice || distance > maxDistance)
            {
                continue;
            }
            idMap[id] = 1;
        }
        vector<int> ret;
        for (int i = maxID; i >= 0; i--)
        {
            if (idMap[i] == 1)
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

// for test
int main()
{
    Solution s;
    return 0;
}
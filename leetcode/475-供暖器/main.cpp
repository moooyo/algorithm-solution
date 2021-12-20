#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
#define _DEBUG

#define INF 0x7f7f7f7f
// submit
struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first < b.first)
        {
            return true;
        }
        if (a.first == b.first && a.second < b.second)
        {
            return true;
        }
        return false;
    }
};

class Solution
{
public:
    int minVal;
    bool findInVec(int left, int right, int targetVal, int radius, vector<int> &data)
    {
        if (left > right)
        {
            return false;
        }
        int mid = (left + right) / 2;
        int midVal = data[mid];
        if (midVal - radius <= targetVal && targetVal <= midVal + radius)
        {
            return true;
        }
        if (targetVal > midVal + radius)
        {
            return findInVec(mid + 1, right, targetVal, radius, data);
        }
        return findInVec(left, mid - 1, targetVal, radius, data);
    }

    void find(int left, int right, vector<int> &houses, vector<int> &heaters)
    {
        if (left > right)
        {
            return;
        }

        int mid = (left + right) / 2;
        bool allMatch = true;
        int heatersNum = heaters.size();
        for (int i = 0; i < houses.size(); i++)
        {
            int house = houses[i];
            bool find = findInVec(0, heatersNum - 1, house, mid, heaters);
            if (!find)
            {
                allMatch = false;
                break;
            }
        }
        if (allMatch)
        {
            minVal = mid;
            find(left, mid - 1, houses, heaters);
        }
        else
        {
            find(mid + 1, right, houses, heaters);
        }
    }

    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        minVal = INF;
        sort(heaters.begin(), heaters.end());
        find(0, 1e9, houses, heaters);
        return minVal;
    }
};

// for test
int main()
{
    Solution s;

    return 0;
}

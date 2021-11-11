#include <iostream>
#include <vector>
using namespace std;

#define _DEBUG
#define MAXN 30

class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int total = 0;
        int nextEndTime = -1;
        for (int i = 0; i < timeSeries.size(); i++)
        {
            if (nextEndTime < timeSeries[i] - 1)
            {
                nextEndTime = timeSeries[i] - 1;
            }

            int nowEndTime = timeSeries[i] + duration - 1;
            int diff = nowEndTime - nextEndTime;
            if (diff > 0)
            {
                total += diff;
            }
            nextEndTime = nowEndTime;
        }
        return total;
    }
};

// for test
int main()
{
    Solution s;
    vector<vector<int>> test1{{2, 2}, {3, 3}};
    cout << s.maxCount(3, 3, test1) << endl;
    vector<vector<int>> test2{};
    cout << s.maxCount(3, 3, test2) << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <set>
//#define _DEBUG
using namespace std;
class Solution
{
public:
    bool xorGame(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum ^= nums[i];
        }
        if (sum == 0)
            return true;

        int count = nums.size();
        if (count % 2 == 0)
        {
            return true;
        }
        return false;
    }
};

// for test
int main()
{
    Solution s;

    return 0;
}
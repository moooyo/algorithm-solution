#include <iostream>
#include <vector>
//#define _DEBUG
using namespace std;
// submit
class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int max = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            max = max < bloomDay[i] ? bloomDay[i] : max;
        }
        return solve(1, max + 1, bloomDay, m, k);
    }
    int solve(int left, int right, vector<int> &bloomDay, int m, int k)
    {
        if (left > right)
        {
            return -1;
        }

        int mid = (left + right) / 2;
#ifdef _DEBUG
        cout << "mid: " << mid << endl;
#endif
        bool find = judge(bloomDay, mid, m, k);
#ifdef _DEBUG
        cout << "find: " << find << endl;
#endif
        if (find)
        {
            int ret = solve(left, mid - 1, bloomDay, m, k);
            return ret != -1 ? ret : mid;
        }
        else
        {
            return solve(mid + 1, right, bloomDay, m, k);
        }
    }
    bool judge(vector<int> &test, int target, int m, int k)
    {
#ifdef _DEBUG
        for (int i = 0; i < test.size(); i++)
        {
            cout << test[i] << " ";
        }
        cout << endl;
#endif
        int count = 0;
        int now = 0;
        for (int i = 0; i < test.size(); i++)
        {
            if (test[i] <= target)
            {
                now++;
            }
            else
            {
                now = 0;
            }
            if (now == k)
            {
                now = 0;
                count++;
            }
        }
#ifdef _DEBUG
        cout << "count: " << count << endl;
#endif
        return count >= m;
    }
};

// for test
int main()
{
    Solution s;
    vector<int> test1{1, 10, 3, 10, 2};
    cout << s.minDays(test1, 3, 1) << endl;
    vector<int> test2{1, 10, 3, 10, 2};
    cout << s.minDays(test2, 3, 2) << endl;
    vector<int> test3{7, 7, 7, 7, 12, 7, 7};
    cout << s.minDays(test3, 2, 3) << endl;
    return 0;
}
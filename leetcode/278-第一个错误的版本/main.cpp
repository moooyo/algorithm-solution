#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define _DEBUG
#define LL long long

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
#ifdef _DEBUG
    const int GUESS = 2;
    bool isBadVersion(int num)
    {
        if (num == GUESS)
        {
            return true;
        }
        return false;
    }
#endif
    int firstBadVersion(int n)
    {
        return find(1, n);
    }
    int find(int left, int right)
    {
        if (left >= right)
        {
            return left;
        }
        int mid = left + (right - left) / 2;
        int val = isBadVersion(mid);
#ifdef _DEBUG
        cout << "mid: " << mid << " val: " << int(val) << endl;
#endif
        if (val)
        {
            return find(left, mid);
        }

        return find(mid + 1, right);
    }
};

// for test
int main()
{
    Solution s;
    cout << s.firstBadVersion(3);

    return 0;
}
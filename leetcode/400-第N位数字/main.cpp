#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
/* #define _DEBUG
 */
#define LL long long
class Solution
{
public:
    int getDigitCount(int num)
    {
        int dightCount = 0;
        while (num != 0)
        {
            num = num / 10;
            dightCount++;
        }
        return dightCount;
    }
    int countNum(int num, int target)
    {
        int dightCount = 0;
        int temp = num;
        int topDightNum = 0;
        while (temp != 0)
        {
            topDightNum = temp;
            temp = temp / 10;
            dightCount++;
        }
        LL count = 0;
        int sz = 1;
        for (int i = 1; i < dightCount; i++)
        {
            if (count > target || count + sz * i * 9 > target)
            {
                return -1;
            }

            count += sz * i * 9;
            sz *= 10;
        }

        int base = 1;
        for (int i = 0; i < dightCount - 1; i++)
        {
            base *= 10;
        }
        int needToAppend = num - base + 1;
        if (count > target || count + needToAppend * dightCount > target)
        {
            return -1;
        }

        count += needToAppend * dightCount;
        return count;
    }

    int bisectionFind(int left, int right, int target)
    {
        int mid = right + (left - right) / 2;
        int count = countNum(mid - 1, target);
        int digitNum = getDigitCount(mid);
        if (count == -1)
        {
            return bisectionFind(left, mid - 1, target);
        }

        int diff = target - count;
#ifdef _DEBUG
        cout << "mid: " << mid << " left: " << left << " right: " << right << " mid: " << mid << " diff: " << diff;
        cout << " count: " << count << " digitNum: " << digitNum << endl;
#endif
        if (diff > 0 && diff <= digitNum)
        {
            diff = digitNum - diff;
            int ret = mid;
            while (diff > 0)
            {
                ret = ret / 10;
                diff--;
            }
            return ret % 10;
        }
        if (diff <= 0)
        {
            return bisectionFind(left, mid - 1, target);
        }
        return bisectionFind(mid + 1, right, target);
    }
    int findNthDigit(int n)
    {
        return bisectionFind(1, INT_MAX, n);
    }
};

// for test
int main()
{
    Solution s;
    cout << s.findNthDigit(3) << endl;
    cout << s.findNthDigit(11) << endl;
    cout << s.findNthDigit(10) << endl;
    cout << s.findNthDigit(2147483647) << endl;
    return 0;
}
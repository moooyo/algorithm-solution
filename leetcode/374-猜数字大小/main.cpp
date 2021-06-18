#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define _DEBUG
#define LL long long

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
#ifdef _DEBUG
    const int GUESS = 6;
    int guess(int num)
    {
        if (num == GUESS)
        {
            return 0;
        }
        else if (GUESS < num)
        {
            return -1;
        }
        else
        {
            return 1;
        }
        return -1;
    }
#endif
    int guessNumber(int n)
    {
        return find(1, n);
    }
    int find(int left, int right)
    {
        if (left > right)
        {
            return -1;
        }
        int mid = left + (right - left) / 2;
        int val = guess(mid);
#ifdef _DEBUG
        cout << "mid: " << mid << " val: " << val << endl;
#endif
        if (val == 0)
        {
#ifdef _DEBUG
            cout << "ret:" << mid << endl;
#endif
            return mid;
        }
        else if (val == -1)
        {
            return find(left, mid - 1);
        }
        else
        {
            return find(mid + 1, right);
        }
        return -1;
    }
};

// for test
int main()
{
    Solution s;
    cout << s.guessNumber(10);

    return 0;
}
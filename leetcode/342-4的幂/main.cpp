#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;

#define _NDEBUG
class Solution
{
    const int MAX = 1 << 30;

public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0 || (n & (n - 1)) != 0)
        {
            return false;
        }
        int mask = 0b1010101010101010101010101010101;
        return (n & mask) != 0;
    }
};

// for test
int main()
{
    Solution s;
    cout << s.isPowerOfFour(16) << endl;
    cout << s.isPowerOfFour(5) << endl;
    cout << s.isPowerOfFour(8) << endl;
    cout << s.isPowerOfFour(1) << endl;
    cout << s.isPowerOfFour(1073741824) << endl;

    return 0;
}
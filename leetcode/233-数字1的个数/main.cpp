#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
#define DEBUG

#define LL long long
class Solution
{
public:
    int countDigitOne(int n)
    {
        LL mod = 1;
        int ret = 0;
        while (n >= mod)
        {
            mod = mod * 10;
            LL count = n / mod;
            ret += count * (mod / 10);
            LL m = n % mod;
#ifdef DEBUG
            cout << "mod: " << mod << " count: " << count << " ret: " << ret << " m: " << m << endl;
#endif

            if (m < mod / 10)
            {
                continue;
            }
            else if (m >= mod / 10 * 2)
            {
                ret += mod / 10;
            }
            else
            {
                ret += (m - (mod / 10)) + 1;
            }
#ifdef DEBUG
            cout << "ret: " << ret << endl;
#endif
        }
        return ret;
    }
};

// for test
int main()
{
    Solution s;
    cout << s.countDigitOne(13) << endl;
    cout << s.countDigitOne(0) << endl;
    cout << s.countDigitOne(2) << endl;
    return 0;
}
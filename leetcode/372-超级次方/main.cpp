#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
#define DEBUG
#define MOD 1337
class Solution
{
public:
    int pow(int a, int b, int mod)
    {
        int ret = 1;
        int now = a;
        if (a > mod)
        {
            a = a % mod;
        }

        while (b)
        {
            if (now > mod)
            {
                now %= mod;
            }
            if (b % 2 != 0)
            {
                ret *= now;
            }
            b /= 2;
            if (ret > mod)
            {
                ret %= mod;
            }
            now *= now;
        }
        return ret;
    }
    int superPow(int a, vector<int> &b)
    {
        int ret = 1;
        int temp = a;
        for (int i = b.size() - 1; i >= 0; i--)
        {
            auto now = pow(temp, b[i], MOD);
#ifdef DEBUG
            cout << "b: " << b[i] << " now: " << now << " temp: " << temp << endl;
#endif
            ret *= now;
            temp = pow(temp, 10, MOD);
            ret = ret % MOD;
        }
        return ret;
    }
};
// for test
int main()
{
    Solution s;
    vector<int> test1{3};
    cout << s.superPow(2, test1) << endl;
    vector<int> test2{4, 3, 3, 8, 5, 2};
    cout << s.superPow(1, test2) << endl;
    vector<int> test3{2, 0, 0};
    cout << s.superPow(2147483647, test3) << endl;
    return 0;
}
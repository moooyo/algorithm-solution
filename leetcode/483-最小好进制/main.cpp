#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
#define _DEBUG
#define LL unsigned long long

class Solution
{
public:
    string smallestGoodBase(string n)
    {
        LL nVal = stol(n);
#ifdef _DEBUG
        cout << nVal << endl;
#endif
        const LL MAXM = 60;
        for (LL i = MAXM; i >= 2; i--)
        {
            LL sq = sqrtm(nVal, i);
#ifdef _DEBUG
            cout << " sq: " << sq << endl;
#endif
            if (sq >= 2)
            {
                if (check(i, sq, nVal))
                {
                    return to_string(sq);
                }
            }
        }
        return to_string(nVal - 1);
    }

    // return \sqrt^{m}{n}
    LL sqrtm(LL n, LL m)
    {
        LL ret = 0;
        find(1, n + 1, n, m, ret);
        return ret;
    }
    void find(LL left, LL right, LL n, LL m, LL &t)
    {
        if (left >= right || right - left == 1)
        {
            return;
        }
        LL mid = (left + right) / 2;
#ifdef _DEBUG
        cout << "m: " << m << " n: " << n << " mid: " << mid << " left: " << left << " right: " << right << endl;
#endif
        double lnmid = log(mid);
        double lnn = log(n);
        if (m * lnmid < lnn)
        {
            find(mid, right, n, m, t);
        }
        else
        {
#ifdef _DEBUG
            cout << "t: " << mid << endl;
#endif
            if (m * lnmid - lnn < 1e-9)
            {
                t = mid;
            }
            else
            {
                t = mid - 1;
            }
            find(left, mid, n, m, t);
        }
    }
    bool check(LL m, LL k, LL n)
    {
#ifdef _DEBUG
        cout << "m: " << m << " n: " << n << " k:" << k << endl;
#endif
        LL ret = 1;
        LL pre = 1;
        for (LL i = 0; i < m; i++)
        {
            pre = pre * k;
            ret = ret + pre;
            if (ret == n)
            {
                return true;
            }
        }

#ifdef _DEBUG
        cout << "ret: " << ret << endl;
#endif
        return false;
    }
};

// for test
int main()
{

    Solution s;
    /*
    cout << s.smallestGoodBase("13") << endl;
    cout << s.smallestGoodBase("4681") << endl;
    cout << s.smallestGoodBase("2251799813685247") << endl;*/
    cout << s.smallestGoodBase("919818571896748567") << endl;
    return 0;
}
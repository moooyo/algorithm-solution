#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
#define _DEBUG

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int len = points.size();
        int ret = 1;
        for (int i = 0; i < len; i++)
        {
            map<string, int> kmap;
            auto point1 = points[i];
            int x1 = point1[0];
            int y1 = point1[1];
            for (int j = i + 1; j < len; j++)
            {
                auto point2 = points[j];
                int x2 = point2[0];
                int y2 = point2[1];
                int dx = x2 - x1;
                int dy = y2 - y1;
                if (dx < 0 && dy < 0)
                {
                    dx *= -1;
                    dy *= -1;
                }
                if (dy < 0 && dx > 0)
                {
                    dx *= -1;
                    dy *= -1;
                }
                int k = gcd(dx, dy);
                int mx = dx / k;
                int my = dy / k;
                string hashKey = "";
                if (my == 0)
                {
                    hashKey = "DY";
                }
                else if (mx == 0)
                {
                    hashKey = "DX";
                }
                else
                {
                    hashKey = to_string(mx) + "_" + to_string(my);
                }
#ifdef _DEBUG
                cout << "x1: " << x1 << " x2: " << x2 << " y1: " << y1 << " y2: " << y2 << " dx:" << dx << " dy:" << dy << " k:" << k << " hashKey:" << hashKey << endl;
#endif
                if (kmap.count(hashKey) == 0)
                {
                    kmap[hashKey] = 0;
                }
                kmap[hashKey]++;
            }
            auto iter = kmap.begin();
            while (iter != kmap.end())
            {
                int val = iter->second;
                if (val + 1 > ret)
                {
                    ret = val + 1;
                }
                iter++;
            }
        }
        return ret;
    }
    int gcd(int x, int y)
    {
        if (x < 0)
        {
            return gcd(x * -1, y);
        }
        if (y < 0)
        {
            return gcd(x, y * -1);
        }

#ifdef _DEBUG
        cout << "x: " << x << " y: " << y << endl;
#endif
        if (y > x)
        {
            return gcd(y, x);
        }
        if (y == 0)
        {
            return x;
        }
        return gcd(x - y, y);
    }
};

// for test
int main()
{
    Solution s;

    /*
    vector<vector<int>> t1{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    cout << s.maxPoints(t1) << endl;

    vector<vector<int>> t2{{1, 1}, {2, 2}, {3, 3}};
    cout << s.maxPoints(t2) << endl;

    vector<vector<int>> t3{{0, 0}, {4, 5}, {7, 8}, {8, 9}, {5, 6}, {3, 4}, {1, 1}};
    cout << s.maxPoints(t3) << endl;*/
    vector<vector<int>> t4{
        {2, 3},
        {3, 3},
        {-5, 3}};
    cout << s.maxPoints(t4) << endl;

    return 0;
}
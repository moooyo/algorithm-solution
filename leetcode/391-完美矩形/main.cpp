#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
/* #define _DEBUG */

bool mless(vector<int> &a, vector<int> &b)
{
    if (a[0] < b[0])
    {
        return true;
    }

    if (a[0] != b[0])
    {
        return false;
    }

    if (a[1] < b[1])
    {
        return true;
    }
    if (a[1] != b[1])
    {
        return false;
    }

    return false;
}

typedef struct line
{
    int start;
    int end;
    line(int a, int b)
    {
        this->start = a;
        this->end = b;
    }
    bool operator<(const line &a)
    {
        return this->start < a.start;
    }
} line;

class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        for (int i = 0; i < rectangles.size(); ++i)
        {
            for (int j = 0; j < i; j++)
            {
                auto a = rectangles[i];
                auto b = rectangles[j];
                if (mless(a, b))
                {
                    auto temp = rectangles[i];
                    rectangles[i] = rectangles[j];
                    rectangles[j] = temp;
                }
            }
        }
#ifdef _DEBUG
        cout << "sorted list:" << endl;
        for (int i = 0; i < rectangles.size(); ++i)
        {
            cout << rectangles[i][0] << " " << rectangles[i][1] << " " << rectangles[i][2] << " " << rectangles[i][3] << endl;
        }
#endif
        int minx, miny, maxx, maxy;
        maxx = maxy = -100001;
        minx = miny = 100001;
        for (int i = 0; i < rectangles.size(); ++i)
        {
            auto a = rectangles[i];
            if (a[0] < minx)
            {
                minx = a[0];
            }
            if (a[1] < miny)
            {
                miny = a[1];
            }
            if (a[2] > maxx)
            {
                maxx = a[2];
            }
            if (a[3] > maxy)
            {
                maxy = a[3];
            }
        }
        int k = 0;
#ifdef _DEBUG
        cout << "minx: " << minx << " miny: " << miny << " maxx: " << maxx << " maxy: " << maxy << endl;
#endif

        for (int i = minx; i < maxx; i++)
        {
#ifdef _DEBUG
            cout << "now scan " << i << endl;
#endif
            while (1)
            {
#ifdef _DEBUG
                cout << "k is " << k << endl;
#endif
                if (k >= rectangles.size())
                {
                    return false;
                }

                if (rectangles[k][2] > i)
                {
                    break;
                }
                k++;
            }
            if (k >= rectangles.size())
            {
                return false;
            }
            vector<line> temp;
            for (int r = k; r < rectangles.size(); r++)
            {
#ifdef _DEBUG
                cout << "now r is " << r << endl;
#endif
                auto a = rectangles[r];
                if (a[0] > i)
                {
                    break;
                }
                if (a[2] <= i)
                {
                    continue;
                }
                line appendTemp(a[1], a[3]);
                temp.push_back(appendTemp);
            }
            sort(temp.begin(), temp.end());
            int nowy = miny;
            for (auto iter = temp.begin(); iter != temp.end(); iter++)
            {
                if (iter->start != nowy)
                {
                    return false;
                }
                nowy = iter->end;
            }
            if (nowy != maxy)
            {
                return false;
            }
        }
        return true;
    }
};

// for test
int main()
{
    Solution s;
    vector<vector<int>> test1{{1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};
    cout << s.isRectangleCover(test1) << endl;
    vector<vector<int>> test2{{1, 1, 2, 3}, {1, 3, 2, 4}, {3, 1, 4, 2}, {3, 2, 4, 4}};
    cout << s.isRectangleCover(test2) << endl;
    vector<vector<int>> test3{{1, 1, 3, 3}, {3, 1, 4, 2}, {1, 3, 2, 4}, {3, 2, 4, 4}};
    cout << s.isRectangleCover(test3) << endl;
    vector<vector<int>> test4{{1, 1, 3, 3}, {3, 1, 4, 2}, {1, 3, 2, 4}, {2, 2, 4, 4}};
    cout << s.isRectangleCover(test4) << endl;
    vector<vector<int>> test5{{0, 0, 4, 1}, {7, 0, 8, 2}, {6, 2, 8, 3}, {5, 1, 6, 3}, {4, 0, 5, 1}, {6, 0, 7, 2}, {4, 2, 5, 3}, {2, 1, 4, 3}, {0, 1, 2, 2}, {0, 2, 2, 3}, {4, 1, 5, 2}, {5, 0, 6, 1}};
    cout << s.isRectangleCover(test5) << endl;
    return 0;
}
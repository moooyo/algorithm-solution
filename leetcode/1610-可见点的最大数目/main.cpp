#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
/* #define DEBUG */
// submit
class Solution
{
public:
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location)
    {
        int x = location[0];
        int y = location[1];
        int appendCnt = 0;
        vector<double> angles;
        for (auto iter = points.begin(); iter != points.end(); iter++)
        {
            auto point = *iter;
            int px = point[0];
            int py = point[1];
            if (px == x && py == y)
            {
                appendCnt++;
                continue;
            }

            double pointAngle = atan2(py - y, px - x);
            if (pointAngle < 0)
            {
                pointAngle += 2 * M_PI;
            }
            pointAngle = pointAngle * 180 / M_PI;
            /* #ifdef DEBUG
                        cout << "px: " << px << " py: " << py << " angle: " << pointAngle << endl;
            #endif */

            angles.push_back(pointAngle);
        }
        sort(angles.begin(), angles.end());
#ifdef DEBUG
        for (int i = 0; i < angles.size(); i++)
        {
            cout << angles[i] << endl;
        }
        cout << endl;
#endif

        int len = angles.size();
        int i = 0, j = 0;
        int maxCount = 0;
        while (i <= j && i < len && (j < len || j < i + len))
        {
            int idxJ = j;
            if (j >= len)
            {
                idxJ = j % len;
            }

            double angleA = angles[i];
            double angleB = angles[idxJ];

            if (j >= len)
            {
                angleB = angleB + 360;
            }

#ifdef DEBUG
            cout << "i: " << i << " j: " << j << " idxJ: " << idxJ << " angleA: " << angleA << " angleB: " << angleB << " angleB - angleA: " << angleB - angleA << endl;
#endif

            if (angleB - angleA <= angle)
            {
                int cnt = j - i + 1;

                if (cnt > maxCount)
                {
                    maxCount = cnt;
                }
                j++;
            }
            else
            {
                i++;
            }
        }
        return maxCount + appendCnt;
    }
};

// for test
int main()
{
    Solution s;
    vector<vector<int>> points1{{2, 1}, {2, 2}, {3, 3}, {2, 0}};
    vector<int> location1{1, 1};
    cout << s.visiblePoints(points1, 90, location1) << endl;

    vector<vector<int>> points2{{1, 0}, {2, 1}};
    vector<int> location2{1, 1};
    cout << s.visiblePoints(points2, 13, location2) << endl;

    vector<vector<int>> points3{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {1, 2}, {2, 1}};
    vector<int> location3{1, 1};
    cout << s.visiblePoints(points3, 0, location3) << endl;

    vector<vector<int>> points4{{41, 7}, {22, 94}, {90, 53}, {94, 54}, {58, 50}, {51, 96}, {87, 88}, {55, 98}, {65, 62}, {36, 47}, {91, 61}, {15, 41}, {31, 94}, {82, 80}, {42, 73}, {79, 6}, {45, 4}};
    vector<int> location4{6, 84};
    cout << s.visiblePoints(points4, 17, location4) << endl;

    return 0;
}
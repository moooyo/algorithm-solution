#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define DEBUG
struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first < b.first;
    }
};
class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        vector<pair<int, int>> data;
        for (int i = 0; i < courses.size(); i++)
        {
            data.push_back(pair<int, int>(courses[i][0], courses[i][1]));
        }
        sort(data.begin(), data.end(), [](pair<int, int> a, pair<int, int> b) -> bool
             { 
                 if (a.second != b.second) {
                 return a.second < b.second;
                 } else {
                     return a.first < b.first;
                 } });
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
#ifdef DEBUG
        cout << "courses: " << endl;
        for (int i = 0; i < data.size(); i++)
        {
            cout << "data[i]: " << data[i].first << " " << data[i].second << endl;
        }
        cout << endl;
#endif

        int count = 0;
        int sum = 0;
        for (int i = 0; i < data.size(); i++)
        {
            auto course = data[i];
            if (course.first + sum <= course.second)
            {
                sum += course.first;
                count++;
                pq.push(course);
            }
            else
            {
                if (!pq.empty())
                {
                    auto tmp = pq.top();
#ifdef DEBUG
                    cout << "top: tmp.first: " << tmp.first << " tmp.second: " << tmp.second << endl;
#endif

                    if (tmp.first >= course.first)
                    {
#ifdef DEBUG
                        cout << "pop tmp.first: " << tmp.first << " tmp.second: " << tmp.second << endl;
#endif
                        pq.pop();
                        sum -= tmp.first;
                        sum += course.first;
                        pq.push(course);
                    }
                }
            }
        }

        return count;
    }
};
// for test
int main()
{
    Solution s;
    /*     vector<vector<int>> courses1{{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
        cout << s.scheduleCourse(courses1) << endl;
        vector<vector<int>> courses2{{3, 2}, {4, 3}};
        cout << s.scheduleCourse(courses2) << endl;
        vector<vector<int>> courses3{{5, 5}, {4, 6}, {2, 6}};
        cout << s.scheduleCourse(courses3) << endl;
        vector<vector<int>> course4{{5, 15}, {3, 19}, {6, 7}, {2, 10}, {5, 16}, {8, 14}, {10, 11}, {2, 19}};
        cout << s.scheduleCourse(course4) << endl;
        vector<vector<int>> course5{{5, 5}, {4, 6}, {2, 6}};
        cout << s.scheduleCourse(course5) << endl;
     */
    vector<vector<int>> course6{{7, 17}, {3, 12}, {10, 20}, {9, 10}, {5, 20}, {10, 19}, {4, 18}};
    cout << s.scheduleCourse(course6) << endl;

    return 0;
}
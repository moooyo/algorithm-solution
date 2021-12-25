#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

#define DEBUG

int monthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Solution
{
public:
    int dayOfYear(string date)
    {
        int year, month, day;
        bool leapYear = false;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        int diff = year - 2008;
        if (diff < 0)
        {
            diff *= -1;
        }
        if (diff % 4 == 0)
        {
            leapYear = true;
        }
        int sum[13];
        sum[0] = 0;
        for (int i = 1; i <= 12; i++)
        {
            sum[i] = sum[i - 1] + monthDay[i];
            if (i == 2 && leapYear)
            {
                sum[i]++;
            }
        }
        int count = 0;
        count += sum[month - 1] + day;
        return count;
    }
};
// for test
int main()
{
    Solution s;
    vector<vector<int>> test1{{2, 2}, {3, 3}};
    cout << s.maxCount(3, 3, test1) << endl;
    vector<vector<int>> test2{};
    cout << s.maxCount(3, 3, test2) << endl;

    return 0;
}
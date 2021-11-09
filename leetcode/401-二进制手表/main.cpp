#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define _DEBUG
class Solution
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<int> hr[5];
        vector<int> min[7];
        vector<string> ret;
        for (int i = 0; i <= 11; i++)
        {
            int num = i;
            int cnt = getCnt(num);
            hr[cnt].push_back(i);
        }
        for (int i = 0; i <= 59; i++)
        {
            int num = i;
            int cnt = getCnt(num);
            min[cnt].push_back(i);
        }
        for (int i = 0; i <= turnedOn && i <= 4; i++)
        {
            int diff = turnedOn - i;
            if (diff >= 7)
            {
                continue;
            }
            for (int k = 0; k < hr[i].size(); k++)
            {
                for (int j = 0; j < min[diff].size(); j++)
                {
                    char s[256];
                    sprintf(s, "%d:%02d", hr[i][k], min[diff][j]);
                    ret.push_back(string(s));
                }
            }
        }
        return ret;
    }
    int getCnt(int num)
    {
        int cnt = 0;
        while (num > 0)
        {
            num &= (num - 1);
            cnt++;
        }
        return cnt;
    }
};

// for test
int main()
{
    Solution s;
    vector<string> t1 = s.readBinaryWatch(9);
    for (int i = 0; i < t1.size(); i++)
    {
        cout << t1[i] << " ";
    }
    cout << endl;

    return 0;
}
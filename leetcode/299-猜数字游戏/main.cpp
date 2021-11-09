#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <map>
using namespace std;
#define _DEBUG

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int cntA = 0;
        int cntB = 0;
        map<char, int> mapA;
        map<char, int> mapB;
        for (int i = 0; i < secret.length(); i++)
        {
            if (secret[i] == guess[i])
            {
                cntA++;
            }
            else
            {
                mapA[secret[i]]++;
                mapB[guess[i]]++;
            }
        }
        for (auto iter = mapB.begin(); iter != mapB.end(); iter++)
        {
            char key = iter->first;
            int count = iter->second;
            if (mapA[key] > count)
            {
                cntB += count;
            }
            else
            {
                cntB += mapA[key];
            }
        }
        string ret = to_string(cntA) + "A" + to_string(cntB) + "B";
        return ret;
    }
};

// for test
int main()
{
    Solution s;
    string secret = "1807";
    string guess = "7810";
    cout << s.getHint(secret, guess) << endl;

    return 0;
}
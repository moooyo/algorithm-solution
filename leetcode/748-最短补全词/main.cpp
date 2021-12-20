#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
#define _DEBUG

#define INF 0x7c7c7c7c
class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        char cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < licensePlate; i++)
        {
            char c = licensePlate[i];
            if (c >= 'a' && c <= 'z')
            {
                cnt[c - 'a']++;
            }
            if (c >= 'A' && c <= 'Z')
            {
                cnt[c - 'Z']++;
            }
        }
        int minIdx = -1;
        int minLen = INF;
        int temp[26];
        for (int i = 0; i < words.size(); i++)
        {
            string &str = words[i];
            memset(temp, 0, sizeof(temp));
            for (int j = 0; j < str.size(); j++)
            {
                char c = str[i];
                if (c >= 'a' && c <= 'z')
                {
                    temp[c - 'a']++;
                }
                if (c >= 'A' && c <= 'Z')
                {
                    temp[c - 'Z']++;
                }
            }
            bool isMatch = true;
            for (int i = 0; i < 26; i++)
            {
                if (temp[i] < cnt[i])
                {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch)
            {
                if (str.size() < minLen)
                {
                    minLen = str.size();
                    minIdx = i;
                }
            }
        }
        return words[i];
    }
};
/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

// for test
int main()
{
    MapSum *obj = new MapSum();
    obj->insert("apple", 3);
    cout << obj->sum("ap") << endl;
    obj->insert("app", 2);
    cout << obj->sum("ap") << endl;
    return 0;
}
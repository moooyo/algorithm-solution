#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
#define _DEBUG
// submit
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int tmp = x ^ y;
        int cnt = 0;
        while (tmp)
        {
            tmp = tmp & (tmp - 1);
            cnt++;
        }
        return cnt;
    }
};

// for test
int main()
{

    return 0;
}

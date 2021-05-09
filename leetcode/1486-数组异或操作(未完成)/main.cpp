#include <iostream>
using namespace std;
// submit
class Solution
{
public:
    int xorOperation(int n, int start)
    {
        int e = 0;
        if (start % 2 != 0 && n % 2 != 0)
        {
            e = 1;
        }
        int s = start / 2;
        return (f(s + n - 1) ^ f(s - 1)) * 2 + e;
    }
    int f(int x)
    {
        switch (x % 4)
        {
        case 0:
            return x;
        case 1:
            return 1;
        case 2:
            return x + 1;
        case 3:
            return 0;
        }

        return 0;
    }
};

// for test
int main()
{
    Solution s;
    cout << s.xorOperation(5, 0) << endl;
    cout << s.xorOperation(4, 3) << endl;
    cout << s.xorOperation(1, 7) << endl;
    cout << s.xorOperation(10, 5) << endl;
    return 0;
}
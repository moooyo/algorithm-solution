#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
//#define _DEBUG
//#define _DEBUG_1
//#define _DEBUG_2
using namespace std;
class Solution
{
#ifdef _DEBUG
#define MAX 10
#else
#define MAX 101
#endif

public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int preX[MAX][MAX];
        int preY[MAX][MAX];
        memset(preX, 0, sizeof(preX));
        memset(preY, 0, sizeof(preY));
        int len = matrix[0].size();
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < len; j++)
            {
                int num = matrix[i][j];
                int pre = 0;
                if (i - 1 >= 0)
                {
                    pre = preY[i - 1][j];
                }
                preY[i][j] = pre + num;
            }
        }
        for (int j = 0; j < len; j++)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                int num = matrix[i][j];
                int pre = 0;
                if (j - 1 >= 0)
                {
                    pre = preX[i][j - 1];
                }
                preX[i][j] = pre + preY[i][j];
            }
        }

#ifdef _DEBUG
        cout << "preY:" << endl;
        printVector(preY, len);
        cout << "preX:" << endl;
        printVector(preX, len);
#endif

        int ret = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < len; j++)
            {
                for (int lenX = 1; lenX <= i + 1; lenX++)
                {
                    for (int lenY = 1; lenY <= j + 1; lenY++)
                    {
                        int sub1, sub2, add1;
                        sub1 = sub2 = add1 = 0;
                        if (i - lenX >= 0)
                        {
                            sub1 = preX[i - lenX][j];
                        }
                        if (j - lenY >= 0)
                        {
                            sub2 = preX[i][j - lenY];
                        }
                        if (i - lenX >= 0 && j - lenY >= 0)
                        {
                            add1 = preX[i - lenX][j - lenY];
                        }
                        int sum = preX[i][j] - sub1 - sub2 + add1;
#ifdef _DEBUG
                        cout << "i: " << i << " j: " << j << " lenX: " << lenX << " lenY: " << lenY << " sum: " << sum << endl;
#endif
                        if (sum == target)
                        {
                            ret++;
                        }
                    }
                }
            }
        }
        return ret;
    }
    int min(int a, int b)
    {
        if (a < b)
        {
            return a;
        }
        return b;
    }
    int max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        return b;
    }
    void printVector(int a[][MAX], int len)
    {
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// for test
int main()
{
    Solution s;
    vector<vector<int>> test1 = {{0, 1, 0},
                                 {1, 1, 1},
                                 {0, 1, 0}};
    vector<vector<int>> test2 = {{1, -1}, {-1, 1}};
    vector<vector<int>> test3 = {{904}};
    cout << s.numSubmatrixSumTarget(test1, 0) << endl;
    cout << s.numSubmatrixSumTarget(test2, 0) << endl;
    cout << s.numSubmatrixSumTarget(test3, 0) << endl;

    return 0;
}
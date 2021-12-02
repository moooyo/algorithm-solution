#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <unordered_map>
using namespace std;
#define _DEBUG
class Solution
{
public:
    int matrixM;
    int matrixN;
    //int *matrixPoint;
    //vector<int> matrixPoint;
    unordered_map<int, int> matrixPoint;
    int size;
    int convertToPointX(int num)
    {
        return num % matrixM;
    }
    int convertToPointY(int num)
    {
        return num / matrixM;
    }

    void reInit(int num)
    {
        matrixPoint.clear();
        size = num;
    }
    void swap(int i, int j)
    {
        if (matrixPoint.count(i) == 0)
        {
            matrixPoint[i] = i;
        }
        if (matrixPoint.count(j) == 0)
        {
            matrixPoint[j] = j;
        }
        int temp = matrixPoint[i];
        matrixPoint[i] = matrixPoint[j];
        matrixPoint[j] = temp;
    }

    Solution(int m, int n)
    {
        matrixM = m;
        matrixN = n;
        srand(time(NULL));
        reInit(m * n);
    }

    vector<int> flip()
    {
        int idx = rand() % size;
        int rd = matrixPoint[idx];
        if (rd == 0)
        {
            rd = idx;
        }

        swap(size - 1, idx);
        size--;
        int x = convertToPointX(rd);
        int y = convertToPointY(rd);
        return vector<int>{x, y};
    }

    void reset()
    {
        reInit(matrixM * matrixN);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
// for test
int main()
{
    Solution s(3, 1);
    auto x1 = s.flip();
    auto x2 = s.flip();
    auto x3 = s.flip();
    s.reset();
    auto x4 = s.flip();
    cout << x1[0] << " " << x1[1] << endl;
    cout << x2[0] << " " << x2[1] << endl;
    cout << x3[0] << " " << x3[1] << endl;
    cout << x4[0] << " " << x4[1] << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define _DEBUG

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int len = arr.size();
        return find(0, len, arr);
    }
    int find(int left, int right, vector<int> &arr)
    {
#ifdef _DEBUG
        cout << "left: " << left << " right: " << right << endl;
#endif
        if (left >= right)
        {
            return -1;
        }
        if (right - left <= 2)
        {
            return -1;
        }
        int mid = (left + right) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1])
        {
            return find(mid, right, arr);
        }
        else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1])
        {
            return find(left, mid + 1, arr);
        }
        else if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        return -1;
    }
};

// for test
int main()
{
    Solution s;
    vector<int> t1{0, 1, 0};
    cout << s.peakIndexInMountainArray(t1) << endl;

    vector<int> t2{0, 10, 5, 2};
    cout << s.peakIndexInMountainArray(t2) << endl;

    vector<int> t3{24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
    cout << s.peakIndexInMountainArray(t3) << endl;

    vector<int> t4{3, 4, 5, 1};
    cout << s.peakIndexInMountainArray(t4) << endl;

    return 0;
}
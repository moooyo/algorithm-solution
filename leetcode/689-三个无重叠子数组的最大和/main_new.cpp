#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <unordered_map>
#include <utility>
using namespace std;
/* #define DEBUG */

#define MAXLEN 20004

typedef struct Node
{
    int sum;
    int startIdx;
} Node;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};
class Solution
{
public:
    int sum[MAXLEN];
    unordered_map<pair<int, int>, Node, pair_hash> umap;
    int maxSubSum(int start, int end, int k, int &maxSum)
    {
        pair<int, int> before{start, end - 1};
        pair<int, int> now{start, end};
        if (umap.count(before) == 1)
        {
            int nowSum = sum[end] - sum[end - k];
            if (nowSum > umap[before].sum)
            {
                umap[now] = Node{
                    sum : nowSum,
                    startIdx : end - k,
                };
                maxSum = nowSum;
                return end - k;
            }
            else
            {
                maxSum = umap[before].sum;
                return umap[before].startIdx;
            }
        }

        maxSum = 0;
        int idx = -1;
        for (int i = start; i < end; i++)
        {
            if (i + k - 1 > end)
            {
                break;
            }
            int nowSum = sum[i + k - 1] - sum[i - 1];
            if (nowSum > maxSum)
            {
                maxSum = nowSum;
                idx = i;
            }
        }
        umap[now] = Node{
            sum : maxSum,
            startIdx : idx - 1,
        };

        return idx - 1;
    }

    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int len = nums.size();
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= len; i++)
        {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        umap.clear();

        int maxSum = 0;
        vector<int> ret;
#ifdef DEBUG
        cout << "start calculate" << endl;
#endif

        for (int i = k + 1; i < len; i++)
        {
            for (int j = i + k; j < len; j++)
            {
                vector<int> idx{0, 0, 0};
                if (j + k > len + 1)
                {
                    break;
                }
                int maxSum1 = 0;
                int maxSum2 = 0;
                int maxSum3 = 0;
                idx[0] = maxSubSum(1, i - 1, k, maxSum1);
                idx[1] = maxSubSum(i, j - 1, k, maxSum2);
                idx[2] = maxSubSum(j, len, k, maxSum3);
#ifdef DEBUG
                cout << "i: " << i << " j: " << j << " sum1:" << maxSum1 << " sum2: " << maxSum2 << " sum3: " << maxSum3 << endl;
#endif
                if (maxSum1 + maxSum2 + maxSum3 > maxSum)
                {
                    maxSum = maxSum1 + maxSum2 + maxSum3;
                    ret = idx;
                }
            }
        }
        return ret;
    }
};

void printVector(vector<int> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

// for test
int main()
{
    Solution s;
    vector<int> test1{1, 2, 1, 2, 6, 7, 5, 1};
    vector<int> test2{1, 2, 1, 2, 1, 2, 1, 2, 1};
    vector<int> test3{7, 13, 20, 19, 19, 2, 10, 1, 1, 19};

    printVector(s.maxSumOfThreeSubarrays(test1, 2));
    printVector(s.maxSumOfThreeSubarrays(test2, 2));
    printVector(s.maxSumOfThreeSubarrays(test3, 3));
    return 0;
}
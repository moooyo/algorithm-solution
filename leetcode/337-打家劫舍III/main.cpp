#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <unordered_map>
using namespace std;
/* #define _DEBUG */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    unordered_map<TreeNode *, int> umap1;
    unordered_map<TreeNode *, int> umap2;
    int dfs(TreeNode *now, bool parentChoose)
    {
        if (now == nullptr)
        {
            return 0;
        }

        int ret1 = 0;
        if (!parentChoose)
        {
            if (umap1.count(now) != 0)
            {
                ret1 = umap1[now];
            }
            else
            {
                ret1 = dfs(now->left, true) + dfs(now->right, true) + now->val;
                umap1[now] = ret1;
            }
        }

        int ret2 = 0;
        if (umap2.count(now) != 0)
        {
            ret2 = umap2[now];
        }
        else
        {
            ret2 = dfs(now->left, false) + dfs(now->right, false);
            umap2[now] = ret2;
        }

        return ret1 > ret2 ? ret1 : ret2;
    }
    int rob(TreeNode *root)
    {
        umap1.clear();
        umap2.clear();
        int answer1 = dfs(root, true);
        int answer2 = dfs(root, false);
        return answer1 > answer2 ? answer1 : answer2;
    }
};

// for test
int main()
{
    Solution s;
    vector<string> test1{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << s.maxProduct(test1) << endl;

    return 0;
}
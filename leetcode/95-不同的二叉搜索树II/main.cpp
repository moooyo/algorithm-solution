#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
#define DEBUG

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
    unordered_set<int> ust;
    vector<TreeNode *> ret;
    TreeNode *root;
    void dfs(TreeNode *parent, TreeNode *now, int target)
    {
        if (ust.size() == 0)
        {
            // 所有值都用掉了
            ret.push_back(root);
            return;
        }
        // 左边选点 右边不选点
        int val = now->val;
        for (int i = 1; i < val; i++)
        {
            if (ust.count(i) == 0)
            {
                ust.insert(i);
                
            }
        }

        // 到此为止，不选点了
        return;
    }
    vector<TreeNode *> generateTrees(int n)
    {
    }
};
// for test
int main()
{
    Solution s;

    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    cout << s.isInterleave("", "", "") << endl;
    cout << s.isInterleave("", "b", "b") << endl;
    return 0;
}
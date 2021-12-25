#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#define _DEBUG
using namespace std;
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
typedef struct NodeInfo
{
    struct TreeNode *node;
    int level;
    NodeInfo()
    {
    }
    NodeInfo(struct TreeNode *a, int lv)
    {
        this->node = a;
        this->level = lv;
    }
} NodeInfo;

class Solution
{
public:
    bool isEvenOddTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        queue<NodeInfo> q;
        q.push(NodeInfo(root, 0));
        int preVal = -1;
        int preLv = -1;
        while (!q.empty())
        {
            auto info = q.front();
            q.pop();
            if (info.level % 2 == info.node->val % 2)
            {
                cout << "1" << endl;
                return false;
            }
            if (info.level != preLv)
            {
                preLv = info.level;
                preVal = info.node->val;
            }
            else
            {
                if (info.level % 2 == 0)
                {
                    if (info.node->val <= preVal)
                    {
                        return false;
                    }
                }
                else
                {
                    if (info.node->val >= preVal)
                    {
                        return false;
                    }
                }
                preVal = info.node->val;
            }
            if (info.node->left != nullptr)
            {
                q.push(NodeInfo(info.node->left, info.level + 1));
            }
            if (info.node->right != nullptr)
            {
                q.push(NodeInfo(info.node->right, info.level + 1));
            }
        }
        return true;
    }
};
// for test
int main()
{
    Solution s;

    return 0;
}
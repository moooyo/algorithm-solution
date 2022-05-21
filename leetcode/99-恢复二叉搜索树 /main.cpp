#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <climits>
#include <unordered_map>
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
    TreeNode *preNode;
    bool success;
    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    void iterTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        iterTree(root->left);
        if (preNode != nullptr)
        {
            if (root->val < preNode->val)
            {
                success = false;
                swap(preNode->val, root->val);
                return;
            }
        }

        preNode = root;

        iterTree(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        preNode = nullptr;
        while (true)
        {
            success = true;
            iterTree(root);
            if (success)
            {
                break;
            }
        }
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
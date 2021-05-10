#include <iostream>
#include <vector>
//#define _DEBUG
using namespace std;
// submit
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
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1, v2;
        solve(root1, v1);
        solve(root2, v2);
#ifdef _DEBUG
        for (int i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < v2.size(); i++)
        {
            cout << v2[i] << " ";
        }
        cout << endl;
#endif
        int length = v1.size();
        if (length != v2.size())
        {
            return false;
        }
        for (int i = 0; i < length; i++)
        {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    }
    void solve(TreeNode *root, vector<int> &ret)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL && root->right == NULL)
        {
            ret.push_back(root->val);
            return;
        }
        solve(root->left, ret);
        solve(root->right, ret);
    }
};

// for test
int main()
{
    Solution s;

    return 0;
}
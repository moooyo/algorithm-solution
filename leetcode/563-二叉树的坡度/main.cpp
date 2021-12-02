#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
#define _DEBUG
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
    int sum(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return root->val + sum(root->left) + sum(root->right);
    }

    int findTilt(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = sum(root->left);
        int right = sum(root->right);
        int diff = left - right;
        if (diff < 0)
        {
            diff = diff * -1;
        }
        return diff + findTilt(root->left) + findTilt(root->right);
    }
};

// for test
int main()
{
    Solution s;
    vector<int> nums1{0, 1};
    cout << s.findMaxLength(nums1) << endl;
    vector<int> nums2{0, 1, 0};
    cout << s.findMaxLength(nums2) << endl;
    return 0;
}
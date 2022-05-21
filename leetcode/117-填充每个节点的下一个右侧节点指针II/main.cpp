#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
/* #define _DEBUG */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    void dfs(Node *node, Node *rootRight)
    {
        if (node == nullptr)
        {
            return;
        }
        node->next = rootRight;

        if (node->right != nullptr)
        {
            Node *right = nullptr;
            Node *next = rootRight;
            while (next != nullptr && right == nullptr)
            {
                if (next->left != nullptr)
                {
                    right = next->left;
                }
                else if (next->right != nullptr)
                {
                    right = next->right;
                }
                next = next->next;
            }
            dfs(node->right, right);
        }

        if (node->left != nullptr)
        {
            // find right;
            Node *right = nullptr;
            if (node->right != nullptr)
            {
                right = node->right;
            }
            Node *next = rootRight;
            while (next != nullptr && right == nullptr)
            {
                if (next->left != nullptr)
                {
                    right = next->left;
                }
                else if (next->right != nullptr)
                {
                    right = next->right;
                }
                next = next->next;
            }
            dfs(node->left, right);
        }
    }
    Node *connect(Node *root)
    {
        dfs(root, nullptr);
        return root;
    }
};
// for test
int main()
{
    Solution s;
    vector<vector<int>> test{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << s.minimumTotal(test) << endl;
    vector<vector<int>> test2{{-10}};
    cout << s.minimumTotal(test2) << endl;
    return 0;
}
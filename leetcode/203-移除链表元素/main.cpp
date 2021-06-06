#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;

#define _NDEBUG
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *ret = head;
        ListNode *now = head;
        ListNode *pre = NULL;
        while (now != NULL)
        {
            int nowVal = now->val;
            if (nowVal == val)
            {
                if (pre != NULL)
                {
                    pre->next = now->next;
                }
                if (now == ret)
                {
                    ret = ret->next;
                }
            }
            else
            {
                pre = now;
            }
            now = now->next;
        }
        return ret;
    }
};

// for test
int main()
{
    Solution s;

    return 0;
}
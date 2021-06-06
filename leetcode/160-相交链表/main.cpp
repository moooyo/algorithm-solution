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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        bool switchA, switchB;
        switchA = switchB = false;
        if (p1 == NULL || p2 == NULL)
        {
            return NULL;
        }
        while (p1 != NULL || p2 != NULL)
        {
            if (p1 == p2)
            {
                return p1;
            }
            if (p1 == NULL)
            {
                if (switchA)
                {
                    p1 = headA;
                }
                else
                {
                    p1 = headB;
                }
                switchA = !switchA;
            }
            else
            {
                p1 = p1->next;
            }
            if (p2 == NULL)
            {
                if (switchB)
                {
                    p2 = headB;
                }
                else
                {
                    p2 = headA;
                }
                switchB = !switchB;
            }
            else
            {
                p2 = p2->next;
            }
        }
        return NULL;
    }
};

// for test
int main()
{
    Solution s;

    return 0;
}
// Leetcode 456
#include <algorithm>
#include <stack>
#include <stdio.h>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* H = new ListNode();
    H->next = head;
    ListNode* pre = H;
    ListNode* cur = head;
    while(pre!=nullptr){
        cur=pre->next;
        if(cur!=nullptr && cur->next!=nullptr && cur->val==cur->next->val){
            ListNode* next = cur->next;
            while(next!=nullptr && next->val==cur->val){
                next = next->next;
            }
            pre->next = next;
        }else{
            pre=cur;
        }
    }
    return H->next;
}

int main(void)
{
    return 0;
}

#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

pair<ListNode*,ListNode*> reverse(ListNode* head,ListNode *tail)
{
    ListNode *prev = nullptr;
    ListNode *cur = head;
    ListNode *tmp;
    while (prev != tail)
    {
        tmp = cur->next;
        cur->next = prev;

        prev = cur;
        cur = tmp;
    }

    return {tail, head};
}

ListNode* reverseKGroup(ListNode* head, int k) 
{
    ListNode *help = new ListNode(0);
    help->next = head;
    ListNode *tail,*prev,*next;
    prev = help;
    while (head)
    {
        tail = prev;
        for (int i = 0; i < k; ++i)
        {
            tail = tail->next;
            if(tail==nullptr){
                head = help->next;
                delete help;
                return head;
            }
        }
        next = tail->next;
        tie(head, tail) = reverse(head, tail);
        prev->next = head;
        tail->next = next;
        prev = tail;
        head = tail->next;
    }

    head = help->next;
    delete help;
    return head;
}

int main(int argc, char const *argv[])
{
 
    return 0;
}

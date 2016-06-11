/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)return head;
        ListNode * tmp = head->next;
        ListNode *prenode = head;
        while(tmp!=NULL)
        {  
            ListNode *nextnode = tmp->next;
            tmp->next = prenode;
            prenode = tmp;
            tmp = nextnode;
         }
         head->next = NULL;
         head = prenode;
         return head;
    }
};
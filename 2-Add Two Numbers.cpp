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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode(0);
        ListNode * beg = head;
        int pre=0;
        while(l1!=NULL||l2!=NULL){
            if(l1!=NULL&&l2!=NULL){
                head->val = head->val+l1->val+l2->val;
                pre = head->val/10;
                head->val = (head->val)%10;
                l1 = l1->next;
                l2 = l2->next;
                if(l1==NULL&&l2==NULL&&pre==0)head->next = NULL;
                else head->next = new ListNode(pre);
                head = head->next;
            }
            else if(l1!=NULL&&l2==NULL){
                head->val = head->val+l1->val;
                pre = head->val/10;
                head->val = (head->val)%10;
                l1 = l1->next;
                if(l1==NULL&&pre==0)head->next = NULL;
                else head->next = new ListNode(pre);
                head = head->next;
            }
            else if(l1==NULL&&l2!=NULL)
            {
                head->val = head->val+l2->val;
                pre = head->val/10;
                head->val = (head->val)%10;
                l2 = l2->next;
                if(l2==NULL&&pre==0)head->next = NULL;
                else head->next = new ListNode(pre);
                head = head->next;
            }
            else{
                head->val = pre;
                return beg;
            }
        }
        return beg;
    }
};
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *fir=head,*sec=head;
        ListNode *tmp=head;
        int len=0;
        while(tmp!=NULL)++len,tmp=tmp->next;//计算链表长度
        if(len==0)return head;  //如果长度为0，返回来保证下面求余不为0
        k = k%len;                
        if(k==0)return head;     //k为rotate的长度，为本身
        while(k--&&sec!=NULL)sec = sec->next;  //让sec先走k步
        while(sec->next!=NULL){            //同时走，直到sec是最后一个节点，fir是倒数第k个节点的前一个节点
            fir=fir->next;
            sec=sec->next;
        }
        sec->next = head; //两段链表链接起来
        head = fir->next;
        fir->next = NULL;
        return head;
    }
};
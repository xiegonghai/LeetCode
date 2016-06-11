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
        while(tmp!=NULL)++len,tmp=tmp->next;//����������
        if(len==0)return head;  //�������Ϊ0����������֤�������಻Ϊ0
        k = k%len;                
        if(k==0)return head;     //kΪrotate�ĳ��ȣ�Ϊ����
        while(k--&&sec!=NULL)sec = sec->next;  //��sec����k��
        while(sec->next!=NULL){            //ͬʱ�ߣ�ֱ��sec�����һ���ڵ㣬fir�ǵ�����k���ڵ��ǰһ���ڵ�
            fir=fir->next;
            sec=sec->next;
        }
        sec->next = head; //����������������
        head = fir->next;
        fir->next = NULL;
        return head;
    }
};
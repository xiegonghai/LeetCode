#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#define IMIN numeric_limits<int>::min()
#define IMAX numeric_limits<int>::max()
#define FR(i,n) for(int i=0;i<n;i++)
#define CLC(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define viter vector<int>::const_iterator
#define vcter vector<int>::const_iterator

using namespace std;
#include <time.h>
#include <sys/timeb.h>

int get_time(string r)
{
    struct timeb rawtime;
    ftime(&rawtime);
    static int ms = rawtime.millitm;
    static unsigned long s = rawtime.time;
    int out_ms = rawtime.millitm - ms;
    unsigned long out_s = rawtime.time - s;
    if (out_ms < 0)
    {
        out_ms += 1000;
        out_s -= 1;
    }
    ms = rawtime.millitm;
    s = rawtime.time;
    int total = 1000*out_s+out_ms;
    cout<<r<<": "<<total<<"ms"<<endl;
    return total;
}
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==1)return head;
        ListNode *fir=head,*sec=head,*pre_fir=NULL,*pre_sec=NULL;
        int finished=0;
        int count=1;
        while(!finished){
            int i=1;
            while(i++<k&&sec!=NULL){sec=sec->next;} //fir.....sec���ܵ�K��Ԫ��
            ListNode *sec_next=(sec==NULL)?NULL:sec->next;
            if((i-1)==k&&(sec!=NULL)){          //ע�⣬ֻ�е�����k�������һ���ҵ���(��Ϊ�գ��Ž������Ԫ��ԭ����ת
                ListNode *tmp = fir->next;   //��תʱ�ĵ�ǰԪ��
                ListNode *prenode = fir;   //��תʱ������ǰһԪ��
                while(tmp!=sec_next) //��ǰԪ��û��secĩβԪ�أ�
                {  
                    ListNode *nextnode = (tmp->next); //���浱ǰԪ�ص���һԪ��
                    tmp->next = prenode;          //��ǰԪ��ָ��ǰһ��Ԫ��
                    prenode = tmp;                //ǰһԪ������
                    tmp = nextnode;               //��ǰԪ������
                 }
                 fir->next = NULL;         //��һ�ε���Ԫ�ر��ĩβԪ�ء�
                 if(pre_fir!=NULL){pre_fir->next = prenode;pre_fir = fir;}//pre_fir��һ����ת���ĩβָ��ǰ����ת��Ŀ�ͷ
                 else {head = prenode;pre_fir=fir;}//��Ե�һ��ǰһ�ε���תǰ��Ϊ��
                 fir = sec_next;  //��ʼ��һ��Ԫ����ת��sec_next������һ��sec����һԪ��
                 sec = fir;      //��sec��Ϊfirһ����ֵ����ʼ��ת���̡�
            }
            else {
                    finished = 1;
                    if(pre_fir!=NULL)pre_fir->next = fir;
            }
        }
        return head;
    }
};
int main()
{
     Solution s;
     get_time("begin");
     ListNode l(1),l1(2),l2(3);
     l.next = &l1;
     l1.next= &l2;
     //ListNode *head = &l;
    // while(head!=NULL)cout<<head->val<<" ",head = head->next;
     //cout<<l.next->next->val<<endl;
      ListNode *head=s.reverseKGroup(&l,2);
     while(head!=NULL)cout<<head->val<<" ",head = head->next;
     get_time("end");
     return 0;
}

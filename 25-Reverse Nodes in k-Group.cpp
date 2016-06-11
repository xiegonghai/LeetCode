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
            while(i++<k&&sec!=NULL){sec=sec->next;} //fir.....sec段总的K个元素
            ListNode *sec_next=(sec==NULL)?NULL:sec->next;
            if((i-1)==k&&(sec!=NULL)){          //注意，只有当找了k次且最后一次找到了(不为空）才进行这段元素原地逆转
                ListNode *tmp = fir->next;   //逆转时的当前元素
                ListNode *prenode = fir;   //逆转时保留的前一元素
                while(tmp!=sec_next) //当前元素没到sec末尾元素，
                {  
                    ListNode *nextnode = (tmp->next); //保存当前元素的下一元素
                    tmp->next = prenode;          //当前元素指向前一个元素
                    prenode = tmp;                //前一元素右移
                    tmp = nextnode;               //当前元素右移
                 }
                 fir->next = NULL;         //第一段的首元素变成末尾元素。
                 if(pre_fir!=NULL){pre_fir->next = prenode;pre_fir = fir;}//pre_fir上一段逆转后的末尾指向当前的逆转后的开头
                 else {head = prenode;pre_fir=fir;}//针对第一次前一段的逆转前的为空
                 fir = sec_next;  //开始下一段元素逆转，sec_next保存上一段sec的下一元素
                 sec = fir;      //将sec置为fir一样的值，开始逆转流程。
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

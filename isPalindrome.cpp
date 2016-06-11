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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)return true;
        int len=0;
        ListNode *p =head;
        while(p!=NULL){
            len++;
            p=p->next;
        }
        if(len==2)return head->next->val==head->val; //因为逆转的时候是针对大于等于2（2*2就是4）的情况来考虑，所以先处理小于4 
        if(len==3)return head->val==head->next->next->val;
        int i=1;
        ListNode *fir=head,*sec=head;
        while(i++<len/2)fir=fir->next;
        if(len%2==0)sec = fir->next;
        else sec = fir->next->next;
        if(len>=4){          //逆转前半部分 
            ListNode *pre_next = fir->next;
            ListNode *tmp=head->next,*pretmp = head;
            while(tmp!=NULL&&tmp!=pre_next){ 
                ListNode *tmpnext = tmp->next;
                tmp->next = pretmp;
                pretmp = tmp;
                tmp=tmpnext;
            }
            head->next=NULL;
        }
        while(fir!=NULL){  //从中间出发判断回文 
            if(fir->val!=sec->val)return false;
            fir = fir->next;
            sec = sec->next;
        }
        return true;
    }
};
int main()
{
     Solution s;
     get_time("begin");
     ListNode l1(1),l2(2),l3(2),l4(1);
     l1.next = &l2;
     l2.next = &l3;
     l3.next = &l4;
     cout<<s.isPalindrome(&l1)<<endl;
     get_time("end");
     return 0;
}


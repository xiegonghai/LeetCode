#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <string.h>
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
/*******************************************
�ֶ�������Ȼ�����������������
���ö��ֲ����㷨��ֻ��ÿ��ȷ��Ŀ��ֵ
��������ʱҪ��һ���ж϶��� 
ʱ�临�Ӷȣ�O(logn)
�ռ䣺O(1) 
*********************************************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int beg = 0,end = n-1;
        while(beg<end){
            int mid = (beg+end)/2;
            if(nums[mid]==target)return mid; //�պ��ҵ����� 
            else if(nums[mid]<target){       //���Ŀ��ֵ�����м�ֵ�����ڱ��м�ֵ��������� 
                if(nums[mid]>=nums[beg]) beg = mid+1; 
                else if(nums[mid]<nums[beg]){
                	if(nums[end]>=target)beg = mid+1;
                	else end = mid -1;
                } 
            }
            else if(nums[mid]>target){     //���Ŀ��ֵС���м�ֵ�����ڱ��м�ֵС�������� 
                if(nums[mid]>=nums[beg]){
                	if(nums[beg]<=target)end = mid-1;
                	else beg = mid+1;
                } 
                else if(nums[mid]<nums[beg])end = mid-1;  
            }
        }
        if(beg==end&&nums[beg]==target)return beg; 
        else return -1;
    }
};
int main()
{
     Solution s;
     get_time("begin");
     int a[]={1,3};
     vector<int> res(a,a+2);
     cout<<s.search(res,0)<<endl;
     get_time("end");
     return 0;
}


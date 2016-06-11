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
分段有序，依然可以利用有序的性质
利用二分查找算法，只是每次确定目标值
所在区间时要多一点判断而已 
时间复杂度：O(logn)
空间：O(1) 
*********************************************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int beg = 0,end = n-1;
        while(beg<end){
            int mid = (beg+end)/2;
            if(nums[mid]==target)return mid; //刚好找到返回 
            else if(nums[mid]<target){       //如果目标值大于中间值，则在比中间值大的区域找 
                if(nums[mid]>=nums[beg]) beg = mid+1; 
                else if(nums[mid]<nums[beg]){
                	if(nums[end]>=target)beg = mid+1;
                	else end = mid -1;
                } 
            }
            else if(nums[mid]>target){     //如果目标值小于中间值，则在比中间值小的区域找 
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


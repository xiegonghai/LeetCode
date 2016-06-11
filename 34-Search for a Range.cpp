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
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int beg = 0,end = n-1;
        int mid;
        while(beg<=end){  //���ֲ���Ŀ��Ԫ�� 
        	mid = (beg+end)/2;
        	if(nums[mid]>target)end = mid-1;
        	else if(nums[mid]<target)beg = mid+1;
        	else break;
        }
        vector<int> res(2,-1);
        cout<<"mid:"<<mid<<" "<<nums[mid]<<endl;
        if(nums[mid]==target){    //�ҵ��� 
            beg =0,end = n-1;
        	int fir=mid,sec=mid;
        	while(sec<=end&&nums[sec]==target)++sec;  //���ұ���չ 
        	while(fir>=0&&nums[fir]==target)--fir;    //�������չ 
        	res[0]=fir+1;res[1]=sec-1;                //ȷ������λ�� 
        }
		return res;                  
    }
};
int main()
{
     Solution s;
     get_time("begin");
     int a[]={5,7,7,7,8,8,10};
     vector<int> vec(a,a+7);
     vector<int> res= s.searchRange(vec,7);
     typedef ostream_iterator<int> OstreamItr;
	 copy(res.begin(), res.end(), OstreamItr(cout, " "));
	 cout<<endl;
     get_time("end");
     return 0;
}

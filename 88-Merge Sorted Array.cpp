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
#include<assert.h>
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	//assert(m>=0&&n>=0);
		if(m!=0&&n==0)return;
        if(m==0&&n!=0){nums1=nums2;return;}
        if(m==0&&n==0){nums1.clear();return;}
        int i,j=0;
        vector<int> res;
        while(i<m&&j<n){
            if(nums1[i]<nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }
            else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        if(i<m){
            for(int k=i;k<m;++k)res.push_back(nums1[k]);
        }
        else if(j<n){
            for(int y=j;y<n;++y)res.push_back(nums2[y]);
        }
        nums1=res;
    }
     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     	int ia=m-1,ib=n-1,icur = m+n-1;
     	while(ia>=0&&ib>=0){
	     	nums1[icur--]=nums1[ia]>=nums2[ib]?nums1[ia--]:nums2[ib--];
	     }
	     while(ib>=0){
     		nums1[icur--]=nums2[ib--];
     	}
     }
};
int main()
{
     Solution s;
     get_time("begin");
     vector<int> a={1,6,8,9,10,11};
     vector<int> b={2};
      s.merge2(a,6,b,1);
      typedef ostream_iterator<int> OstreamItr;
      copy(a.begin(), a.end(), OstreamItr(cout, " "));
     get_time("end");
     return 0;
}

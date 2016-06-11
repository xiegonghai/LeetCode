#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include<utility>
#include<unordered_map>
#define IMIN numeric_limits<int>::min()
#define IMAX numeric_limits<int>::max()
#define FR(i,n) for(int i=0;i<n;i++)
#define CLC(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define viter vector<int>::const_iterator
#include<iterator>
using namespace std;
typedef ostream_iterator<int> OstreamItr; 
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.size()<3)return res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<nums.size()-1;++i){
			if(i!=0&&nums[i]==nums[i-1])continue;
			int beg = i+1,end = n-1;
			while(beg<end){
				vector<int> tmp;
				int sum2 = nums[beg]+nums[end];
				if(sum2==-nums[i]){
				    tmp.push_back(nums[i]);
					tmp.push_back(nums[beg]);
					tmp.push_back(nums[end]);
					res.push_back(tmp);
					while(++beg<end&&nums[beg-1]==nums[beg]);
					while(--end>beg&&nums[end]==nums[end+1]);
				}
				else{
					if(sum2<-nums[i])++beg;
					else --end;
				}
			}
        }
        return res;
    }
};

int main()
{
	 Solution s;
	 vector<int> nums;
	 int a[]={0,8,2,-9,-14,5,2,-5,-5,-9,-1,3,1,-8,0,-3,-12,2,11,9,13,-14,2,-15,4,10,9,7,14,-8,-2,-1,-15,-15,-2,8,-3,7,-12,8,6,2,-12,-8,1,-4,-3,5,13,-7,-1,11,-13,8,4,6,3,-2,-2,3,-2,3,9,-10,-4,-8,14,8,7,9,1,-2,-3,5,5,5,8,9,-5,6,-12,1,-5,12,-6,14,3,5,-11,8,-7,2,-12,9,8,-1,9,-1,-7,1,-7,1,14,-3,13,-4,-12,6,-9,-10,-10,-14,7,0,13,8,-9,1,-2,-5,-14};
	 int a1[]={
 		-4,-8,7,13,10,1,-14,-13,0,8,6,-13,-5,-4,-12,2,-11,7,-5,0,-9,-14,-8,-9,2,-7,-13,-3,13,9,-14,-6,8,1,14,-5,-13,8,-10,-5,1,11,-11,3,14,-8,-10,-12,6,-8,-5,13,-15,2,11,-5,10,6,-1,1,0,0,2,-7,8,-6,3,3,-13,8,5,-5,-3,9,5,-4,-14,11,-8,7,10,-6,-3,11,12,-14,-9,-1,7,5,-15,14,12,-5,-8,-2,4,2,-14,-2,-12,6,8,0,0,-2,3,-7,-14,2,7,12,12,12,0,9,13,-2,-15,-3,10,-14,-4,7,-12,3,-10
 	};
	 nums.resize(sizeof(a1)/sizeof(int));
	 copy(a1,a1+sizeof(a1)/sizeof(int),nums.begin());
	 get_time("begin");
	 vector<vector<int> > res=s.threeSum(nums);
	 get_time("end");
	 for(vector<int> myvector:res)
     {
	    copy(myvector.begin(), myvector.end(), OstreamItr(cout, " "));
		cout<<endl;  
     }
     return 0;
}

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
#define IMAX numeric_limits<int>::max()
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        size_t n = nums.size();
        sort(nums.begin(),nums.end());
        int best_sum=0,error=IMAX;
        for(int i=0;i<n;++i){
            int beg = i+1,end = n-1;
            while(beg<end){
                int tsum =nums[i]+nums[beg]+nums[end];
                if(tsum==target) {
                        best_sum = tsum;
                        while(++beg<end&&nums[beg]==nums[beg-1]);
                        while(--end>beg&&nums[end]==nums[end]);
                }
                else{
                        if(tsum<target)beg++;
                        else end--;
                }
                if(abs(target-tsum)<error){
                        error = abs(target-tsum);
                        best_sum = tsum;
                }
            }
        }
        return best_sum;
    }
};    
int main()
{
	int a[]={
		0,1,2
	};
	vector<int> vec(a,a+sizeof(a)/sizeof(int));
	Solution s;
	cout<<s.threeSumClosest(vec,0);
     return 0;
}


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
#include<iterator>
typedef ostream_iterator<int> OstreamItr;


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
void perm(vector<int>& nums,int k, int m,vector<vector<int>> &res)
{
	int i;
	if(k >m)res.push_back(nums);
	else{
		for(i = k ; i <=m;i++){
			swap(nums[k],nums[i]);
			perm(nums,k+1,m,res);
			swap(nums[i],nums[k]);
		}
	}
}
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        //sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        long long NN=1;
        for(int i=1;i<=n;++i)NN=NN*i;
        long long j=0;
        while(j++<NN){
            res.push_back(nums);
            nextPermutation(nums);
        }
        return res;
    }
    void nextPermutation(vector<int>& nums) {
        const auto rbeg = nums.rbegin();
        const auto rend = nums.rend();
        auto pivot = next(rbeg);
        while(pivot!=rend && *pivot>=*prev(pivot))++pivot;
        if(pivot==rend){
            reverse(rbeg,rend);
            return;
        }
        auto bigger = find_if(rbeg,pivot,bind1st(less<int>(),*pivot));
        swap(*pivot,*bigger);
        reverse(rbeg,pivot);
    }
};
int main()
{
     get_time("begin");
     int a[]={
     1,1,1,2
     };
     //for(int i=1;i<=3;++i)a[i-1]=i;
     vector<int> nums(a,a+sizeof(a)/4);
     vector<int> vec = nums;
     vector<vector<int>> res,res2;
     perm(nums,0,nums.size()-1,res);
     Solution s;
     res2=s.permute(vec);
     for(int i=0;i<res.size();++i){
     		copy(res[i].begin(), res[i].end(), OstreamItr(cout, " "));
	     	cout<<endl;
     }
     res = res2;
     cout<<"not recursive:"<<endl;
     for(int i=0;i<res.size();++i){
     		copy(res[i].begin(), res[i].end(), OstreamItr(cout, " "));
	     	cout<<endl;
     }
     get_time("end");
     return 0;
}

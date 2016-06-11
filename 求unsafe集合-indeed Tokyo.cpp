#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <string.h>
#include <set>
using namespace std;
class Solution {
public:
	vector<string> output_unsafe(string &s){
		int n = s.size();
		set<string> res;
		vector<string> result;
		string sub="abcd",strtmp;
		for(int i=0;i<n;++i){
			for(int j=0;j<4;++j){
				swap(s[i],sub[j]);
				//strtmp.assign(s.rbegin(),s.rend());
				if(res.find(s)==res.end())
					perm(s,0,s.size()-1,res);
				swap(s[i],sub[j]);
			}
		}
		auto it = res.begin();
		while(it!=res.end()) {
			result.push_back(*it);
			it++;
		}
		return result;
	}	
	void perm(string &nums,int k, int m,set<string> &res)
	{
    	int i;
    	if(k >m){
			if(res.find(nums)==res.end())res.insert(nums);
    	}
    	else{
	        for(i = k ; i <=m;i++){
	            swap(nums[k],nums[i]);//首元素与后续元素依次交换
	            perm(nums,k+1,m,res); //求除首元素外子集序列
	            swap(nums[i],nums[k]);//换回去
	        }
    	}
	}
};
int main()
{
     Solution s;
     vector<string> res;
     set<string> res1;
     //get_time("begin");
     string str;
     cin>>str;
     res=s.output_unsafe(str);
    // s.perm(str,0,str.size()-1,res1);
     typedef ostream_iterator<string> OstreamItr;
     copy(res.begin(), res.end(), OstreamItr(cout, "\n"));
     //get_time("end");
     return 0;
}

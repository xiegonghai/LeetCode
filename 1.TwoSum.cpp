#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     	map<int,vector<int> > mp;
        for(int i=0;i<nums.size();++i) mp[nums[i]].push_back(i);
        vector<int> res;
        for(int i=0;i<nums.size();++i)
        {
            if(mp.count(target-nums[i])){
                if(target-nums[i]==nums[i])
                {
                    if(mp[nums[i]].size()>1)
                    {
                        res.push_back(i);
                        res.push_back(mp[nums[i]][1]);
                        return res;
                    }
                    else continue;
                }
                else{
                        res.push_back(i);
                        res.push_back(mp[target-nums[i]][0]);
                        return res;
                   }
                }       
            }
        return res;
    }
};
int main()
{
	Solution s;
	int a[]={0,2,0};
	vector<int> v(a,a+sizeof(a)/sizeof(int));
	vector<int> res=s.twoSum(v,0);
	for(int &i:res)cout<<i<<endl;
}
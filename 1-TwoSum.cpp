#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     	map<int,vector<int> > mp;
        for(int i=0;i<nums.size();++i) mp[nums[i]].push_back(i);
        sort(nums.begin(),nums.end());
        vector<int> res;
        for(int i=0;i<nums.size();++i)
        {
            for(int j=i+1;j<nums.size();++j)
            {
                if(nums[i]+nums[j]==target){
                    res.push_back(i);
                    res.push_back(j);
                    if((j-i)==1&&mp[nums[i]].size()>1)
                   	{
	                	res[0] = mp[nums[i]][0];
					    res[1] = mp[nums[i]][1];  	
                	}
                	else {
        				res[0] = mp[nums[i]][0];
					    res[1] = mp[nums[j]][0];  
	                }
                    return res;
                }
                else if(nums[i]+nums[j]>target)break;
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
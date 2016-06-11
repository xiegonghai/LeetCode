class Solution {
public:
    int maxSubArray(vector<int>& nums) {
	if(nums.size()==0)return -1;
	if(nums.size()==1)return nums[0];
	vector<int>  res_vec(nums.size());
	res_vec[0]=nums[0];
	int max_val = nums[0];
	for(vector<int>::size_type i=1;i<nums.size();++i)
	{
		res_vec[i]=max(res_vec[i-1]+nums[i],nums[i]);
		if(max_val<res_vec[i])max_val = res_vec[i];	
	}
	return max_val;
    }
};
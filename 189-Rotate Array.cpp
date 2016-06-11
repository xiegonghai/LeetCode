Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Related problem: Reverse Words in a String II

˼·һ:��λ����λ�ã���������һ������ʱ��O(n),�ռ�O(n)
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n)k=k%n;
        vector<int> tmp;
        for(int i=n-k;i<n;++i)
        {
            tmp.push_back(nums[i]);
        }
        for(int i=0;i<n-k;++i)
        {
            tmp.push_back(nums[i]);
        }
        nums = tmp;
    }
};
```
˼·����ȫ����ת���ٷֱ���ת�����֣�O(n),�ռ�O(1)
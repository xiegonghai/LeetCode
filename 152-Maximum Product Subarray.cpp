/*****************************************************************************************************************************
f(j+1)为以下标j结尾的连续子序列最大乘积值（1） 

状态转移方程如何表示呢： 
	这里我们知道A[j]可能为正数(或0)或负数，那么当A[j]为正数，期望前j个乘积为正数，
若为负数，则期望前面的为负数。故我们需定义两个函数来确定我们的状态转移方程： 

fmax(j+1)=max(max(fmax(j)?A[j],A[j]),fmin(j)?A[j]) 

fmin(j+1)=min(min(fmin(j)?A[j],A[j]),fmax(j)?A[j])(2) 

************************************************************************/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define FR(i,n) for(int i=0;i<n;i++)
#define CLC(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
using namespace std;
class Solution{
     public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
		assert(n>0);
		if(n==1)return nums[0];
  		int *A=&nums[0];
		int fmax=nums[0],fmin=nums[0];
		int final_res=fmax;
		for(int j=1;j<n;j++)
        {
        	int pre_fmax = fmax;
        	fmax=max(max(fmax*A[j],A[j]),fmin*A[j]);
			fmin=min(min(fmin*A[j],A[j]),pre_fmax*A[j]);	
			if(final_res<fmax)final_res = fmax;		
        }
        return final_res;
    }
};
int main()
{
	 //int a[]={2,0,-3,2,-5,7,-7,8,0,9};
	 int a[]={-2,-4};
	 vector<int> vs(a,a+sizeof(a)/sizeof(int));
	 Solution *s=new Solution;
	 cout<<s->maxProduct(vs);
	 delete s;
     return 0;
}

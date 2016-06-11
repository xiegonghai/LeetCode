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
     	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
     		 int m = nums1.size(),n = nums2.size(); 
			 int total = m+n;
			 cout<<total<<endl;
    		if(total&0x1)
    			return find_k(&nums1[0],m,&nums2[0],n,total/2+1);
   			else 
   			{
  				return (find_k(&nums1[0],m,&nums2[0],n,total/2)
				   +find_k(&nums1[0],m,&nums2[0],n,total/2+1))/2.0;
			   }

     	}
     
     private:
		static int find_k(int A[],int m,int B[],int n,int k)
		{
			if(m>n)return find_k(B,n,A,m,k);
			if(m==0) return B[k-1];
			if(k==1)return min(A[0],B[0]);
			int ia = min(m,k/2),ib = k-ia;
			if(A[ia-1]<B[ib-1]) return find_k(A+ia,m-ia,B,n,ib);
			else if(A[ia-1]>B[ib-1])	
				  return find_k(A,m,B+ib,n-ib,k-ib);
			else return A[ia-1];
		}   
};4. Median of Two Sorted Arrays 
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define IMIN numeric_limits<int>::min()
#define IMAX numeric_limits<int>::max()
#define FR(i,n) for(int i=0;i<n;i++)
#define CLC(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define viter vector<int>::const_iterator
#include<iterator>
using namespace std;
typedef ostream_iterator<int> OstreamItr; 	
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int beg=0,end = n-1;
        int max_area = 0;
        while(beg<end)
        {
        	int tmp=min(height[end],height[beg])*(end-beg);
        	if(max_area<tmp)max_area = tmp;
        	if(height[beg]<height[end]) beg++;
        	else end--;
        }
        return max_area;
    }
};
int main()
{
      Solution s;
      int a[]={1,3,8,3,2,2,2,2,2,2,2,8,1,1,2,1};
      vector<int> height(a,a+sizeof(a)/sizeof(int));
      copy(height.begin(), height.end(), OstreamItr(cout, " "));  
      cout<<s.maxArea(height);
      
      return 0;
}

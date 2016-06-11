#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define IMIN numeric_limits<int>::min()
#define IMAX numeric_limits<int>::max()
#define FR(i,n) for(int i=0;i<n;i++)
#define CLC(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        if(n<=0)return false;
        map<int,int> vis;
        //int num = pow(10,9);
        while(n!=1)
        {
           // num++;
            //if(num==IMAX)break;
            if(vis.count(n))return false;
            vis[n]=1;
            vector<int> vs;
            while(n)
            {
                vs.push_back(n%10);
                n=n/10;
            }
            n=0;
            for(int i=0;i<vs.size();++i)n=n+vs[i]*vs[i];
        }
        return true;
    }
};
int main()
{
	 int n;
	 Solution s;
	 while(cin>>n)cout<<n<<"=>"<<s.isHappy(n)<<endl;
     return 0;
}

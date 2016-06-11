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
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int ns=s.size(),np=p.size();
        if(np==0)return ns==0;
        int beg=0;
        int sn =0; 
        if(p[beg+1]!='*'){
            if(s[beg]==p[beg]||(p[beg]=='.'&&s[beg]!='\0'))
                return isMatch(string(s,beg+1,ns-1),string(p,beg+1,np-1));
            else return false;
        }
        else{
            while(s[sn]==p[beg]||(p[beg]=='.'&&s[sn]!='\0')){
                if(isMatch(string(s,sn,ns-sn),string(p,beg+2,np-2)))
                    return true;
                sn++;
            }
        }
        return isMatch(string(s,sn,ns-sn),string(p,beg+2,np-2));
    }
};
int main()
{
     Solution s;
     string s1,s2;
     while(cin>>s1,cin>>s2)
     	cout<<s.isMatch(s1,s2)<<endl;
     return 0;
}
/*
case0:
Input:
"a"
"ab*"

Expected:
true
case1:
aa
.*c
*/
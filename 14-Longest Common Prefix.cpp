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
typedef ostream_iterator<string> OstreamStr; 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<char> vps;
        int n=strs.size();
        if(n<1)return "";
        for(int j=0;j<strs[0].size();++j){
            int flag =0;
            for(int i=1;i<n;++i){
                if(strs[i].size()<=j||(j<strs[i].size()&&(strs[0][j]!=strs[i][j]))){
                    flag =1;
                    break;
                }
            }
            if(flag==1) break;
            vps.push_back(strs[0][j]);
        }
        if(vps.size()==0)return "";
        return string(vps.data(),0,vps.size());
    }
};
int main()
{
	Solution solu;
	string s[2]={"aa","a"};
	vector<string> vecstr(s,s+2);
	copy(vecstr.begin(), vecstr.end(), OstreamStr(cout, " "));
	cout<<endl;
	cout<<solu.longestCommonPrefix(vecstr)<<endl;
    return 0;
}


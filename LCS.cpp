#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <string.h>
#define IMIN numeric_limits<int>::min()
#define IMAX numeric_limits<int>::max()
#define FR(i,n) for(int i=0;i<n;i++)
#define CLC(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define viter vector<int>::const_iterator
#define vcter vector<int>::const_iterator
//    typedef ostream_iterator<int> OstreamItr;
 //   copy(res.begin(), res.end(), OstreamItr(cout, " "));
using namespace std;
#include <time.h>
#include <sys/timeb.h>

int get_time(string r)
{
    struct timeb rawtime;
    ftime(&rawtime);
    static int ms = rawtime.millitm;
    static unsigned long s = rawtime.time;
    int out_ms = rawtime.millitm - ms;
    unsigned long out_s = rawtime.time - s;
    if (out_ms < 0)
    {
        out_ms += 1000;
        out_s -= 1;
    }
    ms = rawtime.millitm;
    s = rawtime.time;
    int total = 1000*out_s+out_ms;
    cout<<r<<": "<<total<<"ms"<<endl;
    return total;
}
class Solution {
     public:
      string LCS(const string &a,const string &b) {
			int m=a.size(),n=b.size();
			vector<vector<string>> res(m+1,vector<string>(n+1));
			if(m==0||n==0)return string("");
			string best; 
			for(int i=1;i<=m;++i)
				for(int j=1;j<=n;++j){
						if(a[i-1]==b[j-1]){
							string tmp;
							tmp.push_back(a[i-1]);
							if(i>1&&j>1&&a[i-2]==b[j-2])res[i][j]=res[i-1][j-1]+tmp;
							else res[i][j]=tmp;
						}
						if(best.size()<res[i][j].size())best=res[i][j];						
					}
			return best;
      }
	string LCS2(const string &a,const string &b) {
			int m=a.size(),n=b.size();
			vector<vector<string>> res(m+1,vector<string>(n+1));
			if(m==0||n==0)return string("");
			for(int i=1;i<=m;++i)
				for(int j=1;j<=n;++j){
						if(a[i-1]==b[j-1]){
							string tmp;
							tmp.push_back(a[i-1]);
							res[i][j]=res[i-1][j-1]+tmp;	
						}
						else {
							if(res[i][j-1].size()<res[i-1][j].size())
								res[i][j]=res[i-1][j];
							else res[i][j]=res[i][j-1];
						}						
					}	
			return res[m][n];
	}
};
/*
			if(a[0]==b[0])res[0][0]=a[0];
			else if(a[0]==b[1])res[0][1]=a[0];
			else if(a[1]==b[0])res[1][0]=a[1];*/
int main()
{
     Solution s;
     get_time("begin");
     string s1,s2;
     while(cin>>s1>>s2){
        cout<<s.LCS(s1,s2)<<endl;
      	cout<<s.LCS2(s1,s2);
     }

     get_time("end");
     return 0;
}

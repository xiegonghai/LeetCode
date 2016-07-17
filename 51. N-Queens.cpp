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
    vector<vector<string>> solveNQueens(int n) {
 		vector<vector<string>> res;
 		vector<int> vis(n,0),resid(n,0);
 		vector<string> vs;
 		solveNQueens2(n,res,resid,vs,vis,0);
 		return res;
    }
    void solveNQueens2(int n,vector<vector<string>> &res,vector<int> resid,vector<string> vs,vector<int> vis,int j) {
    	if(j==n){
	    	res.push_back(vs);
	    }
	    else{
    		string s(n,'.');
        	for(int i=0;i<n;++i){
 				if(vis[i]==0){
  					vis[i]=1;
		   			s[i] = 'Q';
		   			resid[j]=i;
		   			if(!isLegal(resid,j,i)){
		   				s[i] = '.';
		   				vis[i]=0;
					   	continue;
		   			}
		   			vs.push_back(s);
		   			solveNQueens2(n,res,resid,vs,vis,j+1);
		   			vs.erase(vs.end()-1);
		   			s[i] = '.';
		   			vis[i]=0;
				 }
        	}
    	}   			
    }
    bool isLegal(const vector<int> &resid,int row,int col)
    {
    	for(int i=0;i<row;++i){//是否在同一对角线上 
    		if(abs(col-resid[i])==abs(row-i))return false;
	    }
    	return true; 
    }       
};
int main()
{
     Solution s;
     get_time("begin");
     vector<vector<string>> res;
     res=s.solveNQueens(3);
     for(vector<string> &one:res){
     	for(string line:one)
     		cout<<line<<endl;
   		cout<<endl;
     }
     get_time("end");
     return 0;
}

	

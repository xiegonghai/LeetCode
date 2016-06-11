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
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0)return;
        int n=matrix[0].size();
        int col=1,row=1,fircol=1,firow=1;
        int firone = matrix[0][0];
        for(int i=0;i<m;++i){//检测每一行是否有0 
        	row=1;
        	if(matrix[i][0]==0)fircol=0;
            for(int j=0;j<n;++j)
         		if(matrix[i][j]==0)row=0;
            if(row==0)matrix[i][0]=0;
        }
        if(matrix[0][0]==0)firow=0;
        for(int i=1;i<n;++i){ //检测每一列是否为0 
        	col=1;
            for(int j=0;j<m;++j)
                if(matrix[j][i]==0)col=0;
            if(col==0)matrix[0][i]=0;
        }
        	 typedef ostream_iterator<int> OstreamItr;
             for(int i=0;i<matrix.size();++i){
     copy(matrix[i].begin(), matrix[i].end(), OstreamItr(cout, " "));
     cout<<endl;}
        cout<<endl;
        if(fircol==0)matrix[0][0]=0;
       	for(int c=1;c<n;++c)//根据第一行处理每一列。 
		   	if(matrix[0][c]==0){
		   		for(int r=0;r<m;++r)matrix[r][c]=0;
	   		}
       	for(int r=1;r<m;++r)//根据第一列处理每一行，第一行除外 
		   	if(matrix[r][0]==0){
		   		for(int c=0;c<n;++c)matrix[r][c]=0;
	   		} 	
  		if(firow==0) for(int c=0;c<n;++c)matrix[0][c]=0;
  		if(fircol==0) for(int r=0;r<m;++r)matrix[r][0]=0;
    }
};
int main()
{
	 typedef ostream_iterator<int> OstreamItr;
     Solution s;
     vector<vector<int>> ma={
		{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}
     };
     for(int i=0;i<ma.size();++i){
     copy(ma[i].begin(), ma[i].end(), OstreamItr(cout, " "));
     cout<<endl;}
     get_time("begin");
     s.setZeroes(ma);
     for(int i=0;i<ma.size();++i){
     copy(ma[i].begin(), ma[i].end(), OstreamItr(cout, " "));
     cout<<endl;}
     get_time("end");
     return 0;
}

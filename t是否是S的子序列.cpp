#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <string>
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
      bool isChildStr(string s,string t) {
      		int flag = 1;
			vector<vector<int> > vec = getvectors(s,t,flag);
			if(flag==0) return false;
			else{
				int m = vec.size();
				int val = vec[0][0];
				int next = val;
				for(int k=1;k<m;++k){
					next = firpos(vec[k],val);
					if(next<0) return false;
					else val = next;	
				}
				return true;
			}
      }
      int firpos(vector<int> &sortarr,int val){
      		int n = sortarr.size();
      		if(val>=sortarr[n-1])return -1;
      		int beg=0,end= n-1;
      		while(beg<end){
      			int mid = (beg+end)/2;
      			if(sortarr[mid]==val)beg = mid+1;
      			else if(sortarr[mid]<val)beg= mid+1;
      			else end = mid-1;	
	      	}
	      	if(beg>=n)return sortarr[n-1];
	      	if(beg<n&&sortarr[beg]>val)return sortarr[beg];
	      	else{
	      		
	      		while(beg<n&&sortarr[beg]<=val)beg++;
	      		return sortarr[beg];
	      	} 
      }
      vector<vector<int> > getvectors(const string &s,const string &t,int &flag){
		map<char,vector<int>> mp = getmap(s);
        vector<vector<int>> vs;
        int m=t.size();
        for(int j=0;j<m;++j){
       		if(mp.count(t[j]))vs.push_back(mp[t[j]]);
       		else {
			   flag = 0;
			   return vs;
       		}
        }
      	return vs;
      }
      map<char,vector<int>> getmap(const string &s){
     	map<char,vector<int>> res;
      	int n = s.size();
      	for(int i=0;i<n;++i){
  		  if(res.count(s[i])) res[s[i]].push_back(i);
  		  else {
	  		  	vector<int> tmp;
	  		  	tmp.push_back(i);
	  		  	res[s[i]] = tmp;
  		  }
        }
        return res;
      }
};
int main()
{
     Solution s;
     //while(1){
     string s1,t1;
     cin>>s1;
     cin>>t1;
     //get_time("begin");
     if(s.isChildStr(s1,t1)){
     	cout<<"Yes"<<endl;
     }
     else cout<<"No"<<endl;
     //}
     //get_time("end");
     return 0;
}

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#define IMIN numeric_limits<int>::min()
#define IMAX numeric_limits<int>::max()
#define FR(i,n) for(int i=0;i<n;i++)
#define CLC(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define vcter vector<char>::iterator 
//testcase:"lqjfkvadrurbvwnfobpmvbyluawicltnbcvnyxsprjsmigtwjijeljrflpnnahdelarjxkbqttebbyakijquuhbfxrvxyabj"  
// Time Limit Exceeded
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<=1)return n;
        vector<vector<char> > vm(n);
        vector<int> vi(n);
        vi[0]=1;
        vm[0].push_back(s[0]);
        for(int i=1;i<n;++i)
        {
            vcter it= find(vm[i-1].begin(),vm[i-1].end(),s[i]);
            if(it!=vm[i-1].end())
            {
                vector<char> vtmp(it+1,vm[i-1].end());
                vm[i]=vtmp;
                vm[i].push_back(s[i]);
                vi[i]=vm[i-1].end()-it;
            }
            else{
                vi[i]=vi[i-1]+1;
                vm[i]=vm[i-1];
                vm[i].push_back(s[i]);
            }
        }
        /*
        typedef ostream_iterator<int> OstreamItr; 
        typedef ostream_iterator<char> OstreamCtr; 
		copy(vi.begin(), vi.end(), OstreamItr(cout, " "));
		cout<<endl;
	    for(int l=0;l<vm.size();++l)
	    {
	 		copy(vm[l].begin(), vm[l].end(), OstreamCtr(cout, "")); 
	 		cout<<endl;	
 		 }
 		 */
        return *max_element(vi.begin(),vi.end());
    }
};
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
int main()
{
      string s;
      while(cin>>s)
      {
      	//s="lqjfkvadrurbvwnfobpmvbyluawicltnbcvnyxsprjsmigtwjijeljrflpnnahdelarjxkbqttebbyakijquuhbfxrvxyabj";
      	get_time("-");
      	Solution sou;
		cout<<sou.lengthOfLongestSubstring(s)<<endl;
		get_time("cost");	
      }
      return 0;
}

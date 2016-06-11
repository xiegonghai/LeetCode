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
#define viter vector<int>::const_iterator
#define vcter vector<int>::const_iterator

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
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> res;
        map<char,string> nmap;
        init_map(nmap);
        for(int i=0;i<n;++i){
        	if(digits[i]=='1')continue;
            string word= nmap[digits[i]];
            vector<string> sw,stmp;
            for(int j=0;j<word.size();++j){
                vector<char> vs;
                vs.push_back(word[j]);
                vs.push_back('\0');
                sw.push_back(vs.data());
                for(int k=0;k<res.size();++k)
                    stmp.push_back(res[k]+sw[j]);
            }
            if(res.size()==0)res = sw;
            else res = stmp;
        }
        return res;
    }
    void init_map(map<char,string> &nmap)
    {
        nmap['1']="";nmap['2']="abc";nmap['3']="def";
        nmap['4']="ghi";nmap['5']="jkl";nmap['6']="mno";
        nmap['7']="pqrs";nmap['8']="tuv";nmap['9']="wxyz";
        nmap['0']=" ";
        
    }
};
int main()
{
     Solution s;
     get_time("begin");
     string m;
     while(cin>>m){
  			   vector<string> vi; 
   			  typedef ostream_iterator<string> OstreamStr;
              vi=s.letterCombinations(m);
      		  copy(vi.begin(), vi.end(), OstreamStr(cout, " "));

     }

     get_time("end");
     return 0;
}

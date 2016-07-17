#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
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
          void CountryLeader(const string &filename)
          {
              fstream f(filename);
              ofstream fout("res.txt");
              string line;
              int T=0;
              if(getline(f,line))
              {
                istringstream istr(line);
                istr>>T;
              }
              map<char,bool> wc;
              int max_num = 0,now= 0;
              string best_case,str_line;
              for(int i=0;i<T;++i)
              {
                int case_num=0;
                if(getline(f,line))
                {
                  istringstream istr(line);
                  istr >> case_num;
                }
                best_case.clear();
                for(int j=0;j<case_num;++j)
                {
                    str_line.clear();now=0;
                    if(getline(f,line))
                    {
                        istringstream istr(line);
                        istr>>str_line;
                    }
                    for(int k=0;k<str_line.size();++k)
                    {
                    	if(wc.count(str_line[k])==0)
                      {
                    		++now; 
                    	  wc[str_line[k]]=1;
                      }
                    }
                    wc.clear();
                    if(max_num<=now)
                    {
                        if(max_num==now)
                        {
                        	if(strcmp(best_case.c_str(),str_line.c_str())>0)
                        	   best_case = str_line;
                        }
                        else 
                        {
                        	max_num = now;
                        	best_case = str_line;
                        }
                    }
                }
                max_num = 0;
                fout<<"Case #"<<(i+1)<<": "<<best_case<<endl;
              }  
        }
};
int main()
{
     Solution s;
     get_time("begin");
      s.CountryLeader("A-small-practice.in");
     get_time("end");
     return 0;
}

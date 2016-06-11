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
    string countAndSay(int n) {
        vector<char> vec;
        int i=2;
        string pres("1");
        if(n<=1)return pres;
        pres="11";
        while(i++<n){
            int count=1;
            string s;
            for(int j=0;j<pres.size();++j)
                if(pres[j]==pres[j+1]&&count<9)count++;
                else{
                	s.push_back(count+'0');
                    s.push_back(pres[j]);
                    count=1;
                }
            pres = s;
        }
        return pres;
    }
};
int main()
{
     Solution s;
     get_time("begin");
     int m;
     while(cin>>m)
      cout<<s.countAndSay(m);
     get_time("end");
     return 0;
}


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
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int na = a.size(),nb = b.size();
        int n = max(na,nb)+1,min_len=min(na,nb);
        string res(n,'0');
        for(int i=0;i<min_len;++i){
            int tmp1 = a[i]+b[i]-'0'-'0';
            int tmp2=res[i]-'0'+tmp1%2;
            res[i]=(tmp2)%2+'0';
            int tmp=tmp1/2+tmp2/2;
            res[i+1]=tmp%2+'0';
            res[i+2]=tmp/2+'0';
        }
        cout<<res<<endl;
        if(na<nb)a=b;
        for(int j=min_len;j<n-1;++j){
            int sum=res[j]-'0'+a[j]-'0';
            res[j]=sum%2+'0';
            res[j+1]=sum/2+'0';
        }
        if(res[n-1]=='0')res = res.substr(0,n-1);
        reverse(res.begin(),res.end());
        return res;
    }
};
int main()
{
	 Solution s;
     get_time("begin");
     cout<<s.addBinary("11","1")<<endl;
     get_time("end");
     return 0;
}

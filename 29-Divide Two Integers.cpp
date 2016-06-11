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
#include <assert.h>
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
#define IMAX numeric_limits<int>::max()
#define IMIN numeric_limits<int>::min()
class Solution {
     public:
          int divide(int dividend,int divisor) {
          	assert(divisor!=0);
			int sign = (dividend<0&&divisor>0||dividend>0&&divisor<0)?-1:1;
			unsigned int a = dividend<0?-dividend:dividend;
			unsigned int b = divisor<0?-divisor:divisor;
			unsigned int c = b;
			int multi=0;
			while(a>=b){
				int i=1;	
				while(a>=b){
					a -=b;
					multi+=i;
					if(b<IMAX>>1){
						b=b<<1;
						i<<=1;
					}
				}
				b=c;	
			}
			if(sign>0&&multi==IMIN)return IMAX;
			else return multi*sign;
      }
};
int main()
{
     get_time("begin");
     Solution s;
     cout<<s.divide(IMIN,-1)<<endl;
     get_time("end");
     return 0;
}

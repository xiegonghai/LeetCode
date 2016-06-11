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
   int climbStairs(int n) {
        vector<int> vec(n+1,0);
        vec[1]=1;vec[2]=2;
        if(n<=2)return vec[n];
        for(int i=3;i<=n;++i)
            vec[i]=vec[i-1]+vec[i-2];
        return vec[n];
    }
};
int main()
{
     Solution s;
     get_time("begin");
     cout<<s.climbStairs(44)<<endl;
     get_time("end");
     return 0;
}

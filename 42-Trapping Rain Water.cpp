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
    int trap(vector<int>& height) {
        int n= height.size();
        if(n<3)return 0;  //�ݹ����  
        else if(n==3){  
            if(height[1]<height[0]&&height[1]<height[2])  //�������ӿɼ�����ˮ�� 
                return min(height[2]-height[1],height[0]-height[1]);
            else return 0;
        }
        else{
            int left=0,right=n-1;
            int max1=-1,max2=-1,id1,id2;
            while(left<right){   //���δ��������м俿£��Ѱ�����˵���ߴ� 
                if(height[left]>=max1){   //������벿�ֲ���ߵ� 
                    max1 = height[left];
                    id1 = left;
                }
                if(height[right]>=max2){  //�����Ұ벿�ֲ���ߵ�
                    max2 = height[right];
                    id2 = right;
                }
                if(height[left]<height[right])++left; //�Ǳ�С�����м俿£ 
                else --right;
            }
            int sum=0;      
            for(int i=id1+1;i<id2;++i) //�����м�����߶Ⱥ� 
                sum+=height[i];
            sum = (id2-id1-1)*min(height[id1],height[id2])-sum;//�õ��м���ˮ�� 
            vector<int> fir,sec;
            auto it_beg = height.begin(),it_end=height.end();
            fir.assign(it_beg,it_beg+id1+1);
            sec.assign(it_beg+id2,it_end);
            return trap(fir)+sum+trap(sec);         //��벿��ˮ+�м���ˮ+�Ұ벿��ˮ 
        }
        
    }
};
int main()
{
     Solution s;
     get_time("begin");
     int a[]={5,4,6,7,1,2};
     vector<int> vec(a,a+6);
     cout<<s.trap(vec);
     //typedef ostream_iterator<int> OstreamItr;
	 //copy(res.begin(), res.end(), OstreamItr(cout, " "));
	 cout<<endl;
     get_time("end");
     return 0;
}

	
		

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
#include <string>
using namespace std;
#include <time.h>
#include <sys/timeb.h>
#include <assert.h>
//int strcmp(const char *a,const char *b){return 0;}
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
    ////cout<<r<<": "<<total<<"ms"<<endl;
    return total;
}
/**************************************************************************************************
karatsuba乘法思路：划分成部分乘法
 x = x1 * 10^m + x0；
y = y1 * 10^m + y0。其中m为正整数，m < n，且x0，y0 小于 10^m。
 xy = (x1 * 10^m  + x0)(y1 * 10^m  + y0)
 =z2 * 10^2m + z1 * 10^m + z0
 
z2 = x1 * y1=f(x1,y1)；

z1 = x1 * y0 + x0 * y1；

z0 = x0 * y0=f(X0,y0)。

此步骤共需4次乘法，但是由Karatsuba改进以后仅需要3次乘法。因为：
z1 = x1 * y0+ x0 * y1
z1 = (x1 + x0) * (y1 + y0) - x1 * y1 - x0 * y0，
   = f(x1+x0,y1+y0)-z2-z0;
   
对于给定的n位大数，算法的复杂度不超过3n^log3 ≈ (3n)^1.585。
傅里叶变换的效率是n*log(n)*log(n) n越大相差越明显
 n=100;
 1:   8.4380e+003
 2:   4.4141e+003
 n=1000:
 1:   3.2452e+005
 2:   9.9317e+004
****************************************************************************************************/
class Solution {
     public:
   		  string str_multiply(string &a,string &b)
   		  {
				lstrip(a,' ');lstrip(b,' '); //处理a,b的符号，转化为纯整数的乘法 
				string sign;
				int na=a.size(),nb=b.size();
				if(a[0]=='-'&&b[0]!='-'){ sign="-";a=a.substr(1,na-1);}
				if(a[0]!='-'&&b[0]=='-'){ sign="-";b=b.substr(1,nb-1);}
				if(a[0]=='-'&&b[0]=='-'){a=a.substr(1,na-1);b=b.substr(1,nb-1);}
				return sign+multiply2(a,b); //multiply2实现纯正数的乘法 
	         
          }
          string multiply2(const string &a,const string &b) {  //默认支持合法的数字字符串,负数在前面加上负号,允许最左边有空格 
				int na=a.size(),nb=b.size();
				if(na==0||nb==0)return string("0");// a!=b时，收敛到一个为0，一个不为0 
				if(na==1&&nb==1){                  // a==b时，收敛到a和b都为1个元素 
					int tmps = (a[0]-'0')*(b[0]-'0');
					char c2=tmps/10+'0',c1=tmps%10+'0';
					string st;
					if(c2!='0')st.push_back(c2);
					st.push_back(c1);
					return st;
				}
				int m = max(na,nb);
				int m2=m/2;  //划分一半 
				string high1,high2,low1,low2;
				high1 = a.substr(0,max(na-m2,0)),low1 = a.substr(max(na-m2,0),m2);//划分可能为产生越界，保留合法界限 
				high2 = b.substr(0,max(nb-m2,0)),low2 = b.substr(max(nb-m2,0),m2);
				string z0 = multiply2(low1,low2);                   //计算Z0 
				string z1 = multiply2(str_sum(low1,high1),str_sum(low2,high2));//计算Z1 
				string z2 = multiply2(high1,high2);                //计算Z2
				string tmp1 = z2+string(m/2+m/2,'0'),tmp2=str_sum(z1,"-"+z2);//幂次方直接添0 
				tmp2 = str_sum(tmp2,"-"+z0)+string(m2,'0');
        		string final = str_sum(str_sum(tmp1,tmp2),z0);           //按公式三次加法 
			  return final;    
    	  }
    	  string str_sum(string a,string b)  //robust字符串加减法，支持负数的字符串,利用 add_str，sub_str来实现 
          {
          	  int na = a.size(),nb = b.size();
          	  if(na==0||nb==0)return a+b; // 
          	  string sign;
          	  if(a[0]=='-'&&b[0]=='-'){
          	  	    sign = "-";
					return sign+add_str(a.substr(1,na),b.substr(1,nb));
  	          }
  	    	  else if(a[0]=='-'&&b[0]!='-'){
  	    	 		string aa=a.substr(1,na);
					if(strcmp2(aa.data(),b.data())>0)
						return "-"+sub_str(aa,b); 	
					else return sub_str(b,aa);
  	    	  }
			  else if(a[0]!='-'&&b[0]=='-'){
					string bb=b.substr(1,nb);
					if(strcmp2(bb.data(),a.data())>0)
						return "-"+sub_str(bb,a); 	
					else return sub_str(a,bb);	
  			 }	  	
              else return add_str(a,b);
  	      }
          string add_str(string a,string b)
          {
       			if(a=="0")return b;
                if(b=="0")return a;
                int na=a.size(),nb=b.size();
                if(na==0||nb==0)return a+b;
                reverse(a.begin(),a.end());
                reverse(b.begin(),b.end());
                int m=max(na,nb)+1,min0=min(na,nb),max0=max(na,nb);
                string s(m,'0');
                for(int i=0;i<min0;++i){
                    int sum = a[i]-'0'+ b[i] -'0';
                    int now = s[i]-'0'+ sum%10;
                    s[i]=now%10+'0';
                    s[i+1]=now/10+sum/10+'0';
                }
                string maxstr = na>nb?a:b;
                for(int j=min0;j<max0;++j){
                  if(s[j]!='0'){
                       	int tmp = s[j]-'0'+maxstr[j]-'0';
                     	s[j]=tmp%10+'0';
             			if(tmp>=10)s[j+1]='1';   
                  }
                  else s[j] = maxstr[j];
                }
                int r=m-1;
                while(s[r--]=='0');
				s=s.substr(0,r+2); 
                reverse(s.begin(),s.end());
                return s;
            }
            string sub_str(string a,string b)
            {
                reverse(a.begin(),a.end());
                reverse(b.begin(),b.end());
                int na=a.size(),nb=b.size();
                assert(na>=nb);
                string res(na,'0');
                for(int i=0;i<nb;++i){
                  if(a[i]-b[i]<0){
                    int k=i+1;
                   	while(k<na&&a[k]=='0')k++;
                   	if(k<na)a[k] = a[k]-1;
                    for(int j=i+1;j<k;++j)a[j]='9';
                    res[i] = 10+(a[i]-b[i])+'0';
                  }
                  else {res[i]=a[i]-b[i]+'0';}
                }
                for(int r=nb;r<na;++r)res[r]=a[r]; 
                reverse(res.begin(),res.end());
				int k=0;
				while(res[k]=='0')k++; 
                res = res.substr(k,na-k);
                return res;
            }
            int strcmp2(const string &a,const string &b)
			{
            	int na = a.size(),nb=b.size();
				if(na<nb)return -1;
				else if(na>nb) return 1;
				else {
					int i=0;
					while(i<na){
						if(a[i]>b[i])return 1;
						else if(a[i]<b[i])return -1;
						i++;
					}
					return 0;
				}	
            }
            void lstrip(string &s,char c)
			{
            	int n=s.size();
            	int i;
				for(i=0;i<n;++i)if(s[i]!=c)break;
				s=s.substr(i,n-i);	
            } 
            void lstrip(string &s)
			{
            	int n=s.size();
            	int i;
				for(i=0;i<n;++i)if(s[i]!='0')break;
				s=s.substr(i,n-i);	
            } 
};
int main()
{
	system("mode con cols=5000 lines=200");
     Solution s;
     get_time("begin");
     string s1,s2;
	 while(cin>>s1>>s2)
 	 	cout<<endl<<s.str_multiply(s1,s2)<<endl;	
     get_time("end");
     return 0;
}

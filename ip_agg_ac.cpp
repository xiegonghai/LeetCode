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
#include <set>
using namespace std;
typedef struct IP_ADD{
	int a,b,c,d;
	 //IP_ADD(int _a,int _b,int _c,int _d):a(_a),b(_b),c(_c),d(_c){}
     bool operator < (const IP_ADD&rhs) const  
    {  
        if(a!=rhs.a) return a<rhs.a;  
        else if(b!=rhs.b) return b<rhs.b;  
        else if(c!=rhs.c) return c<rhs.c;  
        else return d<rhs.d;  
    }
	friend IP_ADD operator &(IP_ADD& rhs,IP_ADD& lhs)
	{
		IP_ADD x;
		x.a= lhs.a&rhs.a;
		x.b= lhs.b&rhs.b;
		x.c= lhs.c&rhs.c;
		x.d= lhs.d&rhs.d;
		return x;
	}
}IP;
void ip_agg()
{
	int T,num=1;
	cin>>T;
	while(T--){
		int m,n;
		cin>>n>>m;
		IP_ADD tn[n],tm[m];
		for(int j=0;j<n;++j){
			char tmp;
			//cin>>tn[j].a>>tmp>>tn[j].b>>tmp>>tn[j].c>>tmp>>tn[j].d;	
			scanf("%d.%d.%d.%d",&tn[j].a,&tn[j].b,&tn[j].c,&tn[j].d);
		}
		vector<int> res(m);
		cout<<"Case #"<<num++<<":"<<endl;
		for(int i=0;i<m;++i){
			char tmp;
			//cin>>tm[i].a>>tmp>>tm[i].b>>tmp>>tm[i].c>>tmp>>tm[i].d;
			scanf("%d.%d.%d.%d",&tm[i].a,&tm[i].b,&tm[i].c,&tm[i].d);
			set<IP_ADD> ipset;
			int count=0;
			for(int k=0;k<n;++k){
				IP_ADD now;
				now=tm[i]&tn[k];
				if(!ipset.count(now)){ count++;ipset.insert(now);}
			}
			cout<<count<<endl;
			res[i]=count;	
		}
	}
	
}
int main()
{
     ip_agg();
     return 0;
}

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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
vector<string> split(string s,string delim)
{
	char *ss=const_cast<char *>(s.c_str());
	const char *ddelim= delim.data();
    char *token = strtok(ss,ddelim);
    vector<string> vstr;
    while(token!=NULL){
        string stmp = token;
        vstr.push_back(stmp);
        token = strtok(NULL,ddelim);
    }
    return vstr;
}
string itostring(unsigned int a)
{
    if(a==0)return "0";	
	vector<char> vc;
	while(a){
		unsigned int tmp = a%10;
		vc.push_back(tmp+'0');
		a=a/10;
	}
	int n=vc.size();
	string s(n,'0');
	for(int i=n-1;i>=0;--i)s[n-1-i]=vc[i];
	return s;	
}
string join(const vector<string> &vs,const string &s)
{
	int n=vs.size();
	string restr;
	for(int i=0;i<n-1;++i)restr=restr+vs[i]+s;
	restr +=vs[n-1];
	return restr;
}
string ip_add(string s1,string s2)
{
	vector<string> vecs1=split(s1,"."),vecs2=split(s2,".");
	int n1=vecs1.size(),n2=vecs2.size();
	n1=min(n1,n2);
	string res;
    int a1,b1,c;
	for(int i=0;i<n1;++i){
		a1=atoi(vecs1[i].data());
		b1=atoi(vecs2[i].data());
		c=a1&b1;
		string stmp=itostring(c);
		res=res+stmp+".";
	}
	res=res.substr(0,res.size()-1);
	//cout<< res<<endl;
	return res;
	
}
void ip_aggregate()
{
	int T;
	cin>>T;
	for(int i=0;i<T;++i){
		int n,m;
		cin>>n>>m;
		vector<string> vn(n),vm(m);
		int r=0;
		while(r<n)cin>>vn[r++];
		r=0;
		while(r<m)cin>>vm[r++];
		get_time("begin");
		vector<int> vres(m);
		map<string,int> ms;
		for(int k=0;k<m;++k){
			for(int j=0;j<n;++j){
					string tmp=ip_add(vm[k],vn[j]);
					//cout<<tmp.size()<<tmp<<endl;
					if(!ms.count(tmp))vres[k]++;
					ms[tmp]=1;	
			}
		}
     //typedef ostream_iterator<int> OstreamItr;
     cout<<"Case #"<<i+1<<":"<<endl;
     for(int x=0;x<vres.size();++x)cout<<vres[x]<<endl;
     //copy(vres.begin(),vres.end(),OstreamItr(cout,"\n"));	
	 get_time("end");	
	}	
	
}


int main()
{
     ip_aggregate();
     return 0;
}

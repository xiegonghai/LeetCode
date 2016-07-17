#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <string>
#include <string.h>
#define IMIN numeric_limits<int>::min()
#define IMAX numeric_limits<int>::max()
#define FR(i,n) for(int i=0;i<n;i++)
#define CLC(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define viter vector<int>::const_iterator
#define vcter vector<int>::const_iterator
using namespace std;
//字符串分割函数 
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
//是否为大写字母 
bool isCapital(char c)
{
    if(c>='A'&&c<='Z')return true;
    else return false;
}
//处理一行字符串,将字母替换成具体的值 
vector<string> getNewLine(const string &line,map<char,string> &mp)
{
    int n = line.size();
    vector<string> vs;
    string word;
    int lastisop=0;
    for(int i=0;i<n;++i){
        if(line[i]=='<'){
            if(word.size()==1&&isCapital(word[0])){
                vs.push_back(mp[word[0]]);
            }
            else vs.push_back(word);
            word.clear();
            if(line[i+1]=='='){
                vs.push_back(string("<="));
                i++;
            }
            else {
                vs.push_back(string("<"));
            }
        }
        else word.push_back(line[i]);
    }
    if(word.size()==1&&isCapital(word[0])){
    	vs.push_back(mp[word[0]]);
     }
     else vs.push_back(word);
    return vs;
}
//检查该行值逻辑是否成立 
bool isSatisfied(vector<string> &vs)
{
    int n=vs.size();
    for(int i=1;i<n;i=i+2){
        if(vs[i]=="<"){
            if(atoi(vs[i-1].c_str())-atoi(vs[i+1].c_str())>=0)return false;
        }
        else if(vs[i]=="<="){
            if(atoi(vs[i-1].c_str())-atoi(vs[i+1].c_str())>0)return false;
        }
    }
    return true;
}
//检查该组数逻辑是否成立 
string isSucceed(vector<string> &cons,map<char,string> &mp)
{
    int n = cons.size();
    for(int i=0;i<n;++i){
        vector<string> newl = getNewLine(cons[i],mp);
        //typedef ostream_iterator<string> OstreamStr;
        //copy(newl.begin(), newl.end(), OstreamStr(cout, " "));
        //cout<<endl;
        if(isSatisfied(newl)==false)return string("No");
    }
    return string("Yes");
}
//
void Constraint_Checker()
{
    int m;
    string tmp;
    getline(cin,tmp);
    m = atoi(tmp.c_str());
    vector<string> vs;
    map<char,int> mps;
    for(int i=0;i<m;++i){
    	tmp.clear();
        getline(cin,tmp);
        for(int k=0;k<tmp.size();++k){
            if(isCapital(tmp[k])){
                if(!mps.count(tmp[k]))mps[tmp[k]]=1;
            }
        }
        vs.push_back(tmp);
    }
    //cout<<"over"<<endl;
    int n;
    getline(cin,tmp);
    n = atoi(tmp.c_str());
    map<char,string> mp;
    string line;
    int wn = mps.size();
    for(int x=0;x<n;++x){
        mp.clear();
    	for(int y=0;y<wn;++y){
            getline(cin,line);
            vector<string> row = split(line,string(" "));
            if(!mp.count(row[0][0]))
            {
    			mp[row[0][0]]=row[1];
            }
            line.clear();
        }
        string res = isSucceed(vs,mp);
        cout<<res<<endl;
    }
}

int main()
{
    Constraint_Checker();
    return 0;
}

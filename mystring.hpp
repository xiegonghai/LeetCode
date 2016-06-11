#pragma once
#ifndef _mystring_h_
#define _mystring_h_
#include <string.h>
#include <vector>
#include <string>
//字符串分割函数,类似python的split
vector<string> split(char s[],const char *delim)
{
    char *token = strtok(s,delim);
    vector<string> vstr;
    while(token!=NULL){
        string stmp = token;
        vstr.push_back(stmp);
        token = strtok(NULL,delim);
    }
    return vstr;
}
//若用string调用如下
//string s="192.168",sm=".";
//vector<string> ss=split(const_cast<char *>(s.c_str()),sm.data());

//参数都为string版
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
//以下给出类似于Python 中join功能的实现，后续不断完善
string join(const vector<string> &vs,const string &s)
{
    int n=vs.size();
    string restr;
    for(int i=0;i<n-1;++i)restr=restr+vs[i]+s;
    restr +=vs[n-1];
    return restr;
}


//列出自己实现的string to int( atoi)
int myAtoi(string str) {
        if(str=="")return 0;
        if(str.size()==1)
        {
            if(str[0]>'9'||str[0]<'0')return 0;
        }
        int beg=0;
        while(str[beg]==' ')beg++;//越过前面的空字符
        if((str[beg]>'9'||str[beg]<'0')&&str[beg]!='-'&&str[beg]!='+')return 0;//第一个非空字符非法
        int sign=(str[beg]=='-')?-1:1; //判断符号
        int j=(str[beg]=='+'||str[beg]=='-')?beg+1:beg;//判定何时开始计算
        int res=0;
        for(int i=j;i<str.size();++i)
        {
            if(str[i]>'9'||str[i]<'0')break;//遇到非数字即不看后面的内容
            res=res*10+(str[i]-'0');
        }
        return res*sign;
}
//列出自己实现的unsigned int转string，无bug
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

#endif
/*
//atoi 或者 itoa  (int to string)int atoi(const char *nptr);
char*itoa(int value,char*string,int radix);
char *strtok(char s[], const char *delim);
//strod字符串转浮点
string = "3.1415926 This stopped it";
x = strtod(string, &stopstring);
printf("string = %s\n", string);
printf("strtod = %f\n", x);
printf("Stopped scan at: %s\n", stopstring);
string = 3.1415926 This stopped it
strtod = 3.141593
Stopped scan at:  This stopped it
string = -1011 This stopped it



//char *或vector<char>转string

vector<char> vs;
vs.push_back(char);
vs.push_back('\0'); //特别注意char* 转
string s;
s=string(vs.data());
char a[100]="6666666";
s=string(a);




1. const char* 和string 转换

(1) const char*转换为 string，直接赋值即可。

     EX: const char* tmp = "tsinghua".

            string s = tmp;

(2) string转换为const char*，利用c_str()或者data()

    EX:  string s = "tsinghua";

           const char*tmp = s.c_str();

           const char *tmp = s.data();

2. char*和const char*之间的转换

(1) const char*转化为char*，利用const_cast<char*>

     EX: const char* tmp = "tsinghua";

             char* p = const_cast<char*>(tmp);

(2) char*转化为const char*，直接赋值即可。

     char* p = "tsinghua".

     const char* tmp = p;

3. char*和string之间的转换

  有了1和2的基础，char*和string转化就很简单了。

(1)char*转化为string，直接赋值即可。

     EX: char* p = "tsinghua".

            string str = p;

(2)string转化为char*，走两步，先是string->const char*，然后是const char*->char*

     EX:  string str = "tsinghua";

             char* p = const_cast<char*>(str.c_str()):
*/
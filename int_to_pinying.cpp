#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<math.h>
using namespace std;
void init1(map<int,string> &map_index)
{
   map_index[0]="";
   map_index[1]="shi";
   map_index[2]="bai";
   map_index[3]="qian";
   map_index[4]="wang";
   map_index[8]="YI";

}
/*
yibailinger
sanshisi
wubailiushiqi
bashijiu*/
void init2(map<int,string> &map2)
{
   map2[0]="ling";
   map2[1]="yi";
   map2[2]="er";
   map2[3]="san";
   map2[4]="si";
   map2[5]="wu";
   map2[6]="liu";
   map2[7]="qi";
   map2[8]="ba";
   map2[9]="jiu"; 
}
vector<string> transform(vector<int> &s,map<int,string> map_index,map<int,string> map2)
{
    vector<string> res;
    for(int i=0;i<s.size();++i)
    {
        //cout<<s[i]<<endl;
          if(i%4==0&&((i/4)%2==1))res.push_back(map_index[4]);
        if(i%4==0&&((i/4)%2==0)&&i!=0) res.push_back(map_index[8]);
        if(s[i]!=0)
        {   
             res.push_back(map_index[i%4]);
             res.push_back(map2[s[i]]);
             //cout<<88<<endl;
        }
       else{ 
                   while((i<s.size())&&(s[i]==0))i++;
                   //cout<<"1"<<endl;
      	           i=i-1;
                   res.push_back(map2[0]);   
        }     
    }
    return res;
}

int main()
{ 
    int n;
    map<int,string> map_index;//数字到汉字的映射
    map<int,string> map2; //所在位
    init1(map_index);
    init2(map2);
    while(cin>>n)
    {
      vector<int> vs;
      int N = n;
      while(n){
            int tmp=n%10;
            vs.push_back(tmp);
            n = n/10;
      }
      vector<string> res;
      res=transform(vs,map_index,map2);
      int end = 0;
      if((N>=10)&&(N%10==0))end = 1;
      for(int i=res.size()-1;i>=end;--i)cout<<res[i];
      cout<<endl;
    }
    return 0;
}
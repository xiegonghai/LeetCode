#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<math.h>
using namespace std;
void init1(map<int,string> &map_index)
{
   map_index[0]="";
   map_index[1]="ʰ";
   map_index[2]="��";
   map_index[3]="Ǫ";
   map_index[4]="��";
   map_index[8]="��";
   
}
void init2(map<int,string> &map2)
{
   map2[0]="��";
   map2[1]="Ҽ";
   map2[2]="��";
   map2[3]="�q";
   map2[4]="��";
   map2[5]="��";
   map2[6]="½";
   map2[7]="��";
   map2[8]="��";
   map2[9]="��";  
}
vector<string> transform(const string &s,map<int,string> map_index,map<int,string> map2)
{
    vector<string> res;
    for(int i=0;i<s.size();++i)
    {
    	cout<<s[i]<<endl;
  	    if(i%4==0&&((i/4)%2==1))res.push_back(map_index[4]);
    	if(i%4==0&&((i/4)%2==0)&&i!=0) res.push_back(map_index[8]);
        if(s[i]!='0') 
        {	
        	 res.push_back(map_index[i%4]);
             	res.push_back(map2[s[i]-'0']);
             	cout<<88<<endl;
        }
       else{  
       			while((i<s.size())&&(s[i]=='0'))i++;
       			cout<<"1"<<endl;
			    i=i-1;
          		res.push_back(map2[0]);	
        }      
    }
    return res;
}

int main()
{

    string s;
    map<int,string> map_index;//���ֵ����ֵ�ӳ��
    map<int,string> map2; //����λ
    init1(map_index);
    init2(map2);
    while(cin>>s)
    {
      for(int i=0;i<s.size()/2;++i)
      {
  		char tmp= s[i];
  		s[i] = s[s.size()-1-i];
  		s[s.size()-1-i] = tmp;
      }
      cout<<s<<endl;
      vector<string> res;
      res=transform(s,map_index,map2);
      for(int i=res.size()-1;i>=0;--i)cout<<res[i];
    }
    return 0;
}
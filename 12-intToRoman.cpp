#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#define IMIN numeric_limits<int>::min()
#define IMAX numeric_limits<int>::max()
#define FR(i,n) for(int i=0;i<n;i++)
#define CLC(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        map<int,string> mp1,mp2,mp3,mp4;
		init1(mp1);init2(mp2);init3(mp3);init4(mp4);
		string s;
		int n=1;
		while(num)
		{
			int tmp=num%10;
			switch(n)
			{
				case 1:s=mp1[tmp]+s;break;
				case 2:s=mp2[tmp]+s;break;
				case 3:s=mp3[tmp]+s;break;
				case 4:s=mp4[tmp]+s;break;	
			}
			cout<<s<<endl;
			cout<<num<<endl;
			num = num/10;
			n++;
		}
		return s;
    }
    void init1(map<int,string> &mp)
    {
    	mp[0]="";
    	mp[1]=string("I");mp[2]=string("II");
    	mp[3]=string("III");mp[4]=string("IV");
    	mp[5]=string("V");mp[6]=string("VI");
    	mp[7]=string("VII");mp[8]=string("VIII");
    	mp[9]=string("IX");		
    }
    void init2(map<int,string> &mp)
    {
    	mp[0]="";
    	mp[1]=string("X");mp[2]=string("XX");
    	mp[3]=string("XXX");mp[4]=string("XL");
    	mp[5]=string("L");mp[6]=string("LX");
    	mp[7]=string("LXX");mp[8]=string("LXXX");
    	mp[9]=string("XC");		
    }
    void init3(map<int,string> &mp)
    {
    	mp[0]="";
    	mp[1]=string("C");mp[2]=string("CC");
    	mp[3]=string("CCC");mp[4]=string("CD");
    	mp[5]=string("D");mp[6]=string("DC");
    	mp[7]=string("DCC");mp[8]=string("DCCC");
    	mp[9]=string("CM");		
    }
    void init4(map<int,string> &mp)
    {
    	mp[1]=string("M");mp[2]=string("MM");
    	mp[3]=string("MMM");
    }
};
int main()
{
	Solution s;
	int n;
	while(cin>>n)
	cout<<s.intToRoman(n)<<endl;
	return 0;
}

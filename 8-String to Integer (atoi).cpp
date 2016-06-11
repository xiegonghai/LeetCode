#include<iostream>
#include<limits>
using namespace std;
#define IMAX numeric_limits<int>::max() 
#define IMIN numeric_limits<int>::min() 
/*********************************
test cases:
"1"=>"1"
"+"=>"0"  "-"=>"0"
"     0101"=>"101"
" -1010023630o4"=>"-1010023630"
"+12"=>"12"
"  fsad101 "=>"0"
"2147483648"=>"2147483647"
"-2147483648"=>"-2147483648"
**********************************/
int myAtoi(string str) 
{
        if(str=="")return 0;
        if(str.size()==1)
        {
            if(str[0]>'9'||str[0]<'0')return 0;
        }
        int beg=0;
        while(str[beg]==' ')beg++;//Խ��ǰ��Ŀ��ַ�
        if((str[beg]>'9'||str[beg]<'0')&&str[beg]!='-'&&str[beg]!='+')return 0;//��һ���ǿ��ַ��Ƿ�
        int sign=(str[beg]=='-')?-1:1; //�жϷ���
        int j=(str[beg]=='+'||str[beg]=='-')?beg+1:beg;//�ж���ʱ��ʼ����
        int res=0;
        int count=0;
        for(int i=j;i<str.size();++i)
        {
            if(str[i]>'9'||str[i]<'0')break;//���������ּ��������������
            if(count>9)return (sign==1)?IMAX:IMIN;
            res = res*10;
        	if(count==8){
				if(sign==1&&res>IMAX/10)  return IMAX;
				if(sign==-1&&res*sign<IMIN/10)  return IMIN;
			}
			if(count==9){
				//cout<<str[i]-'0'<<endl<<res<<" "<<IMIN;
				if(sign==1&&(IMAX-res<=str[i]-'0'))return IMAX;
				if(sign==-1&&(res*sign-IMIN<=str[i]-'0')) return IMIN; 
			}
			res +=str[i]-'0';
			count++;
        }
        return res*sign;
}
int main()
{	
	cout<<myAtoi(" -1010023630o4");
	return 0;
}

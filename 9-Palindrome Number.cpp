���������ж�����ʹ�ö���Ŀռ�
Determine whether an integer is a palindrome. **Do this without extra space**.

˼·����һ��������ת���ж���ԭ�������಻���
ע�⸺��һ�����ǻ�����
```
#define IMAX numeric_limits<int>::max()
#define IMIN numeric_limits<int>::min()
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int x1 = reverse(x);
        return x1==x;
    }
    int reverse(int x) {
        int sign= x>0?1:-1;
        if(x==IMIN)return 0; //���Ǹ�������ֵҪ����������ֵ��1
        else x = abs(x);
        int res=0,count=0;
        for(;x;x/=10)
        {
            if(count>9)return (sign==1)?IMAX:IMIN;//����Խ�� 
            res = res*10;
            if(count==8){                       //���ǳ˷���Խ��
                if(sign==1&&res>IMAX/10)  return 0;
                if(sign==-1&&res*sign<IMIN/10)  return 0;
            }
            if(count==9){
                if(sign==1&&(IMAX-res<=x%10))return 0;
                if(sign==-1&&(res*sign-IMIN<=x%10)) return 0;
            }
            count++;
            res=x%10+res;
        }
        return res*sign;    
    }
};
```
回文数的判定，不使用额外的空间
Determine whether an integer is a palindrome. **Do this without extra space**.

思路：将一个整数逆转，判定和原来的数相不相等
注意负数一定不是回文数
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
        if(x==IMIN)return 0; //考虑负数绝对值要比正数绝对值大1
        else x = abs(x);
        int res=0,count=0;
        for(;x;x/=10)
        {
            if(count>9)return (sign==1)?IMAX:IMIN;//考虑越界 
            res = res*10;
            if(count==8){                       //考虑乘法后越界
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
#define IMAX numeric_limits<int>::max()
#define IMIN numeric_limits<int>::min()
class Solution {
public:
    int reverse(int x) {
        int sign= x>0?1:-1;
        if(x==IMIN)return 0;
        else x = abs(x);
        int res=0,count=0;
        for(;x;x/=10)
        {
            if(count>9)return (sign==1)?IMAX:IMIN;
            res = res*10;
            if(count==8){                         //�����ڶ�λ��󿴻᲻��Խ�磬Խ�緵��0
                if(sign==1&&res>IMAX/10)  return 0;
                if(sign==-1&&res*sign<IMIN/10)  return 0;
            }
            if(count==9){
                if(sign==1&&(IMAX-res<=x%10))return 0;//���һλ��󿴲���Խ�磬Խ�緵��0
                if(sign==-1&&(res*sign-IMIN<=x%10)) return 0;
            }
            count++;
            res=x%10+res;
        }
        return res*sign;   
    }
};

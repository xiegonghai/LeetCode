#define IMIN numeric_limits<int>::min()
class Solution {
public:
    double myPow(double x, int n) {
        int is_min=0;
        if(n<0){
            x=1/x;
            if(n==IMIN){n=abs(n+1);is_min=1;}
            else n=abs(n);
        }
        if(n==0)return 1;
        int sign=-1;
        if(n%2==0)sign=0;
        else sign=1;
        double left = myPow(x,n/2);
        double res=0;
        if(sign==0)res= left*left;
        else res= left*left*x;
        if(is_min)res = res*x;
        return res;
    }
};
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n)
        {
            if(n%2==0)n=n/2;
            else break;
        }
        if(n==1)return true;
        else return false;
    }
};
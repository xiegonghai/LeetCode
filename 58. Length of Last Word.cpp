class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        if(n==0)return 0;
        int fir,sec=n-1;
        while(sec>=0&&s[sec]==' ')--sec;
        if(sec<0)return 0;
        else fir = sec-1;
        while(fir>=0&&s[fir]!=' ')--fir;
        return sec-fir;
    }
};
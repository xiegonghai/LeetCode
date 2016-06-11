class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len=0,last = -1;
        int n= s.size();
        stack<int> lefts;
        for(int i=0;i<n;++i){
            if(s[i]=='(')lefts.push(i);//如果是左括号，一直入栈
            else{  
                if(lefts.empty()){//一直遇到右括号“)))))”,如果栈空，记录last的位置，
                    //总是在第一个合法位置的前一个位置
                    last = i;   
                }
                else{//遇到右括号且栈不为空，那么出栈且计算当前最大值
                    lefts.pop();
                    if(lefts.empty())//空了，记录上一次合法的第一个位置,序列")))))()"，出栈之前“(”
                        max_len = max(max_len,i-last);
                    else max_len = max(max_len,i-lefts.top());//这种情况，序列“((()”,出栈前“(((”
                }
            }
        }
        return max_len;
    }
    /**********************动态规划*******************************
     *记f[i]为以i开头的合法括号长度最大值
     *1.这种情况“（（）（）（））”f[i]=f[i+1]+2,
     *如果s[i]与s[i+f[i+1]+1]匹配,match=i+f[i+1]+1
     *即一个是'(',一个是')'
     *2.如果是这样“（（）（）（））（）”,f[i]=f[i]+f[match+1]
    ***********************************************************/
    int longestValidParentheses_2(string s) {
        int n = s.size();
        vector<int> f(n,0);
        int res=0;
        for(int i=n-2;i>=0;--i){
            int match = i+f[i+1]+1;
            if(s[i]=='('&& match<n &&s[match]==')'){
                f[i]=f[i+1]+2;
                if(match+1<n)f[i]+=f[match+1];
            }
            res = max(res,f[i]); 
        }
        return res;
    }
};
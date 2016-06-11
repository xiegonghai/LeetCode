class Solution {  
public:  
    string convert(string s, int nRows)  
    {  
        if(nRows <= 1 || s.length() < 3 || s.length() <= nRows) return s;  
        string s2;  
        int zigSpan = nRows*2 - 2;  
        for (int i = 0; i < nRows; i++)  
        {  
            for (int j = i; j < s.length(); j+=zigSpan)  
            {  
                s2.push_back(s[j]);  //先打印间隔相等为zigspan的垂直元素,第i行第一个元素为s[i],下一个s[i+zigspan]
                //第i行斜线第一个元素的位置nrow-(i+1)+nrow-1=2nrow-2-i,斜线相邻元素相隔zigspan=2nrow-2
                //第i行应该是打印，2nrow-2-i+0*zigspan，2nrow-2-i+1*zigspan,2nrow-2-i+2*zigspan,....,2nrow-2-i+n*zigspan
                //循环中,n=(j-i)*span,起始位置j-i=0
                if (i != 0 && i != nRows-1 && zigSpan+j-2*i<s.length())  
                {  
                    s2.push_back(s[zigSpan+j-2*i]);  
                }  
            }  
        }  
        return s2;  
    }  
}; 
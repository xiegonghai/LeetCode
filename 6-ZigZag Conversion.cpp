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
                s2.push_back(s[j]);  //�ȴ�ӡ������Ϊzigspan�Ĵ�ֱԪ��,��i�е�һ��Ԫ��Ϊs[i],��һ��s[i+zigspan]
                //��i��б�ߵ�һ��Ԫ�ص�λ��nrow-(i+1)+nrow-1=2nrow-2-i,б������Ԫ�����zigspan=2nrow-2
                //��i��Ӧ���Ǵ�ӡ��2nrow-2-i+0*zigspan��2nrow-2-i+1*zigspan,2nrow-2-i+2*zigspan,....,2nrow-2-i+n*zigspan
                //ѭ����,n=(j-i)*span,��ʼλ��j-i=0
                if (i != 0 && i != nRows-1 && zigSpan+j-2*i<s.length())  
                {  
                    s2.push_back(s[zigSpan+j-2*i]);  
                }  
            }  
        }  
        return s2;  
    }  
}; 
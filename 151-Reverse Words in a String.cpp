class Solution {
public:
    void reverseWords(string &s) {
 vector<string> data;
        string word;
        stringstream ss(s);
        while(ss>>word) data.push_back(word);

        vector<string> rdata(data.rbegin(), data.rend());

        s = accumulate(rdata.begin(), rdata.end(), string(""),
            [](string s1, string s2){
                if(s1.empty()) return s2;
                else return s1+" "+s2; 
            });
		
    }
};
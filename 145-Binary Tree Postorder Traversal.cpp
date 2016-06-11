#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <string.h>
#define IMIN numeric_limits<int>::min()
#define IMAX numeric_limits<int>::max()
#define FR(i,n) for(int i=0;i<n;i++)
#define CLC(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define viter vector<int>::const_iterator
#define vcter vector<int>::const_iterator
#include<stack>
using namespace std;
#include <time.h>
#include <sys/timeb.h>

int get_time(string r)
{
    struct timeb rawtime;
    ftime(&rawtime);
    static int ms = rawtime.millitm;
    static unsigned long s = rawtime.time;
    int out_ms = rawtime.millitm - ms;
    unsigned long out_s = rawtime.time - s;
    if (out_ms < 0)
    {
        out_ms += 1000;
        out_s -= 1;
    }
    ms = rawtime.millitm;
    s = rawtime.time;
    int total = 1000*out_s+out_ms;
    cout<<r<<": "<<total<<"ms"<<endl;
    return total;
}
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL)return res;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode * rn=root;
        map<TreeNode*,int> map;
        map[rn]=1;
        while(!st.empty()){
            while(rn!=NULL&&rn->left!=NULL&&!map.count(rn->left)){
                st.push(rn->left);  
                rn = rn->left;
                map[rn]=1;
            }
            if(rn->right!=NULL&&!map.count(rn->right)){
                rn = rn->right;
                st.push(rn);
                map[rn]=1;
            }
            else {
                res.push_back(rn->val);
				st.pop();
   				if(!st.empty())rn = st.top();
            }      
        }
        return res;
    }
};
int main()
{
     Solution s;
     get_time("begin");
     vector<int> res;
     TreeNode l1(1),l2(2),l3(3),l4(4),l5(5);
     l1.left = &l2,l1.right=&l3,l2.left=&l4,l4.right=&l5;
     cout<<99<<endl;
     res= s.postorderTraversal(&l1);
     cout<<666<<endl;
     typedef ostream_iterator<int> ios;
     copy(res.begin(),res.end(),ios(cout," "));
     get_time("end");
     return 0;
}

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
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
 /*递归方式 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL)return v;
        vector<int> vl,vr;
        vl = inorderTraversal(root->left);
        v.push_back(root->val);
        vr = inorderTraversal(root->right);
        int n = vl.size()+v.size()+vr.size();
        vector<int> res(n);
        copy(vl.begin(),vl.end(),res.begin());
        copy(v.begin(),v.end(),res.begin()+vl.size());
        copy(vr.begin(),vr.end(),res.begin()+vl.size()+v.size());
        return res;
    }
};
*/
class Solution {  //迭代方式 
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> st;
        while(root||!st.empty()){
            while(root!=NULL){
            	st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            v.push_back(root->val);
			root = root->right;
        }
        return v;
    }
};
int main()
{
     Solution s;
     get_time("begin");
     TreeNode t0(66),t1(12),t2(78);
     t0.left  = &t1;
     t1.right = &t2;
     vector<int> res=s.inorderTraversal(&t0);
     typedef ostream_iterator<int> OstreamItr;
	 copy(res.begin(), res.end(), OstreamItr(cout, " "));
     get_time("end");
     return 0;
}

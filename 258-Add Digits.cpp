/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int,vector<ListNode*> > maps;
        for(int i=0;i<lists.size();++i)
        {
            while(lists[i]!=NULL)
            {
                maps[lists[i]->val].push_back(lists[i]);
                lists[i] = lists[i]->next;
            }
        }
        ListNode *now=NULL,*pre=NULL,*head;
        map<int,vector<ListNode*> >::const_iterator it = maps.begin();
        if(it!=maps.end()){
                head = (it->second)[0];
        }
        else head = NULL;
        while(it!=maps.end())
        {
            cout<<(it->second).size()<<endl;
            for(int k=0;k<(it->second).size();++k)
            {
                pre = now;
                now = (it->second)[k];
                if(pre!=NULL)pre->next = now;
            }
            it++;
        }
        return head;
    }
};
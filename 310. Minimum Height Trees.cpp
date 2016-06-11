class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        int nsize=edges.size();
        set<int> ps;
        map<int,set<int>> mp;      //类似于邻接表
        for(int i=0;i<nsize;++i){
                mp[edges[i].first].insert(edges[i].second);
                mp[edges[i].second].insert(edges[i].first);
        }
        set<int> leaf;
        auto it = mp.begin();
        while(it!=mp.end()){
            if(it->second.size()==1)leaf.insert(it->first);  //第一次得到叶子节点集合
            ++it;
        }
        while(mp.size()>2){              //当剩下的节点数>2
            set<int> newleaf;
            auto it2 = mp.begin();
            while(it2!=mp.end()){
                if(leaf.count(it2->first)){          //如果当前节点在叶子节点
                    auto itbeg = (it2->second).begin();
                    auto itend = (it2->second).end();
                    while(itbeg!=itend){              //使得和叶子节点相邻的节点不再和叶子节点相连
                        mp[*itbeg].erase(it2->first);
                        if(mp[*itbeg].size()==1)newleaf.insert(*itbeg); //加入到新一轮的叶子节点
                        ++itbeg;
                    }
                    auto it2next = ++it2; //确保迭代器有效
                    --it2;
                    mp.erase(it2);      //删除叶子节点
                    it2 = it2next;
                }
                else ++it2;
            }
            leaf = newleaf;       //更新新一轮的叶子节点
        }
         vector<int> res;
         if(n==1){                //如果n==1要求直接返回0
             res.push_back(0);
             return res;
         }
         auto mit=mp.begin();
         while(mit!=mp.end()){
             res.push_back(mit->first);
             ++mit;
         }
         return res;
    }
};
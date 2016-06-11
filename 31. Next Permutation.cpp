class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const auto rbeg = nums.rbegin();
        const auto rend = nums.rend();
        auto pivot = next(rbeg);
        while(pivot!=rend && *pivot>=*prev(pivot))++pivot;
        if(pivot==rend){
            reverse(rbeg,rend);
            return;
        }
        auto bigger = find_if(rbeg,pivot,bind1st(less<int>(),*pivot));
        swap(*pivot,*bigger);
        reverse(rbeg,pivot);
    }
};
#define IMIN numeric_limits<int>::min()
#define IMAX numeric_limits<int>::max()
class Solution {
public:
    bool isPowerOfFour(int num) {
             int a=1;
             map<int,int> mset;
             while(a<IMAX&&a!=0)//最大值为2,147,483,648,最多循环5次,时间复杂度O(1)
             {
                 mset[a]=1;
                 a=a<<2;
             }
             if(mset.count(num))return true;
             else return false;
    }
};
//这样还是进行了5次移位操作，可以直接进行静态映射，只要一次便可出结果
//这里不写了，可以自己写
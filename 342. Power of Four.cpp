#define IMIN numeric_limits<int>::min()
#define IMAX numeric_limits<int>::max()
class Solution {
public:
    bool isPowerOfFour(int num) {
             int a=1;
             map<int,int> mset;
             while(a<IMAX&&a!=0)//���ֵΪ2,147,483,648,���ѭ��5��,ʱ�临�Ӷ�O(1)
             {
                 mset[a]=1;
                 a=a<<2;
             }
             if(mset.count(num))return true;
             else return false;
    }
};
//�������ǽ�����5����λ����������ֱ�ӽ��о�̬ӳ�䣬ֻҪһ�α�ɳ����
//���ﲻд�ˣ������Լ�д
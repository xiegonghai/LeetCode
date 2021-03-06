#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include<utility>
#include<unordered_map>
#define IMIN numeric_limits<int>::min()
#define IMAX numeric_limits<int>::max()
#define FR(i,n) for(int i=0;i<n;i++)
#define CLC(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define viter vector<int>::const_iterator
#include<iterator>
using namespace std;
typedef ostream_iterator<int> OstreamItr; 
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
class Solution {
public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int> > result;
		map<vector<int>,int> mres;
		if(nums.size()<4)return result;
		sort(nums.begin(),nums.end());
		//nums.erase(unique(nums.begin(),nums.end()),nums.end());
		map<int,vector<pair<int,int> > > cache;
		map<int,vector<pair<int,int> > > cache_value;
		for(size_t a=0;a<nums.size()-1;++a){
			for(size_t b=a+1;b<nums.size();++b){
				cache[nums[a]+nums[b]].push_back(pair<int,int>(a,b));
				//cout<<"fs"<<nums[a]+nums[b]<<endl;
				cache_value[nums[a]+nums[b]].push_back(pair<int,int>(nums[a],nums[b]));
			}
		}
		auto it_beg=cache.begin(),it_end=cache.end();
		auto it2_beg=cache_value.begin(),it2_end=cache_value.end();
		int flag=0;
		while(it_beg!=it_end)
		{
			if((flag++)==0)--it_end,--it2_end;
			int now_sum = it2_beg->first+it2_end->first;
			//cout<<(it_beg)->first<<endl<<(it_end)->first<<endl;
			if(now_sum==target){
				 for(int i=0;i<it_beg->second.size();++i)
				 {
 					for(int j=0;j<it_end->second.size();++j)
 					{
					 	if((it_beg->second[i].first)!=(it_end->second[j].first)&&(it_beg->second[i].second)!=(it_end->second[j].second)&&
						 (it_beg->second[i].first)!=(it_end->second[j].second)&&(it_beg->second[i].second)!=(it_end->second[j].first))
						 {
		 		   				 cout<<"==================="<<it_beg->first<<"   "<<it_end->first<<endl;
			 			         vector<int> tmp;
								 tmp.push_back(it2_beg->second[i].first);tmp.push_back(it2_beg->second[i].second);
								 tmp.push_back(it2_end->second[j].first);tmp.push_back(it2_end->second[j].second);
								 sort(tmp.begin(),tmp.end());
								 mres[tmp]=1;
 						}
					 }
 				}
 				if(it_beg==it_end)break;
 				it_beg++;it2_beg++;
 				if(it_beg==it_end)break;
 				it_end--;it2_end--;
 				if(it_beg==it_end)break;
 				
			}
			else{
				if(now_sum<target){
				    if(it_beg==it_end)break;
					it_beg++,it2_beg++;
					if(it_beg==it_end)break;
				}
				else {
				    if(it_beg==it_end)break;
					it_end--,it2_end--;
					if(it_beg==it_end)break;
				}
			}
		}
        vector<vector<int> > res1;
        auto mit = mres.begin();
        while(mit!=mres.end()){
        	res1.push_back(mit->first);
        	mit++;
        }
		return res1;
    }
};

int main()
{
	system("mode con:cols=100 lines=9000");
	 Solution s;
	 vector<int> nums;
	 int a[]={0,8,2,-9,-14,5,2,-5,-5,-9,-1,3,1,-8,0,-3,-12,2,11,9,13,-14,2,-15,4,10,9,7,14,-8,-2,-1,-15,-15,-2,8,-3,7,-12,8,6,2,-12,-8,1,-4,-3,5,13,-7,-1,11,-13,8,4,6,3,-2,-2,3,-2,3,9,-10,-4,-8,14,8,7,9,1,-2,-3,5,5,5,8,9,-5,6,-12,1,-5,12,-6,14,3,5,-11,8,-7,2,-12,9,8,-1,9,-1,-7,1,-7,1,14,-3,13,-4,-12,6,-9,-10,-10,-14,7,0,13,8,-9,1,-2,-5,-14};
	 int a2[]={
 		-4,-8,7,13,10,1,-14,-13,0,8,6,-13,-5,-4,-12,2,-11,7,-5,0,-9,-14,-8,-9,2,-7,-13,-3,13,9,-14,-6,8,1,14,-5,-13,8,-10,-5,1,11,-11,3,14,-8,-10,-12,6,-8,-5,13,-15,2,11,-5,10,6,-1,1,0,0,2,-7,8,-6,3,3,-13,8,5,-5,-3,9,5,-4,-14,11,-8,7,10,-6,-3,11,12,-14,-9,-1,7,5,-15,14,12,-5,-8,-2,4,2,-14,-2,-12,6,8,0,0,-2,3,-7,-14,2,7,12,12,12,0,9,13,-2,-15,-3,10,-14,-4,7,-12,3,-10
 	};
 	int a1[]={
	 	91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245
};
 	 int a11[]={0,0,0,0};
	 nums.resize(sizeof(a1)/sizeof(int));
	 copy(a1,a1+sizeof(a1)/sizeof(int),nums.begin());
	 get_time("begin");
	 vector<vector<int> > res=s.fourSum(nums,-236727523);
	 get_time("end");
	 for(vector<int> myvector:res)
     {
	    copy(myvector.begin(), myvector.end(), OstreamItr(cout, " "));
		cout<<endl;  
     }
     return 0;
}

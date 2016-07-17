#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <string.h>
#include <set>
using namespace std;
class Solution {
public:
	void output_shortpath(){
		int V,Q;
		cin>>V>>Q;
		int dis[100][100];
		int path[100][100];
		for(int i=0;i<V;++i)
			for(int j=0;j<V;++j){
				if(j==i+1)dis[i][j]=1;
				else dis[i][j]=101;
			}
		int ai,bi,i=0;
		while(i++<Q){
				cin>>ai>>bi;
				Floyd(dis,V);
				if(dis[ai-1][bi-1]==101){
					cout<<-1<<endl;
				}
				else{
					cout<<dis[ai-1][bi-1]<<endl;
					dis[ai-1][bi-1]=1;
				}
		}		
	}
	void Floyd(int A[][100],int n){
		int i,j,k;
		for(k=0;k<n;k++)
		{ 
			for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			if(A[i][j]>(A[i][k]+A[k][j]))
			{
				A[i][j]=A[i][k]+A[k][j];
			}
		} 
	} 
};
int main()
{
     Solution s;
     s.output_shortpath();
     return 0;
}

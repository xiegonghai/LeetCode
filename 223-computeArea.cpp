#include <iostream>
using namespace std;
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long resAx,resBy,resCx,resDy;
        long long area1,area2,intersect=-1;
        resAx= max(A,E);
        resCx= min(C,G);
        resBy=max(B,F);
        resDy=min(D,H);
        cout<<resAx<<endl<<resCx<<endl<<resBy<<endl<<resDy<<endl;
        if(resCx-resAx<=0||resDy-resBy<=0)intersect=0;
        else intersect = abs(resCx-resAx)*abs(resDy-resBy);
        if((A==C||B==D)||(E==G)||F==H)intersect=0;
        area1=(C-A)*(D-B),area2 = (G-E)*(H-F);
        //cout<<area1<<endl<<area2<<endl;
        //cout<<intersect<<endl;
        return area1+area2-intersect;
}
/*
-1500000001,0,-1500000000,1,1500000000,0,1500000001,1
*/
int main()
{
	cout<<computeArea(-1500000001,0,-1500000000,1,1500000000,0,1500000001,1)<<endl;
	
	return 0;
}
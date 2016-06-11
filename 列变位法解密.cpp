#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T,n;
char s[100005],c;
int a[1000005];

int main()
{
    int Case=1;
    scanf("%d",&T);
    while (T--)
    {
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        scanf("%c",&c);
        gets(s);
        scanf("%d",&n);
        int l=strlen(s),p=1,j,i=1;
        printf("Case #%d:\n",Case++);
        while (i<=n)
        {
            j=0;
            while (i+j<=l)
            {
                a[i+j]=p++;
                j+=n;
            }
            i++;
        }
        for (int i=1;i<=l;i++) printf("%c",s[a[i]-1]);
        printf("\n");
    }
    return 0;
}
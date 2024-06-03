#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("yenngua.inp","r",stdin);
    freopen("yenngua.out.","w",stdout);
    int m,n,i,j,b=0,cnt=0;
    cin>>m>>n;
    int a[m][n],nn[m],ln[n];
    for(i=0;i<m;i++)
	{
        for(j=0;j<n;j++)
		{
            cin>>a[i][j];
        }
    }
    for(i=0;i<m;i++)
	{
        int mn=INT_MAX;
        for(j=0;j<n;j++)
		{
            mn=min(a[i][j],mn);
        }
        nn[i]=mn;
    }
    for(j=0;j<n;j++)
	{
        int mx=INT_MIN;
        for(i=0;i<m;i++)
		{
            mx=max(a[i][j],mx);
        }
        ln[j]=mx;
    }
    for(i=0;i<m;i++)
	{
        for(j=0;j<n;j++)
		{
            if(a[i][j]==nn[i]&&a[i][j]==ln[j])
			{
                cout<<i+1<<' '<<j+1<<endl;
                cnt++;
            }
        }
    }
    if (cnt==0) cout<<0;
}

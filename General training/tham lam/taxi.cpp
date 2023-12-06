#include<bits/stdc++.h>
using namespace std;
long long n,rs=0,a[100009],dem[5],i;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        dem[a[i]]++;
    }
    rs=dem[4];
    if(dem[3]<=dem[1])
    {
        rs+=dem[3];
        dem[1]-=dem[3];
        rs+=(dem[2]/2);
        if(dem[2]%2==0)
            rs+=(dem[1]+3)/4;
        else
        {
            rs+=1;
            dem[1]-=2;
            if (dem[1]<0) dem[1]=0;
            rs+=(dem[1]+3)/4;
        }
        cout<<rs;
    }
    else
    {
        rs+=dem[1];
        dem[3]-=dem[1];
        rs+=((dem[2]+1)/2);
        rs+=dem[3];

        cout<<rs;
    }
}

#include<bits/stdc++.h>
using namespace std;
string s;
const int MAX=1e7+5;
int n,k,x,i1[MAX],i2[MAX],i3[MAX],pos;
vector<string> v1,v2;
int main()
{
    //freopen("SHUFFLE.INP","r",stdin);
    //freopen("SHUFFLE.OUT","w",stdout);
    cin>>n>>k>>x;
    for(int i=1;i<=x;i++)
    {
        cin>>i1[i]>>i2[i]>>i3[i];
    }
    for(int i=1;i<=k;i++)
    {
        pos=i;
        for(int j=x;j>=1;j--)
        {
            if(pos<i3[j]+i2[j]&&pos>=i3[j])
            {
                pos=pos-i3[j]+i1[j];
            }
            else if(pos>=i3[j]+i2[j]&&pos<=i2[j]+i1[j]-1)
            {
                pos=pos-i2[j];
            }
            else if(pos<i3[j]) pos+=i2[j];
        }
        cout<<pos<<" ";
    }
}

#include<bits/stdc++.h>
using namespace std;
string a,b;
int n,m;
long long x,y;
long long dp1[19][2][10][2],dp2[19][2][10][2];
long long f(int i,bool les,int last, bool nz) {
    if (i==n) return 1;
    long long ans=0;
    if (dp1[i][les][last][nz]!=-1) return dp1[i][les][last][nz];
    for (char c='0';c<='9';c++)
        if ((les||c<=a[i+1])&&(c-'0'!=last||!nz)) ans+=f(i+1,les||c<a[i+1],c-'0',nz||c!='0');
    dp1[i][les][last][nz]=ans;
    return ans;
}
long long g(int i,bool les,int last, bool nz) {
    if (i==m) return 1;
    long long ans=0;
    if (dp2[i][les][last][nz]!=-1) return dp2[i][les][last][nz];
    for (char c='0';c<='9';c++)
        if ((les||c<=b[i+1])&&(c-'0'!=last||!nz)) ans+=g(i+1,les||c<b[i+1],c-'0',nz||c!='0');
    dp2[i][les][last][nz]=ans;
    return ans;
}
int main() {
    //freopen("NSAME.INP","r",stdin);
    //freopen("NSAME.OUT","w",stdout);
    for (int i=0;i<=18;i++)
        for (int j=0;j<=1;j++)
            for (int k=0;k<=9;k++)
                for (int m=0;m<=1;m++)
                    dp1[i][j][k][m]=dp2[i][j][k][m]=-1;
    cin>>x>>y;
    x--;
    a=to_string(x),b=to_string(y);
    n=a.size(),m=b.size();
    a=' '+a;
    b=' '+b;
    cout<<g(0,0,0,0)-f(0,0,0,0);
}

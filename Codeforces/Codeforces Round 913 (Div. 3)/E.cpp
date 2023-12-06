#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,x,dp[8][64][64],val=0,tcs=0;
string s;
ll f(ll i,ll carry,ll sum)
{
    if(i==n)
    {
        if(carry==0&&sum==tcs)
        {
            return 1;
        }
        else return 0;
    }
    ll ans=0;
    if(dp[i][carry][sum]!=-1)
    {
        return dp[i][carry][sum];
    }
    if(carry%10==(s[i+1]-'0'))
    {
        for(int a=0;a<=9;a++)
        {	
            for(int b=0;b<=9;b++)
            {
                for(int c=0;c<=9;c++)
                {
                    ans+=f(i+1,carry/10+a+b+c,sum+a+b+c);
                }
            }
        }
    }
    return dp[i][carry][sum]=ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>s;
        tcs=0;
        for(int i=0;i<s.length();i++)
        {
            tcs+=(s[i]-'0');
        }
        reverse(s.begin(),s.end());
        n=s.length();
        s=" "+s;
        ll res=0;
        memset(dp,-1,sizeof(dp));
        for(int a=0;a<=9;a++)
        {
            for(int b=0;b<=9;b++)
            {
                for(int c=0;c<=9;c++)
                {

                    res+=f(0,a+b+c,a+b+c);
                }
            }
        }
        cout<<res<<'\n';
    }
}
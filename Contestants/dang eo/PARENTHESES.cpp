#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
int main(){
    freopen("PARENTHESES.INP","r",stdin);
    freopen("PARENTHESES.OUT","w",stdout);
    cin>>n;
    while(n--){
        cin>>s;
        int n=s.size();
        s=' '+s;
        int b[int(1e5)+5],mnx[int(1e5)+5],mnn[int(1e5)+5];
        for(int i=1;i<=n;i++) b[i]=0;
        for(int i=0;i<=n+2;i++) mnx[i]=INT_MAX;
        for(int i=0;i<=n+2;i++) mnn[i]=INT_MAX;
        for(int i=1;i<=n;i++){
            if(s[i]=='('){
                b[i]=b[i-1]+1;
                mnx[i]=min(b[i],mnx[i-1]);
            }
            else{
                b[i]=b[i-1]-1;
                mnx[i]=min(b[i],mnx[i-1]);
            }
            //cout<<b[i]<<' ';
        }
       // cout<<b[n]<<' ';
        for(int i=n;i>=1;i--) mnn[i]=min(b[i],mnn[i+1]);
        for(int i=1;i<=n;i++)
            if(mnx[i-1]>=0 && mnn[i]>=2 && b[n]==2 && s[i]=='(') cout<<i-1<<' ';
        for(int i=1;i<=n;i++)
            if(mnx[i-1]>=0 && mnn[i]>=-2 && b[n]==-2 && s[i]==')') cout<<i-1<<' ';
        cout<<'\n';
    }
}


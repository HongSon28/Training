#include<bits/stdc++.h>
using namespace std;
int n;
int mx,l,r;
vector<int>prime,res;
void seive() {
    bool p[n+1];
    memset(p,true,sizeof(p));
    for (int i=2;i<=n;i++) {
        if (p[i]) {
            prime.push_back(i);
            for (int j=i*2;j<=n;j+=i) p[j]=false;
        }
    }
}
int main() {
    //freopen("NUMBER.INP","r",stdin);
    //freopen("NUMBER.OUT","w",stdout);
    cin>>n;
    seive();
    int g[n+1][prime.size()+1];
    for (int i=0;i<=n;i++)
        for (int j=0;j<=prime.size();j++)
            g[i][j]=1;
    for (int p=1;p<=prime.size();p++) {
        for (int i=0;i<=n;i++) {
            g[i][p]=g[i][p-1];
            int power=prime[p-1];
            while (power<=i) {
                int temp=g[i-power][p-1]*power;
                g[i][p]=max(g[i][p],temp);
                power*=prime[p-1];
            }
        }
    }
    int i=n,p=prime.size();
    while (g[i][p]!=1) {
        int power=prime[p-1];
        while (power<=i) {
            int temp=g[i-power][p-1]*power;
            if (g[i][p]==temp) {
                res.push_back(power);
                i-=power;
                break;
            }
            power*=prime[p-1];
        }
        p--;
    }
    cout<<g[n][prime.size()]<<endl;
    sort(res.begin(),res.end());
    for (auto i:res) cout<<i<<' ';
}


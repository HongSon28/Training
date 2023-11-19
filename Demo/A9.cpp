#include<bits/stdc++.h>
using namespace std;
const int N=5000,MX=sqrt(N);
vector<int>prime,v1;
vector<vector<int>>v2(N+5);
bool p[N+5];
bool used[(1<<19)+5];
int dp[(1<<19)+5];
int n,res;
int a[N+5];
void seive() {
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    for (int i=2;i<=N;i++) {
        if (p[i]) {
            prime.push_back(i);
            for (int j=i*i;j<=N;j+=i) p[j]=false;
        }
    }
}
int main() {
    seive();
    cout<<prime.size()<<endl;
    for (auto i:prime) cout<<i<<' ';
}

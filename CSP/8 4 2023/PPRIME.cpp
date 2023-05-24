#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
bool p[N+2];
vector<int>v;
void sang() {
    fill(p,p+N+2,true);
    p[0]=false;
    p[1]=false;
    for (int i=2;i<=N;i++) {
        if (p[i]==true) {
            v.push_back(i);
            for (int j=i*2;j<=N;j+=i) p[j]=false;
        }
    }
}
int rev(int n) {
    int s=0;
    while (n!=0) {
        s*=10;
        s+=n%10;
        n/=10;
    }
    return s;
}
int main() {
    freopen("PPRIME.INP","r",stdin);
    freopen("PPRIME.OUT","w",stdout);
    sang();
    int n;
    cin>>n;
    for (int i=0;i<v.size();i++) {
        if (v[i]>n) break;
        if (p[rev(v[i])]==true) cout<<v[i]<<' ';
    }
}

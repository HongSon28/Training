#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
vector<int>v;
void sang() {
    bool p[N+1];
    memset(p,true,sizeof(p));
    for (int i=2; i<=N;i++) {
        if (p[i]==true) {
            v.push_back(i);
            for (int j=i*2;j<=N;j+=i) p[j]=false;
        }
    }
}
int main() {
    int res=1;
    sang();
    int n;
    cin>>n;
    for (int i=0;i<v.size();i++) {
        int cnt=0;
        while (n%v[i]==0) {
            cnt++;
            n/=v[i];
        }
        res*=cnt+1;
    }
    if (n!=1) res*=2;
    cout<<res;
}

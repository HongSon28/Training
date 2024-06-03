#include<bits/stdc++.h>
using namespace std;
const int N=1000;
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
    sang();
    int n;
    cin>>n;
    for (int i=0;i<v.size();i++) {
        if (n%v[i]==0) {
            cout<<n/v[i];
            return 0;
        }
    }
    cout<<1;
}

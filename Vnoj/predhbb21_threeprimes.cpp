#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int k,cnt;
vector<int>prime;
int p[N+5];
void seive() {
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    for (int i=2;i<=N;i++) {
        if (p[i]) {
            prime.push_back(i);
            for (int j=i*2;j<=N;j+=i) p[j]=false;
        }
    }
}
int main() {
    seive();
    cin>>k;
    for (auto i:prime) {
        if (p[i*2-1]) {
            cnt++;
            if (cnt==k) {
                cout<<i<<' '<<i<<' '<<i*2-1;
                break;
            }
        }
        if (p[i*2+1]) {
            cnt++;
            if (cnt==k) {
                cout<<i<<' '<<i<<' '<<i*2+1;
                break;
            }
        }
    }
}

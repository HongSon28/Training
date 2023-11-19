#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,h;
bool p[N+5];
int res;
vector<int>prime;
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
int height (int m) {
    int sum=0;
    while (m>0) {
        sum+=m%10;
        m/=10;
    }
    return sum;
}
int main() {
    seive();
    cin>>n>>h;
    for (auto i:prime) {
        if (i>n) break;
        if (height(i)==h) {
            cout<<i<<'\n';
            res++;
        }
    }
    cout<<res;
}

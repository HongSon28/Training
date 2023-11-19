#include<bits/stdc++.h>
using namespace std;
const int N=7e6;
int n,k;
bool p[N+5];
vector<long long>v;
string s;
void seive() {
    memset(p,true,sizeof(p));
    for (long long i=2;i<=N;i++) {
        if (p[i]) {
            v.push_back(i);
            for (long long j=i*i;j<=N;j+=i) p[j]=false;
        }
    }
}
int main() {
    seive();
    cin>>n>>k;
    for (int i=0;i<n;i++) {
        s+=to_string(v[i]);
    }
}

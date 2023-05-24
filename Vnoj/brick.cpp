#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
vector<long long>prime;
vector<long long>mul;
void sang() {
    bool p[N+1];
    memset(p,true,sizeof(p));
    p[0]=false;
    p[1]=false;
    for (int i=2;i<=N;i++) {
        if (p[i]==true) {
            for (int j=i*2;j<=N;j+=i) {
                p[j]=false;
            }
        }
    }
    for (int i=2;i<=N;i++) {
        if (p[i]==true) {
            prime.push_back(i);
        }
    }
}
int main() {
    sang();
    int t;
    cin>>t;
    for (int i=0;i<prime.size()-1;i++) {
        mul.push_back(prime[i]*prime[i+1]);
    }
    for (int i=0;i<t;i++) {
        long long n;
        cin>>n;
        auto it=upper_bound(mul.begin(),mul.end(),n);
        it--;
        cout<<n-*it<<endl;
    }
}

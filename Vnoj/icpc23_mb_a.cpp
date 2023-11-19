#include<bits/stdc++.h>
using namespace std;
long long maxN=1e18;
vector<long long>fib;
void prep() {
    fib.push_back(1);
    fib.push_back(1);
    long long temp=2;
    while (temp<=maxN) {
        fib.push_back(temp);
        temp=fib[fib.size()-2]+fib.back();
    }
}
long long calc(long long n,long long lst) {
    if (n==1) return 1;
    long long ans=0;
    for (int i=0;i<=lst;i++) {
        if (fib[i]>=2&&n%fib[i]==0) ans+=calc(n/fib[i],i);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    prep();
    int t,n=fib.size();
    cin>>t;
    while (t--) {
        long long x;
        cin>>x;
        cout<<calc(x,n)<<endl;
    }
}

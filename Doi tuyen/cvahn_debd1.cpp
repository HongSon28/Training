#include<bits/stdc++.h>
using namespace std;
const int N=15000;
int n;
long long a[N+5],sum;
priority_queue<long long,vector<long long>,greater<long long>>q;
double res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) q.push(a[i]);
    while (q.size()>1) {
        long long x=q.top();
        q.pop();
        long long y=q.top();
        q.pop();
        q.push(x+y);
        res+=(double)(x+y)/20;
    }
    cout.precision(2);
    cout<<fixed<<res;
}

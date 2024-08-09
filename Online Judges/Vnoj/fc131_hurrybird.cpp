#include<bits/stdc++.h>
using namespace std;
int t;
long long n,m,x,y;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        cin>>n>>m>>x>>y;
        if (n>m) swap(n,m);
        if (n==1) {
            cout<<(m-1)*x<<endl;
            continue;
        }
        long long t1=x*(n+m-2);
        long long t2=(n-1)*y+(m-n)*x;
        long long t3;
        if (m%2==n%2) t3=y*(m-1);
        else t3=y*(m-2)+x;
        cout<<min({t1,t2,t3})<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
int t;
long long n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        cin>>n;
        if (n>=6) cout<<9<<'\n';
        else {
            long long mul=1;
            for (int i=1;i<=n;i++) mul*=i;
            while (mul>=10) {
                long long sum=0;
                while (mul!=0) {
                    sum+=mul%10;
                    mul/=10;
                }
                mul=sum;
            }
            cout<<mul<<'\n';
        }
    }
}

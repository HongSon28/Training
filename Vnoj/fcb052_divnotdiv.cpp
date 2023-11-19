#include<bits/stdc++.h>
using namespace std;
long long n,a,b,t;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        cin>>a>>b>>n;
        if (a%b==0) cout<<-1<<'\n';
        else {
            long long temp;
            if (n%a==0) temp=n;
            else temp=(n/a)*a+a;
            if (temp%b==0) temp+=a;
            cout<<temp<<'\n';
        }
    }
}

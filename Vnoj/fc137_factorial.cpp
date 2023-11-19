#include<bits/stdc++.h>
using namespace std;
int t;
string n;
int k;
int main() {
    cin>>t;
    while (t--) {
        cin>>n>>k;
        if (k==1) cout<<"YES"<<endl;
        else if (k==2) {
            if ((n[n.size()-1]-'0')%2==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        } else {
            int sum=0;
            for (auto i:n) sum+=i-'0';
            if (sum%3==0&&(n[n.size()-1]-'0')%2==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}

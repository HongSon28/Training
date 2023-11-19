#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,k;
string username[N+5],password[N+5];
int cnt[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>username[i]>>password[i];
    cin>>k;
    while (k--) {
        string x,p;
        cin>>x>>p;
        for (int i=1;i<=n;i++) {
            if (username[i]==x&&password[i]==p) cnt[i]++;
        }
    }
    for (int i=1;i<=n;i++) cout<<cnt[i]<<' ';
}

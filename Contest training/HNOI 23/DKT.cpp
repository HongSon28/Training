#include<bits/stdc++.h>
using namespace std;
long long n;
int main() {
    freopen("DKT.INP","r",stdin);
    freopen("DKT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    long long t;
    if (n%2==0) t=(((n/2)%26)*((n+1)%26))%26;
    else t=((n%26)*((n/2+1)%26))%26;
    cout<<char(t+'A');
}


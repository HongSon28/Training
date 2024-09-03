#include<bits/stdc++.h>
using namespace std;
const int N=30;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    unsigned long long res=1;
    cin>>n;
    for (int i=1;i<=n;i++) res*=2ll;
    cout<<res-n-1;
}
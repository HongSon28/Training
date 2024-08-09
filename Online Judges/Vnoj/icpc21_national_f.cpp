#include<bits/stdc++.h>
using namespace std;
int n;
long long res=1;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=2;i<=n;i++) res*=2;
    cout<<res;
}
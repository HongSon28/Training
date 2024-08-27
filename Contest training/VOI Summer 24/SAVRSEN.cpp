#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int a,b;
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>a>>b;
    vector<int>v(b+1);
    for (int d=1;d<=b;d++) {
    	for (int i=d*2;i<=b;i+=d) v[i]+=d;
    }
    for (int i=a;i<=b;i++) res+=abs(v[i]-i);
	cout<<res;
}
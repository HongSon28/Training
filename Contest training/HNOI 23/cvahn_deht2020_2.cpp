#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int c[N+5];
int res;
int main() {
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        c[t]++;
    }
    for (int i=1;i<=N;i++) res+=c[i]/i;
    cout<<res;
}

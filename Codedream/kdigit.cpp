#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,d;
void rec(int n){
    if(n==0) return;
    if(n%2==1) d++;
    rec(n/2);
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        rec(i);
        if(d==k) cnt++;
        d=0;
    }
    cout<<cnt;
}
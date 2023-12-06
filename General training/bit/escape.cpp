#include<bits/stdc++.h>
using namespace std;
const int N=20;
int res;
int n;
bool used[N+5];
string a[N+5];
void check() {
    for (int k=0;k<9;k++) {
        int sum=0;
        for (int i=1;i<=n;i++) {
            if (used[i]) {
                sum+=a[i][k]-'0';
            }
        }
        if (sum>=10) return;
    }
    int cnt=0;
    for (int i=1;i<=n;i++) {
        if(used[i]) cnt++;
    }
    res=max(res,cnt);
}
void rec(int k){
    used[k]=true;
    if (k==n) check();
    else rec(k+1);
    used[k]=false;
    if (k==n) check();
    else rec(k+1);
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        while (a[i].size()<9) a[i]='0'+a[i];
    }
    rec(1);
    cout<<res;
}

#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e6;
int a[10005];
bool c[N+5];
int res;
bool check(int a,int b,int c) {
    if (a+b>c&&a+c>b&&b+c>a) return true;
    return false;
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        c[a[i]]=true;
    }
    sort(a+1,a+1+n);
    for (int i=1;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            int dif=a[j]-a[i];
            if (a[j]+dif<=N&&c[a[j]+dif]) {
                int t=a[j]+dif;
                if (check(a[i],a[j],t)) res++;
            }
        }
    }
    cout<<res;
}

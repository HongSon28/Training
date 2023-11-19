#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
long long a[N+5];
long long n;
long long cnt;
bool check(long long a,long long b,long long c) {
    return (a+b>c);
}
bool check_acute(long long a,long long b,long long c) {
    return (a*a+b*b>c*c);
}
bool check_right(long long a,long long b,long long c) {
    return (a*a+b*b==c*c);
}
long long cnt_right() {
    long long ans=0;
    for (int i=1;i<n-1;i++) {
        long long k=i+2;
        long long last=0;
        for (int j=i+1;j<n;j++) {
            if (j!=i+1&&a[j]==a[j-1]) {
                ans+=last;
                continue;
            }
            long long temp=0;
            while (k<=n&&check_acute(a[i],a[j],a[k])) k++;
            while (k<=n&&check_right(a[i],a[j],a[k])) {
                k++;
                temp++;
            }
            last=temp;
            ans+=temp;
        }
    }
    return ans;
}
long long cnt_acute() {
    long long ans=0;
    for (long long i=1;i<=n-2;i++) {
        long long d=i+2;
        long long c=i+2;
        for (long long j=i+1;j<=n-1;j++) {
            while (c<=n&&check(a[i],a[j],a[c]))c++;
            cnt+=c-j-1;
            while (d<=n&&check_acute(a[i],a[j],a[d]))d++;
            if (d-1<=c) ans+=d-j-1;
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    long long right=cnt_right();
    long long acute=cnt_acute();
    long long obtuse=cnt-right-acute;
    cout<<acute<<' '<<right<<' '<<obtuse;
}

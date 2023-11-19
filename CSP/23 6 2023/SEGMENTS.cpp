#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
long long a[N+5];
long long cursum,sum;
int main() {
    freopen("SEGMENTS.INP","r",stdin);
    freopen("SEGMENTS.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    for (int i=1;i<=n;i++) {
        cursum+=a[i];
        if (sum%cursum==0) {
            long long temp=0;
            bool flag=true;
            for (int j=i+1;j<=n;j++) {
                temp+=a[j];
                if (temp==cursum) temp=0;
                else if (temp>cursum) {
                    flag=false;
                    break;
                }
            }
            if (flag) {
                cout<<sum/cursum;
                return 0;
            }
        }
    }
}

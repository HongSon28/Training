#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("Doanconm.inp","r",stdin);
    freopen("Doanconm.out","w",stdout);
    int n,res=INT_MIN;
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        int j=1,sum=a[i];
        res=max(res,sum);
        while (j<=n) {
            j++;
            i++;
            if (i>n) i=1;
            sum+=a[i];
            res=max(res,sum);
        }
    }
    cout<<res;
}

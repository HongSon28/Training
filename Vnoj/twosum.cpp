#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N=1e4;
ll a[N],res;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++) {
        int l=i,r=i+1,suml=a[i],sumr=a[i+1];
        while (l>=1&&r<=n) {
            if (suml>sumr) {
                r++;
                sumr+=a[r];
            } else if (suml<sumr) {
                l--;
                suml+=a[l];
            } else {
                if (r-l+1>res){
                    res=r-l+1;
                }
                l--;
                suml+=a[l];
                r++;
                sumr+=a[r];
            }
        }
    }
    cout<<res;
}

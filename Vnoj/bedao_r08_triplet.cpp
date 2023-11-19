#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    int c1=0,c2=0;
    cin>>n>>k;
    if (k%2==0) {
        for (int i=1;i<=n;i++) {
            if (i%k==0) c1++;
            else if (i%k==k/2) c2++;
        }
        //cout<<c1<<' '<<c2<<endl;
        cout<<c1*c1*c1+c2*c2*c2;
    } else {
        for (int i=1;i<=n;i++) {
            if (i%k==0) c1++;
        }
        cout<<c1*c1*c1;
    }
}

#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    int a[100];
    int b[100];
    cin>>t;
    for(int i=0; i<t;i++) {
        cin>>a[i];
    }
    for(int i=0; i<t;i++) {
        if ((a[i]<4)||(a[i]%2==1)) {
            cout<<"-1"<<endl;
        } else {
            b[i]=(a[i])/2;
            for (int j=1;j<=b[i]/2;j++) {
                cout<<(a[i]/2-j)*j<<" ";
            }
        }
    }
}



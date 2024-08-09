#include<bits/stdc++.h>
using namespace std;
int main() {
    int c;
    cin>>c;
    if (c==1) {
        cout<<"NO";
        return 0;
    }
    for (int i=1;i*i<=c;i++) {
        if (c%i==0) {
            int j=c/i;
            if (i%2==j%2) {
                cout<<"YES"<<endl;
                cout<<(i+j)/2<<" "<<abs(i-j)/2;
                return 0;
            }
        }
    }
    cout<<"NO";
}

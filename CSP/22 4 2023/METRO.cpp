#include<bits/stdc++.h>
using namespace std;
int n;
int d(int p,int q) {
    return (q-p+n)%n;
}
int main() {
    int q;
    cin>>q;
    while (q--) {
        int a,x,b,y;
        cin>>n>>a>>x>>b>>y;
        int ab=d(a,b),abn=d(a,b)+n;
        //cout<<ab/2<<' '<<d(a,x)<<' '<<d(y,b)<<endl;
        if (ab==0) {
            cout<<"YES"<<endl;
            continue;
        }
        if (ab%2==0&&ab/2<=d(a,x)&&ab/2<=d(y,b)) {
            cout<<"YES"<<endl;
            continue;
        }
        if (abn%2==0&&abn/2<=d(a,x)&&abn/2<=d(y,b)) {
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
}

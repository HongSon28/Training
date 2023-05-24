#include<bits/stdc++.h>
using namespace std;
int mx=3000001;
bool p[3000001];
bool c[3000001];
int psum[3000001];
int sum(int n) {
    int t=0;
    while (n!=0) {
        t+=n%10;
        n/=10;
    }
    return t;
}
void sang() {

    memset(p,true,sizeof(p));
    memset(c,false,sizeof(c));
    p[0]=false;
    p[1]=false;
    for (int i=2;i<mx;i++) {
        if (p[i]==true) {
            for (int j=i*2;j<mx;j+=i) {
                p[j]=false;
            }
        }
    }
    for (int i=2;i<mx;i++) {
        if (p[i]==true) {
            if (sum(i)%5==0) {
                c[i]=true;
            }
        }
    }
}
int main() {
    freopen("SPRIME.INP","r",stdin);
    freopen("SPRIME.OUT","w",stdout);
    sang();
    psum[0]=0;
    for (int i=1;i<mx;i++) {
        if (c[i]==false) {
            psum[i]=psum[i-1];
        } else {
            psum[i]=psum[i-1]+1;
        }
    }
    int t;
    cin>>t;
    for (int i=0;i<t;i++) {
        int l,r;
        cin>>l>>r;
        cout<<psum[r]-psum[l-1]<<endl;
    }
}

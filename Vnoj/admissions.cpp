#include<bits/stdc++.h>
using namespace std;
struct st {
    int math, it, id;
    bool cf;
};
bool compA (st x,st y) {
    if (x.math==y.math) return x.id<y.id;
    else return x.math>y.math;
}
bool compB (st x,st y) {
    if (x.it==y.it) return x.id<y.id;
    else return x.it>y.it;
}
bool compC (st x,st y) {
    if (x.math+x.it==y.math+y.it) return x.id<y.id;
    else return x.math+x.it>y.math+y.it;
}
bool compD (st x,st y) {
    return x.id<y.id;
}
int main() {
    int n,A,B,C;
    cin>>n>>A>>B>>C;
    vector<st>v(n);
    for (int t,i=0;i<n;i++) {
        cin>>t;
        v[i].math=t;
        v[i].id=i+1;
        v[i].cf=false;
    }
    for (int t,i=0;i<n;i++) {
        cin>>t;
        v[i].it=t;
    }
    sort(v.begin(),v.end(),compA);
    for (int i=0;i<n;i++) {
        if (A==0) break;
        if (v[i].cf==true) continue;
        else {
            v[i].cf=true;
            A--;
        }
    }
    sort(v.begin(),v.end(),compB);
    for (int i=0;i<n;i++) {
        if (B==0) break;
        if (v[i].cf==true) continue;
        else {
            v[i].cf=true;
            B--;
        }
    }
    sort(v.begin(),v.end(),compC);
    for (int i=0;i<n;i++) {
        if (C==0) break;
        if (v[i].cf==true) continue;
        else {
            v[i].cf=true;
            C--;
        }
    }
    sort(v.begin(),v.end(),compD);
    for (int i=0;i<n;i++) {
        if (v[i].cf==true) cout<<v[i].id<<endl;
    }
}

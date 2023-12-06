#include<bits/stdc++.h>
using namespace std;
bool p[1000000];
int res[1000000]={};
void sang(){
    memset(p,true,sizeof(p));
    p[0]=p[1]=false;
    for (long long i=2;i*i<=1000000;i++) {
        if (p[i]==true) {
            for (long long j=i*i; j*j<=1000000; j+=i)
                p[j]=false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sang();
    res[0]=0;
    for (int i=1;i<=1000000;i++) {
        if (p[i]==true) {
            res[i]=res[i-1]+1;
        } else {
            res[i]=res[i-1];
        }
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++) {
        int l,r;
        cin>>l>>r;
        cout<<res[r]-res[l-1]<<endl;
    }
}

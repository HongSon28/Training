#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
long long n,a[N+3],res=-1e18,temp,l,r,sa[N+3],s[N+3],j=1,b[N+3];
int main(){
    freopen("cseq.inp","r",stdin);
    freopen("cseq_nka.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sa[i]=sa[i-1]+a[i];
        b[i]=-a[i];
        s[i]=s[i-1]+b[i];
    }
    for(int i=1;i<=n;i++) {
        temp+=b[i];
        if(res<temp) {
            res=temp;
            l=j;
            r=i;
        }
        if(temp<0){
            temp=0;
            j=i+1;
        }
    }
    cout<<sa[n]-(sa[r]-sa[l-1])+s[r]-s[l-1];
}


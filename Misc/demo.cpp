#include <bits/stdc++.h>
using namespace std;
bool p[1000000];
void sang(int n){
    memset(p,true,sizeof(p));
    p[0] = p[1] = false;
    for (long long i=2; i*i <=n; i++) {
        if (p[i] == true)
            for (long long j=i*i; j*j<=n; j +=i)
                p[j] = false;
    }
}
bool check(long long a){
    for(long long i=2;i*i<=a;i++){
        if(a%i==0) return false;
    }
    return true;
}
int main(){
    long long n, i, j, a=0;
    cin>>n;
    sang(n);
    for(i=3;i*i<=n;i++){
            if(p[i]==true){
                j=i*i+4;
                if(check(j)==true && j<n){
                a++;
                cout<<2<<" "<<i<<" "<<j<<'\n';}
            }
    }
    if(a==0) cout<<-1;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
vector<int>v;
void sang() {
    bool p[N+1];
    memset(p,true,sizeof(p));
    for (int i=2; i<=N;i++) {
        if (p[i]==true) {
            v.push_back(i);
            for (int j=i*2;j<=N;j+=i) p[j]=false;
        }
    }
}
int uocso(long long n){
    long long a=1;
    for(int i=0;i<v.size();i++){
       long long dem=0;
       while(n%v[i]==0){
            dem++;
            n/=v[i];
       }
       a*=dem+1;
    }
    if(n!=1)
        a=a*2;
    return a;
}
int main(){
    long long n;
    sang();
    cin>>n;
    cout<<uocso(n);
}

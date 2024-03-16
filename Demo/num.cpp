#include<bits/stdc++.h>
#define int long long
using namespace std;
int k,num,s=9;
int power(int n, int x){
    int res=1;
    while(x--) res*=n;
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>k;
    while(num++ >=0){
        if(k>num*s){
            k-=num*s;
            s*=10;
        }else{
            int st=power(10,num-1),p=0;
            if(!(k%num)){
                p=st+k/num-1;
                k-=(k/num-1)*num;
            }else{
                p=st+k/num;
                k-=(k/num)*num;
            }
            string t=to_string(p);
            cout<<t[k-1];
            break;
        }
    }
}
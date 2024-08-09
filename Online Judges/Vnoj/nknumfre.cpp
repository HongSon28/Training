#include<bits/stdc++.h>
using namespace std;
int rev(int n) {
    vector<int> t;
    while (n>0) {
        int temp=n%10;
        n/=10;
        t.push_back(temp);
    }
    int res=0;
    for (int i=0;i<t.size();i++) {
        res*=10;
        res+=t[i];
    }
    return res;
}
int main() {
    int a,b,res=0;
    cin>>a>>b;
    for (int i=a;i<=b;i++) {
        //cout<<i<<' '<<rev(i)<<endl;
        if (__gcd(i,rev(i))==1) res++;
    }
    cout<<res;
}

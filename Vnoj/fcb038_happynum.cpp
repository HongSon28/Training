#include<bits/stdc++.h>
using namespace std;
bool check(int n) {
    map<int,int>mp;
    mp[n]=true;
    while (n!=1) {
        int sum=0;
        while (n>0) {
            sum+=(n%10)*(n%10);
            n/=10;
        }
        n=sum;
        if (mp[n]) return false;
        mp[n]=true;
    }
    return true;
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        if (check(n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

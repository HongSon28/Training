#include<bits/stdc++.h>
using namespace std;
int n;
int t,res=-1e9;
int main() {
    cin>>n;
    while (n--) {
        cin>>t;
        res=max(res,t);
    }
    cout<<res;
}

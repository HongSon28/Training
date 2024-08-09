#include<bits/stdc++.h>
using namespace std;
int t;
int a,b;
int res;
int main() {
    cin>>t;
    while (t--) {
        cin>>a>>b;
        res=0;
        while (a!=b) {
            a-=b;
            res++;
            if (a<b) swap(a,b);
        }
        cout<<res<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string fi[46];
    fi[0]="a";
    fi[1]="b";
    for (int i=2;i<=45;i++) {
        fi[i]=fi[i-2]+fi[i-1];
    }
    int t;
    cin>>t;
    for (int i=0;i<t;i++) {
        int n,k;
        cin>>n>>k;
        cout<<fi[n][k-1]<<endl;
    }
}

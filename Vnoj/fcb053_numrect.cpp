#include<bits/stdc++.h>
using namespace std;
int t;
long long m,n;
int main() {
    cin>>t;
    while (t--) {
        cin>>m>>n;
        m=(m+1)*m/2;
        n=(n+1)*n/2;
        cout<<m*n<<endl;
    }
}

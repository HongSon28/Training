#include<bits/stdc++.h>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    int fence=(n+m)*2;
    fence+=(m-1)*n;
    fence+=(n-1)*m;
    cout<<fence;
}

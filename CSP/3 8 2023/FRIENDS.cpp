#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
pair<int,int>p[N+5];
bool check(int i,int j) {
    for (int k=1;k<=n;k++) {
        if (k==i||k==j) continue;
        if (cal(i,j)>=(cal(i,j)))
    }
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (check(i,j)) cout<<i<<' '<<j<<endl;
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,x;
pair<int,int>p[N+5];
int main() {
    cin>>n>>x;
    for (int i=1;i<=n;i++) p[i]=make_pair(i-1,i+1);
    while (x--) {
        int i,j;
        cin>>i>>j;
        int left=p[i].first,right=p[i].second;
        p[left].second=right;
        p[right].first=left;
        left=p[j].first;
        p[left].second=i;
        p[i].first=left;
        p[i].second=j;
        p[j].first=i;
    }
    int f;
    for (int i=1;i<=n;i++) {
        if (p[i].first==0) {
            f=i;
            break;
        }
    }
    for (int i=1;i<=n;i++) {
        cout<<f<<' ';
        f=p[f].second;
    }
}

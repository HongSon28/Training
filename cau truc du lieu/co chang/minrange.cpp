#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int a[n+1];
    for (int i=1;i<=n;i++) cin>>a[i];
    deque<int>dq;
    for (int i=1;i<=n;i++) {
        while (dq.empty()==false&&a[dq.back()]>=a[i]) dq.pop_back();
        dq.push_back(i);
        if (dq.front()+k<=i) dq.pop_front();
        if (i>=k) cout<<a[dq.front()]<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k,cnt=1;
    cin>>n>>k;
    queue<int>q;
    q.push(n);
    while(q.empty()==false) {
        int x=q.front();
        q.pop();
        if ((x+k)%2==0&&x>k) {
            q.push((x+k)/2);
            q.push((x-k)/2);
            cnt++;
        }
    }
    cout<<cnt;
}

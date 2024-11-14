#include<bits/stdc++.h>
using namespace std;
vector<int>pos;
priority_queue<int,vector<int>,greater<int>>pq;
bool used[205];
int res[205];
int ask(int x,int y,int z) {
    cout<<x<<' '<<y<<' '<<z<<endl;
    int ans;
    cin>>ans;
    return ans;
}
void calc(int x) {
    int lo=0,hi=pos.size()-2,mid,ans;
    while (lo<=hi) {
        mid=(lo+hi)/2;
        int temp=ask(pos[mid],x,pos[mid+1]);
        if (temp==x) {
            ans=mid;
            break;
        }
        if (temp==pos[mid+1]) lo=mid+1;
        else hi=mid-1;
    }
    pos.insert(pos.begin()+ans+1,x);
}
int main() {
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) pq.push(i);
    while (pq.size()>2){
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        int z=pq.top();
        pq.pop();
        int ans=ask(x,y,z);
        if (ans!=x) pq.push(x);
        if (ans!=y) pq.push(y);
        if (ans!=z) pq.push(z);
    }
    while (!pq.empty()) {
        int temp=pq.top();
        pq.pop();
        used[temp]=true;
        pos.push_back(temp);
    }
    for (int i=1;i<=n;i++) {
        if (used[i]) continue;
        calc(i);
    }
    for (int i=0;i<pos.size();i++) res[pos[i]]=i+1;
    cout<<"OK ";
    for (int i=1;i<=n;i++) cout<<res[i]<<' ';
}

#include<bits/stdc++.h>
using namespace std;
int n,k,res;
queue<int>q;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    q.push(n);
    while (!q.empty()) {
    	int t=q.front();
    	q.pop();
    	if (t<=k||(t+k)%2!=0) res++;
    	else {
    		q.push((t+k)/2);
    		q.push((t-k)/2);
    	}
    }
    cout<<res;
}
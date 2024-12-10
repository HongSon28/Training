#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,l,r;
int a[N+5];
bool b[N+5];
int res=-1;
int main() {
	freopen("ROBOT.INP","r",stdin);
	freopen("ROBOT.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>l>>r;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	b[a[i]]=true;
    }
    if (n*r*2<l) {
    	cout<<-1;
    	return 0;
    }
    int cur=0,cnt=0,fi=0;
    queue<int>q;
    for (int i=0;i<=l;i++) {
    	res++;
    	if (b[i]) cnt++;
    	while (!q.empty()&&cnt) {
    		res+=(i-q.front())*2;
    		q.pop();
    		cnt--;
    	}
    	if (cur+r==i) {
    		cur+=2*r;
    		if (cnt==0) {
    			if (fi==0) fi=i;
    			q.push(i);
    		} else cnt--;
    		if (cur>=l&&q.empty()) break;
    	}
    }
    if ((n-1)*r*2>=l) res=min(res,l-r+(l-r-fi));
    else res=min(res,l+(l-fi));
    cout<<res;
}
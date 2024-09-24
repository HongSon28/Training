#include<bits/stdc++.h>
using namespace std;
const int N=70;
struct dat{
	int x[5];
};
int vis[N+1][N+1][N+1][N+1];
bool check(dat t) {
	if (t.x[1]<1||t.x[2]<1||t.x[3]<1||t.x[4]<1) return false;
	if (t.x[1]>N||t.x[2]>N||t.x[3]>N||t.x[4]>N) return false;
	for (int i=1;i<4;i++)
		for (int j=i+1;j<=4;j++)
			if (t.x[i]==t.x[j]) return false;
	if (vis[t.x[1]][t.x[2]][t.x[3]][t.x[4]]!=-1) return false;
	return true;
} 
queue<pair<dat,int>>q;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(vis,-1,sizeof(vis));
	vis[1][2][3][4]=0;
	dat temp;
	for (int i=1;i<=4;i++) temp.x[i]=i;
	q.push({temp,0});
	while (!q.empty()) {
		dat t=q.front().first;
		int cnt=q.front().second;
		q.pop();
		dat cur,cur2;
		for (int i=1;i<=4;i++) {
			cur=t;
			cur.x[i]--;
			cur2=cur;
			sort(cur2.x+1,cur2.x+5);
			if (check(cur2)) {
				vis[cur2.x[1]][cur2.x[2]][cur2.x[3]][cur2.x[4]]=cnt+1;
				//cout<<cur2.x[1]<<' '<<cur2.x[2]<<' '<<cur2.x[3]<<' '<<cur2.x[4]<<endl;
				q.push({cur2,cnt+1});
			}
			cur.x[i]+=2;
			cur2=cur;
			sort(cur2.x+1,cur2.x+5);
			if (check(cur2)) {
				vis[cur2.x[1]][cur2.x[2]][cur2.x[3]][cur2.x[4]]=cnt+1;
				//cout<<cur2.x[1]<<' '<<cur2.x[2]<<' '<<cur2.x[3]<<' '<<cur2.x[4]<<endl;
				q.push({cur2,cnt+1});
			}
			cur.x[i]--;
			for (int j=1;j<=4;j++) {
				if (j==i) continue;
				cur.x[i]=cur.x[j]+(cur.x[j]-cur.x[i]);
				cur2=cur;
				cur=t;
				sort(cur2.x+1,cur2.x+5);
				if (check(cur2)) {
					vis[cur2.x[1]][cur2.x[2]][cur2.x[3]][cur2.x[4]]=cnt+1;
					//cout<<cur2.x[1]<<' '<<cur2.x[2]<<' '<<cur2.x[3]<<' '<<cur2.x[4]<<endl;
					q.push({cur2,cnt+1});
				}
			}
		}
	}
	int t,x[5];
	cin>>t;
	while (t--) {
		cin>>x[1]>>x[2]>>x[3]>>x[4];
		sort(x+1,x+5);
		cout<<vis[x[1]][x[2]][x[3]][x[4]]<<'\n';
	}
}
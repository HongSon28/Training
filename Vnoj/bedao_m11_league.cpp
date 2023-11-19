#include<bits/stdc++.h>
using namespace std;
const int N=20;
struct team{
    int pnt,win,lose;
};
int n;
int a[N+5];
team Teams[N+5];
int max_point;
int max_gd=INT_MIN;
int max_goal;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n*(n-1);i++) {
        int ai,aj,x,y;
        cin>>ai>>aj>>x>>y;
        if (x>y) Teams[ai].pnt+=3;
        else if (x==y) {
            Teams[ai].pnt++;
            Teams[aj].pnt++;
        } else Teams[aj].pnt+=3;
        Teams[ai].win+=x;
        Teams[ai].lose+=y;
        Teams[aj].win+=y;
        Teams[aj].lose+=x;
    }
    for (int i=1;i<=n;i++) {
        if (Teams[i].pnt>max_point) {
            max_point=Teams[i].pnt;
            max_gd=Teams[i].win-Teams[i].lose;
            max_goal=Teams[i].win;
        } else if (Teams[i].pnt==max_point) {
            if (Teams[i].win-Teams[i].lose>max_gd) {
                max_gd=Teams[i].win-Teams[i].lose;
                max_goal=Teams[i].win;
            } else if (Teams[i].win-Teams[i].lose==max_gd) {
                if (Teams[i].win>max_goal) max_goal=Teams[i].win;
            }
        }
    }
    for (int i=1;i<=n;i++) {
        if (Teams[i].pnt==max_point&&Teams[i].win-Teams[i].lose==max_gd&&Teams[i].win==max_goal) cout<<i<<' ';
    }
}

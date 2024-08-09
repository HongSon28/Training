#include<bits/stdc++.h>
using namespace std;
const int N=1e6,M=1e3,SZ=1e3;
int n,x,y,res;
struct point{
    int x,y,id;
    bool operator < (const point &other) const {
        return y<other.y;
    }
};
vector<point>block[M+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        point temp;
        cin>>temp.x>>temp.y;
        temp.id=i;
        int id=temp.x/SZ;
        block[id].push_back(temp);
    }
    for (int i=0;i<=M;i++) {
        sort(block[i].begin(),block[i].end());
        if (i%2==0) {
            for (int j=0;j<block[i].size();j++) cout<<block[i][j].id<<' ';
        } else {
            for (int j=block[i].size()-1;j>=0;j--) cout<<block[i][j].id<<' ';
        }
    }
}


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int maxN = 50;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int type;

struct Node
{
    ll x, y, dist;
    Node(ll _x = 0, ll _y = 0, ll _dist = 0) : x(_x), y(_y), dist(_dist) {}

    bool operator < (const Node& other) const
    {
        return dist > other.dist;
    }
};

priority_queue<Node> pq;
ll a[maxN][maxN], d[3][maxN][maxN], dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, state[maxN][maxN];
pii b[5];
ll r1,c1,r2,c2,h,t, u1, v1, s1, u2, v2, s2;
pii trace[maxN][maxN];

void dijkstra(int sx, int sy, int k)
{
    for(int i = 1; i <= 16; i++)
    {
        for(int j = 1; j <= 16; j++)
        {
            d[k][i][j] = INFLL;
        }
    }
    memset(trace, -1, sizeof(trace));
    d[k][sx][sy] = 0;
    pq.push({sx, sy, 0});
    while(!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();
        int x = cur.x, y = cur.y;
        ll dist = cur.dist;
        if(dist > d[k][x][y]) continue;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 1 && nx <= 16 && ny >= 1 && ny <= 16 && a[nx][ny] >= 0)
            {
                if(d[k][nx][ny] > d[k][x][y] + 1)
                {
                    d[k][nx][ny] = d[k][x][y] + 1;
                    trace[nx][ny]={x,y};
                    pq.push({nx, ny, d[k][nx][ny]});
                }
            }
        }
    }
}
string hist[2][101];

namespace case1
{
    bool check()
    {
        for(int i = 1; i <= h; i++)
        {
            if(hist[1][i] != "X") return false;
        }
        return true;
    }

    bool valid(int x, int y)
    {
        return x >= 1 && x <= 16 && y >= 1 && y <= 16 && a[x][y] != -1;
    }

    int count_all() {
        int ans=0;
        for (int i=1;i<=16;i++) {
            for (int j=1;j<=16;j++) {
                ans+=(state[i][j]!=0 && a[i][j]>0);
            }
        }
        return ans;
    }

    void solve()
    {
        if (t-h<3 && count_all()==1 && state[u1][v1]==1) {
            cout<<"X";
            return;
        }
        if (h==0) {
            cout<<"X";
            return;
        } else {
            if (h==t-2) {
                if (check()) {
                    for(int i = 0; i < 4; i++)
                    {
                        if (valid(u1+dx[i],u2+dy[i])) {
                            if (dx[i]==1) {
                                cout<<"DU";
                            }
                            if (dx[i]==-1){
                                cout<<"UD";
                            }
                            if (dy[i]==1) {
                                cout<<"RL";
                            }
                            if (dy[i]==-1) {
                                cout<<"LR";
                            }
                        }
                    }
                    return;
                }
            }
            if (h==t-1) {
                string st=hist[0][h];
                if (st=="DU"||st=="UD"||st=="LR"||st=="RL") {
                    cout<<"X";
                    return;
                }
            }
            if (hist[1][h]!="*") {
                cout<<hist[1][h];
                return;
            }
        }
        cout << "X";
    }
}

namespace case3
{
    void solve()
    {
        if (state[u1][v1]!=1 && a[u1][v1]>0) {
            cout<<"X";
            return;
        }
        dijkstra(u1,v1,0);
        double mx=0;
        pii choice = {u1,v1};
        for (int i=1;i<=16;i++) {
            for (int j=1;j<=16;j++) {
                if (state[i][j]==1 || a[i][j]<=0) continue;
                double num=(d[0][i][j]+2)/3+1;
                double val = a[i][j];
                if (state[i][j]==2) val*=2;
                if (num>t-h) continue;
                double temp=val/num;
                if (temp>mx) {
                    mx=temp;
                    choice = {i,j};
                }
            }
        }
        if (choice == make_pair((int)u1,(int)v1) ) choice = {u2,v2};
        int tempx=choice.fi,tempy=choice.se;
        vector<pii>mov;
        while (tempx!=u1||tempy!=v1) {
            mov.push_back({tempx,tempy});
            pii cur = trace[tempx][tempy];
            tempx = cur.fi, tempy = cur.se;
        }
        mov.push_back({u1,v1});
        reverse(mov.begin(),mov.end());
        for (int i=1;i<=min((int)mov.size()-1,3);i++) {
            int difx=mov[i].fi-mov[i-1].fi;
            int dify=mov[i].se-mov[i-1].se;
            if (difx==-1) cout<<"U";
            if (difx==1) cout<<"D";
            if (dify==-1) cout<<"L";
            if (dify==1) cout<<"R";
        }
    }
}

namespace case2
{
    void solve()
    {
        int curx=r2,cury=c2, ftime = -1;
        for (int i=1; i<=h;i++) {
            if(hist[1][i] == "X" && a[curx][cury] > 0)
            {
                ftime = i;
                break;
            }
            if (hist[1][i]!="X" && hist[1][i]!="*") {
                for (auto c:hist[1][i]){
                    if (c=='L') cury--;
                    else if (c=='R') cury++;
                    else if (c=='U') curx--;
                    else curx++;
                }

            }
        }
        if(u1 == curx && v1 == cury && state[u1][v1] == 2)
        {
            cout << "X";
            return;
        } else
        {
            int mx = r1, my = c1;
            for (int i=1; i<=h;i++) {
                if (hist[0][i]!="X" && hist[0][i]!="*") {
                    for (auto c:hist[0][i]){
                        if (c=='L') my--;
                        else if (c=='R') my++;
                        else if (c=='U') mx--;
                        else mx++;
                    }

                } else if(hist[0][i] == "X" && mx == curx && my == cury)
                {
                    cout << hist[1][ftime + h - i + 1 ];
                    return;
                }
            }
        }
        dijkstra(u1,v1,0);
        int tempx=curx,tempy=cury;
        vector<pii>mov;
        while (tempx!=u1||tempy!=v1) {
            mov.push_back({tempx,tempy});
            pii cur = trace[tempx][tempy];
            tempx = cur.fi, tempy = cur.se;
        }
        mov.push_back({u1,v1});
        reverse(mov.begin(),mov.end());
        for (int i=1;i<=min((int)mov.size()-1,3);i++) {
            int difx=mov[i].fi-mov[i-1].fi;
            int dify=mov[i].se-mov[i-1].se;
            if (difx==-1) cout<<"U";
            if (difx==1) cout<<"D";
            if (dify==-1) cout<<"L";
            if (dify==1) cout<<"R";
        }
    }
}

bool isCase3()
{
    int posi=-1,posj=-1;
    pii pos2 = {r2, c2};
    for(int i = 1; i <= h; i++)
    {
        if (posi != -1 && posj != -1) break;
        if (hist[1][i]!="X"&&hist[1][i]!="*") {
            for (auto c:hist[1][i]) {
                if (c=='L') pos2.se--;
                else if (c=='R') pos2.se++;
                else if (c=='D') pos2.fi++;
                else pos2.fi--;
            }
        }
        pii pos1 = {r1,c1};
        for (int j = 1; j <= i; j++) {
            if (hist[0][j]!="X"&&hist[0][j]!="*") {
                for (auto c:hist[0][j]) {
                    if (c=='L') pos1.se--;
                    else if (c=='R') pos1.se++;
                    else if (c=='D') pos1.fi++;
                    else pos1.fi--;
                }
            }
        }
        for(int j = i+1; j <=h ; j++)
        {
            if (hist[0][j]!="X"&&hist[0][j]!="*") {
                for (auto c:hist[0][j]) {
                    if (c=='L') pos1.se--;
                    else if (c=='R') pos1.se++;
                    else if (c=='D') pos1.fi++;
                    else pos1.fi--;
                }
            }
            if (pos1 == pos2 && hist[1][i]=="X" && hist[0][j]=="X") {
                posi=i;
                posj=j;
                break;
            }
        }
    }
    if (posi==-1) return false;
    while (posi<=h && posj<=h) {
        if (hist[1][posi] != hist[0][posj]) return true;
        posi++;
        posj++;
    }
    return false;
}

int main()
{
    init();
    cin >> type;
    if(type == 1)
    {
        for(int i = 1; i <= 16; i++)
        {
            for(int j = 1; j <= 16; j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i = 0; i < 3; i++)
        {
            cin >> b[i].fi >> b[i].se;
            dijkstra(b[i].fi, b[i].se, i);
        }
        cin >> t;
        ll cur = INFLL;
        pii st = b[0];
        for(int i = 0; i < 3; i++)
        {
            ll mx = 0;
            for(int j = 0; j < 3; j++)
            {
                mx = max(mx, d[i][b[j].fi][b[j].se]);
            }
            if(mx < cur)
            {
                cur = mx;
                st = b[i];
            }
        }
        cout << st.fi << " " << st.se << '\n';
    } else if(type == 2)
    {
        for(int i = 1; i <= 16; i++)
        {
            for(int j = 1; j <= 16; j++)
            {
                cin >> a[i][j];
            }
        }for(int i = 1; i <= 16; i++)
        {
            for(int j = 1; j <= 16; j++)
            {
                cin >> state[i][j];
            }
        }
        cin >> u1 >> v1 >> s1 >> u2 >> v2 >> s2;
        cin>>r1>>c1>>r2>>c2>>h>>t;
        for (int i=1;i <= h;i++) cin>>hist[0][i] >> hist[1][i];
        if(r1 == c1 && r2 == c2)
        {
            case1::solve();
        } else
        {
            dijkstra(r1, c1, 0);
            if(d[0][r2][c2] < t)
            {
                if(!isCase3()) {
                    if (h<=t/3) {
                        case2::solve();
                        return 0;
                    }
                    else if (s2>0) {
                        case2::solve();
                        return 0;
                    }
                }
            }
            case3::solve();
        }
    }
}
/*
2
0 1 0 0 0 0 0 -1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 -1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

4 8 1 7 8 0

1 1 1 2 5 30
R X
X DDD
DDD RRR
RRR DDD
RRR RRR
*/

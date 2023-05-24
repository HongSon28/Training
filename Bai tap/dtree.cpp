#include <bits/stdc++.h>
using namespace std;
struct doan
{
    int x, type;
};
doan a[10000];
int n;
bool cmp (doan a, doan b)
{
    return a.x<b.x;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        memset(a,0,sizeof(a));
        int d=0;
        cin>>n;
        for(int x,r,i=1;i<=n;i++)
        {
            cin >> x >> r;
            a[++d]= {x-r, 0};
            a[++d]= {x+r, 1};
        }
        sort(a+1,a+1+n*2,cmp);
        int res = 0;
        d=0;
        for (int i=1; i<=2*n;i++)
        {
            if (d>0) res += a[i].x - a[i-1].x;
            if (a[i].type==0) d++;
            else d--;
        }
        cout << res <<endl;
    }
    return 0;
}

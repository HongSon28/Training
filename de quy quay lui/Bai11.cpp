#include<bits/stdc++.h>
using namespace std;
int n,m,res=INT_MAX;
int music[62];
bool used[32];
int a[32][32];
int price=0;
vector <int> resl;
vector <int> v;
bool check() {
    for (int i=1;i<=m;i++) {
        if (music[i]==0)
            return false;
    }
    return true;
}
void dequy(int k,int s) {
    for (int i=s;i<=n;i++) {
        if (used[i]==false) {
                v.push_back(i);
            used[i]=true;
            price+=a[i][0];
            for (int j=2;j<=a[i][1]+1;j++) {
                music[a[i][j]]++;
            }
            if(check()==true) {
                if (res>price) {
                    resl=v;
                    res=price;
                }
            } else {
                dequy(k+1,i+1);
            }
            used[i]=false;
            price-=a[i][0];
            for (int j=2;j<=a[i][1]+1;j++) {
                music[a[i][j]]--;
            }
            v.pop_back();
        }
    }
}
int main() {
    fill(music,music+62,0);
    memset(used,false,sizeof(used));
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i][0]>>a[i][1];
        for (int j=2;j<=a[i][1]+1;j++) {
            cin>>a[i][j];
        }
    }
    dequy(1,1);
    cout<<res<<endl;
    for (int i=0;i<resl.size();i++) {
        cout<<resl[i]<<" ";
    }
}

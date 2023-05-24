#include<bits/stdc++.h>
using namespace std;
int a,b;
bool check(int x,int y) {
    int temp1=abs(x-a),temp2=abs(y-b);
    if (temp1<=1&&temp2<=1)
        return true;
    return false;
}
int main() {
    int x=0,y=0;
    cin>>a>>b;
    int k;
    cin>>k;
    string s;
    cin>>s;
    int dem=0;
    if (check(x,y)==true) {
        cout<<"0"<<endl;
        dem++;
    }
    for (int j=1;j<=k;j++) {
        int i=j-1;
        if (s[i]=='R') {
            x++;
            if (check(x,y)==true) {
                cout<<j<<endl;
                dem++;
            }
        } else if (s[i]=='U') {
            y++;
            if (check(x,y)==true) {
                cout<<j<<endl;
                dem++;
            }
        } else if (s[i]=='L') {
            x--;
            if (check(x,y)==true) {
                cout<<j<<endl;
                dem++;
            }
        } else {
            y--;
            if (check(x,y)==true) {
                cout<<j<<endl;
                dem++;
            }
        }
    }
    if(dem==0) {
        cout<<"-1";
    }
}

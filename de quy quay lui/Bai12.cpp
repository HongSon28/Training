#include<bits/stdc++.h>
using namespace std;
int n,res=0,t=0;
int a[10][10];
int b[10][10];
int c[2]={-1,1};
int h=3;
int x=1,y=1;
int solvea() {
    int kq=0;
    while (true) {
        if (h==3) {
            while (a[x][y+1]==0) {
                a[x][y+1]=2;
                y++;
                kq++;
                cout<<x<<' '<<y<<endl;
            }
            h=2;
            if (a[x][y+1]==2)
                break;
            if (a[x+1][y]==1)
                break;
        }
        if (h==2) {
            while (a[x+1][y]==0) {
                a[x+1][y]=2;
                x++;
                kq++;
                cout<<x<<' '<<y<<endl;
            }
            h=1;
            if (a[x+1][y]==2)
                break;
            if (a[x][y-1]==1)
                break;
        }
        if (h==1) {
            while (a[x][y-1]==0) {
                a[x][y-1]=2;
                y--;
                kq++;
                cout<<x<<' '<<y<<endl;
            }
            h=4;
            if (a[x][y-1]==2)
                break;
            if (a[x+1][y]==1)
                break;
        }
        if (h==4) {
            while (a[x-1][y]==0) {
                a[x-1][y]=2;
                x--;
                kq++;
                cout<<x<<' '<<y<<endl;
            }
            h=3;
            if (a[x-1][y]==2)
                break;
            if (a[x][y+1]==1)
                break;
        }
    }
    return kq;
}
void dequy(int k) {
    int temp=0;
    if (k==1) {
        while (b[x][y-1]==0) {
            y--;
            b[x][y]=2;
            t++;
            temp++;
        }
    }
    else if (k==2) {
        while (b[x+1][y]==0) {
            x++;
            b[x][y]=2;
            t++;
            temp++;
        }
    }
    else if (k==3) {
        while (b[x][y+1]==0) {
            y++;
            b[x][y]=2;
            t++
            temp++;
        }
    } else {
        while (b[x-1][y]==0) {
            x--;
            b[x][y]=2;
            t++
            temp++;
        }
    }
    for (int i=0;i<=1;i++) {
        k=k+c[i];
        if (k==5) k=1;
        if (k==0) k=4;
        if (k==1) {
            if (b[x][y-1]==2) {
                res=max(res,t);
            } else if (b[x][y-1]==0) {
                dequy(k);
            }
        } else if (k==2) {
            if (b[x+1][y]==2) {
                res=max(res,t);
            } else if (b[x+1][y]==0) {
                dequy(k);
            }
        } else if (k==3) {
            if (b[x][y+1]==2) {
                res=max(res,t);
            } else if (b[x][y+1]==2) {
                dequy(k);
            }
        } else {
            if (b[x-1][y]==2) {
                res=max(res,t);
            } else if (b[x-1][y]==2) {
                dequy(k);
            }
        }
        t-=temp;

    }
}
int main() {
    fill(&a[0][0], &a[0][0] + 10,0);
    fill(&b[0][0], &b[0][0] + 10,0);
    cin>>n;
    for (int i=0;i<n;i++) {
        string temp;
        cin>>temp;
        int y=(int)temp[1]-48;
        int x=(int)temp[0]-64;
        a[x][y]=1;
        b[x][y]=1;
    }
    for (int i=0;i<=9;i++) {
        a[i][0]=1;
        a[0][i]=1;
        a[9][i]=1;
        a[i][9]=1;
        b[i][0]=1;
        b[0][i]=1;
        b[9][i]=1;
        b[i][9]=1;
    }
    x=1;
    y=1;
    cout<<solvea(3);
}

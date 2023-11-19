#include<bits/stdc++.h>
using namespace std;
char su[9][9];
bool row[9][10],col[9][10],tab[3][3][10];
void rec(int i,int j) {
    if (su[i][j]=='.') {
        for (int t=1;t<=9;t++) {
            if (row[i][t]) continue;
            if (col[j][t]) continue;
            int u=i/3,v=j/3;
            if (tab[u][v][t]) continue;
            su[i][j]=(char)t+'0';
            row[i][t]=true;
            col[j][t]=true;
            tab[u][v][t]=true;
            //cout<<i<<' '<<j<<' '<<t<<endl;
            if (i==8&&j==8) {
                for (int u=0;u<9;u++){
                    for (int v=0;v<9;v++)
                        cout<<su[u][v];
                    cout<<endl;
                }
                exit(0);
            }
            if (j==8) rec(i+1,0);
            else rec(i,j+1);
            su[i][j]='.';
            row[i][t]=false;
            col[j][t]=false;
            tab[u][v][t]=false;
        }
    } else {
        if (i==8&&j==8) {
            for (int u=0;u<9;u++){
                for (int v=0;v<9;v++)
                    cout<<su[u][v];
                cout<<endl;
            }
            exit(0);
        }
        if (j==8) rec(i+1,0);
        else rec(i,j+1);
    }
}
int main() {
    //freopen("SUDOKU.INP","r",stdin);
    //freopen("SUDOKU.OUT","w",stdout);
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            cin>>su[i][j];
            if (su[i][j]!='.') {
                int t=(int)su[i][j]-'0';
                row[i][t]=true;
                col[j][t]=true;
                int u=i/3,v=j/3;
                tab[u][v][t]=true;
            }
        }
    }
    rec(0,0);
    cout<<0;
}
/*
.....2.3.
374..6.2.
.....8.1.
258......
.........
......493
.4.1.....
.2.8..675
.6.5.....
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int m,n;
    int res=1000000000;
    cin>>m>>n;
    char a[m][n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for (int j=1;j<n;j++) {
        if (a[0][j]=='#'||a[0][j-1]=='#') {
            //cout<<a[0][j]<<endl;
            int p=0;
            bool flag=true;
            for (int i=1;i<m;i++) {
                if (a[i][j]=='#'||a[i][j-1]=='#') p+=0;
                else if (a[i][j]!='.'&&a[i][j-1]!='.') {
                    p+=min(a[i][j],a[i][j-1])-'0';
                }
                else if (a[i][j]!='.') {
                    p+=a[i][j]-'0';
                    //cout<<a[i][j]<<endl;
                }
                else if (a[i][j-1]!='.') {
                    p+=a[i][j-1]-'0';
                    //cout<<a[i][j-1]<<endl;
                }
                else {
                    flag=false;
                }
            }
            if (flag==true) {
                res=min(res,p);
            }
        } else if (a[0][j]!='.') {
            //cout<<a[0][j]<<endl;
            int p=a[0][j]-'0';
            bool flag=true;
            for (int i=1;i<m;i++) {
                if (a[i][j]=='#'||a[i][j-1]=='#') p+=0;
                else if (a[i][j]!='.'&&a[i][j-1]!='.') {
                    p+=min(a[i][j],a[i][j-1])-'0';
                }
                else if (a[i][j]!='.') {
                    p+=a[i][j]-'0';
                    //cout<<a[i][j]<<endl;
                }
                else if (a[i][j-1]!='.') {
                    p+=a[i][j-1]-'0';
                    //cout<<a[i][j-1]<<endl;
                }
                else flag=false;
            }
            if (flag==true) res=min(res,p);
        } else if (a[0][j-1]!='.') {
            //cout<<a[0][j-1]<<endl;
            int p=a[0][j-1]-'0';
            bool flag=true;
            for (int i=1;i<m;i++) {
                if (a[i][j]=='#'||a[i][j-1]=='#') p+=0;
                else if (a[i][j]!='.'&&a[i][j-1]!='.') {
                    p+=min(a[i][j],a[i][j-1])-'0';
                }
                else if (a[i][j]!='.') {
                    p+=a[i][j]-'0';
                    //cout<<a[i][j]<<endl;
                }
                else if (a[i][j-1]!='.') {
                    p+=a[i][j-1]-'0';
                    //cout<<a[i][j-1]<<endl;
                }
                else flag=false;
            }
            if (flag==true) res=min(res,p);
        }
    }
    if (res==1000000000) cout<<-1;
    else cout<<res;
}

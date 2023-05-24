#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int m=1;m<=t;m++){
        int n;
        cin>>n;
        char a[n+2][n+2],b[n+2][n+2];
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=n+1;j++){
                a[i][j]='.';
                b[i][j]='.';
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>a[i][j];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]=='.'){
                    b[i][j]='A';
                    while(b[i][j]==a[i-1][j]||b[i][j]==a[i+1][j]||b[i][j]==a[i][j-1]||b[i][j]==a[i][j+1]||b[i][j]==b[i-1][j]||b[i][j]==b[i][j-1]){
                        int temp=(int)b[i][j];
                        temp++;
                        b[i][j]=(char)temp;
                    }
                }
                else
                    b[i][j]=a[i][j];
            }
        }
        cout<<"Case "<<m<<":"<<'\n';
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<b[i][j];
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
}

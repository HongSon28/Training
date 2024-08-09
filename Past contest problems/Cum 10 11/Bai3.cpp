#include<bits/stdc++.h>
using namespace std;
int b[101][101];
bool check(int n) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (b[i][j]!=b[j][i]) return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    int a[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=n;i>=3;i--) {
        for (int p=0;p<=n-i;p++) {
            for (int q=0;q<=n-i;q++) {
                for (int m=p;m<p+i;m++) {
                    int r=m-p;
                    for (int n=q;n<q+i;n++) {
                        int s=n-q;
                        b[r][s]=a[m][n];
                    }
                }
                if (check(i)) {
                    cout<<p+1<<" "<<q+1<<" "<<i<<endl;
                    return 0;
                    break;
                }
            }
        }
    }
}

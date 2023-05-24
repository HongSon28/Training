#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp("matsym.inp");
    ofstream out("matsym.out");
    int n;
    inp>>n;
    int a[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            inp>>a[i][j];
        }
    }
    for (int i=n;i>=3;i--) {
        for (int p=0;p<=n-i;p++) {
            for (int q=0;q<=n-i;q++) {
                int b[i][i];
                for (int m=p;m<p+i;m++) {
                    int r=m-p;
                    for (int n=q;n<q+i;n++) {
                        int s=n-q;
                        b[r][s]=a[m][n];
                    }
                }
                int dem=0;
                for (int m=0;m<i;m++) {
                    for (int n=0;n<i;n++) {
                        if (b[m][n]==b[n][m])
                            dem+=1;
                    }
                }
                if (dem==i*i) {
                    out<<p+1<<" "<<q+1<<" "<<i<<endl;
                    return 0;
                    break;
                }
            }
        }
    }
}



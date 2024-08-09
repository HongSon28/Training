class Solution {
public:
    int N, cnt=0;
    int a[21];
    bool c1[13],c2[23],c3[23];
    bool check(int i,int j) {
        if (c1[j]==true&&c2[i-j+11]==true&&c3[i+j-2]==true)
            return true;
        return false;
    }
    void rec(int i) {
        for (int j=1;j<=N;j++) {
            if (check(i,j)==true) {
                c1[j]=false;
                c2[i-j+11]=false;
                c3[i+j-2]=false;
                a[i]=j;
                if (i==N)
                    cnt++;
                else
                    rec(i+1);
                c1[j]=true;
                c2[i-j+11]=true;
                c3[i+j-2]=true;
            }
        }
    }
    int totalNQueens(int n) {
        N=n;
        memset(c1,true,sizeof(c1));
        memset(c2,true,sizeof(c2));
        memset(c3,true,sizeof(c3));
        rec(1);
        return cnt;
    }
};

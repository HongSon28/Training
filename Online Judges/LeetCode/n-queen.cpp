class Solution {
public:
    int N, cnt=0;
    int a[21];
    bool c1[13],c2[23],c3[23];
    vector<vector<string>>res;
    bool check(int i,int j) {
        if (c1[j]==true&&c2[i-j+11]==true&&c3[i+j-2]==true)
            return true;
        return false;
    }
    void out() {
        vector<string>temp;
        for (int i=1;i<=N;i++) {
            string s;
            for (int j=1;j<a[i];j++) s+='.';
            s+='Q';
            for (int j=a[i]+1;j<=N;j++) s+='.';
            temp.push_back(s);
        }
        res.push_back(temp);
    }
    void rec(int i) {
        for (int j=1;j<=N;j++) {
            if (check(i,j)==true) {
                c1[j]=false;
                c2[i-j+11]=false;
                c3[i+j-2]=false;
                a[i]=j;
                if (i==N)
                    out();
                else
                    rec(i+1);
                c1[j]=true;
                c2[i-j+11]=true;
                c3[i+j-2]=true;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N=n;
        memset(c1,true,sizeof(c1));
        memset(c2,true,sizeof(c2));
        memset(c3,true,sizeof(c3));
        rec(1);
        return res;
    }
};

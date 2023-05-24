#include <bits/stdc++.h>
#define N 50000
using namespace std;
priority_queue<int>qp ;
int n;
int a[N+2] ;
int res=0 ;
int main()
{
    int t;
    cin >> t ;
    while (t--)
  {
    cout<<t<<endl;
    cin >> n ;
    for (int i=0;i<n;i++)
    {
        cin >> a[i] ;
        qp.push(a[i]) ;
    }
    for (int i=0;i<n;i++)
    {
        t=qp.top() ;
        int l;
        l+=a[i] ;
        res = l+(l-t) ;
        qp.pop() ;
    }
    cout << res << endl ;
  }


    return 0;
}

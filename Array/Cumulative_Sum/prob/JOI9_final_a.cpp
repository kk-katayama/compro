#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;cin >> n >> k;
  vector<int> s(n-1);
  rep(i,n-1) cin >> s[i];
  vector<int> a(k);
  rep(i,k) cin >> a[i];


  vector<int> sum(n);sum[0]=0;
  rep(i,n-1) sum[i+1] = sum[i] + s[i];
  int l=0;
  int res=0;
  rep(i,k){
    int r=l+a[i];

    res = (res+abs(sum[r]-sum[l]))%100000;
    l=r;
  }
  cout << res << "\n";
  
  return 0;
}

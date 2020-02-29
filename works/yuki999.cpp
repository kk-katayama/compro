#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n;cin >> n;
  vector<ll> a(2*n);
  rep(i,2*n) cin >> a[i];
  vector<ll> sum(n+1);
  sum[0] = 0;
  rep(i,n){
    sum[i+1] = sum[i]+a[2*i]-a[2*i+1];
  }
  ll res=-(1LL<<60);
  rep(i,n+1){
    res = max(res,2*sum[i]-sum[n]);
  }
  cout << res << "\n";
  return 0;
}

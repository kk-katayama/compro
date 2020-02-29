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
  vector<ll> a(n);rep(i,n) cin >> a[i];
  vector<ll> sum(n+1);
  sum[0] = 0;
  rep(i,n) sum[i+1] = sum[i]+a[i];
  rep1(i,n){
    ll res=0;
    for(int j=i;j<=n;++j){
      res = max(res,sum[j]-sum[j-i]);
    }
    cout << res << "\n";
  }

  return 0;
}

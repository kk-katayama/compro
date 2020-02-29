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
  ll sum = 0,sum2 = 0;
  rep(i,n){
    sum += a[i];
    if(i%2==1) sum2 += a[i];
  }

  ll x = sum/2-sum2;
  vector<ll> res(n);res[0] = 2*x;
  rep(i,n){
    x = a[i]-x;
    if(i==n-1) break;
    res[i+1] = 2*x;
  }
  rep(i,n) cout << res[i] << " ";
  cout  << "\n";
  
  return 0;
}

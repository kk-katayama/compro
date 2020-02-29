#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll l,r;cin >> l >> r;
  if(r-l>=2018) cout << 0 << "\n";
  else{
    ll in=3000;
    for(ll i=l;i<=r;++i)
      for(ll j=l;j<=r;++j){
	if(i==j) continue;
	in = min(in,(i*j)%2019);
      }
    cout << in << "\n";
  }

  return 0;
}

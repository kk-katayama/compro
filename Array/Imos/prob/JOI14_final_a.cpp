#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n,m;cin >> n >> m;
  vector<int> p(m);
  rep(i,m) {cin >> p[i];p[i]--;}
  vector<ll> a(n-1),b(n-1),c(n-1);
  rep(i,n-1) cin >> a[i] >> b[i] >> c[i];

  vector<ll> sim(n,0);
  rep(i,m-1){
    if(p[i]<p[i+1]){
      sim[p[i]]++;
      sim[p[i+1]]--;
    }
    else{
      sim[p[i+1]]++;
      sim[p[i]]--;
    }
  }
  vector<ll> imos(n-1,0);
  int cnt=0;
  rep(i,n-1){
    cnt += sim[i];
    imos[i] = cnt;
  }

  ll res = 0;
  rep(i,n-1){
    res += min(imos[i]*a[i],c[i]+imos[i]*b[i]);
  }
  cout << res << "\n";
  
  return 0;
}

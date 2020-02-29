#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  int res=0;
  int cnt=0;
  rep(i,n){
    if(h[i]>cnt){
      res += h[i]-cnt;
    }
    cnt = h[i];
  }
  cout << res << "\n";
  return 0;
}

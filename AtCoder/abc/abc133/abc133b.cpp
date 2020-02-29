#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,d;cin >> n >> d;
  vector<vector<int>> x(n,vector<int>(d));
  rep(i,n) rep(j,d) cin >> x[i][j];
  vector<int> sqr;
  rep1(i,200) sqr.push_back(i*i);

  int res=0;
  rep(i,n) rep(j,n){
    if(i>=j) continue;
    int tmp=0;
    rep(k,d){
      tmp += (x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
    }
    bool f = false;
    rep(k,sqr.size()){
      if(tmp==sqr[k]){
	f = true;break;
      }
    }
    if(f) res++;
  }
  cout << res << "\n";
  return 0;
}

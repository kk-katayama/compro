#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> p(n);
  rep(i,n) cin >> p[i];
  int res=0;
  rep(i,n-2){
    vector<int> tmp(3);
    int a = p[i+1];
    rep(j,3) tmp[j] = p[i+j];
    sort(tmp.begin(), tmp.end());
    if(a==tmp[1]) res++;
  }
  cout << res << "\n";
  return 0;
}

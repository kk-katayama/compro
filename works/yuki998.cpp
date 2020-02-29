#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  vector<int> a(4);
  rep(i,4) cin >> a[i];
  sort(a.begin(), a.end());
  bool f = true;
  rep(i,3){
    if(a[i]+1!=a[i+1]) f=false;
  }
  if(f) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}

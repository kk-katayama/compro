#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i,n) cin >> d[i];
  sort(d.begin(), d.end());
  cout << d[n/2]-d[n/2-1] << "\n";
  return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,a,b;cin >> n >> a >> b;
  cout << min(n*a,b) << "\n";
  return 0;
}

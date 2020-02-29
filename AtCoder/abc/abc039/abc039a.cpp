#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int a,b,c;cin >> a >> b >> c;
  cout << 2*a*b+2*b*c+2*c*a << "\n";
  return 0;
}

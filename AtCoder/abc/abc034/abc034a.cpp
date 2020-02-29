#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int x,y;
  cin >> x >> y;
  if(x<y) cout << "Better" << "\n";
  else cout << "Worse" << "\n";
  return 0;
}

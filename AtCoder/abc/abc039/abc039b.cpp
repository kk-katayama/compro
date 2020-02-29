#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll x;cin >> x;
  for(ll i=1;i<=1000;++i){
    if(i*i*i*i==x){
      cout << i << "\n";
      return 0;
    }
  }
  return 0;
}

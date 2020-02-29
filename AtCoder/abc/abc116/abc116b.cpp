#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll s;cin >> s;
  ll res=1;
  map<ll,int> mp;
  while(1){
    if(mp[s]==1){
      break;
    }
    mp[s]++;
    if(s%2==0) s /= 2;
    else s = s*3+1;
    res++;
  }
  cout << res << "\n";
  return 0;
}

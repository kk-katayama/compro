#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template <typename X>
struct BIT
{
  vector<X> dat;
  int n;

  BIT(int _n){
    n = _n+1;
    dat.assign(n,0);
  }
  
  X sum(int i)
  {
    X s = 0;
    while(i > 0){
      s += dat[i];
      i -= i&(-i);
    }
    return s;
  }

  void add(int i,X x)
  {
    while(i<=n){
      dat[i] += x;
      i += i&(-i);
    }
  }
};

int main()
{
  int n;cin >> n;
  vector<int> t(n),x(n);
  rep(i,n) cin >> t[i] >> x[i];

  BIT<int> bt(210000);
  rep(i,n){
    if(t[i]==1) bt.add(x[i],1);
    else{
      int left=0,right=210000;
      while(right-left>1){
	int mid=(right+left)/2;
	if(bt.sum(mid)>=x[i]) right=mid;
	else left=mid;
      }
      cout << right << "\n";
      bt.add(right,-1);
    }
  }
  return 0;
}

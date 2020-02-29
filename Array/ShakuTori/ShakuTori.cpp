#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template <typename X>
struct ShakuTori{
  vector<X> array;
  int n;
  vector<X> sum;
  
  ShakuTori(vector<X> _array)
  {
    array = _array;
    n = array.size();    
  }
  //累積和作成、最初にやる
  void make_sum()
  {
    sum.resize(n+1);
    sum[0] = 0;
    rep(i,n){
      sum[i+1] = sum[i]+array[i];
    }
  }
  
  //[l,r)の和array[l]+...+array[r-1]を返す
  X segsum(int l,int r)
  {
    return sum[r] - sum[l];
  }
  
  int worm_count(X x)
  {
    int res = 0;
    int l = 0,r = 1;
    X sum = segsum(l,r);
    while(1){
      while(sum<=x){
	res += r - l;
	cout << l << " " << r << "\n";
	r++;
	if(r == n+1) break;	
	sum = segsum(l,r);
      }
      if(r == n+1) break;
      l++;
      sum = segsum(l,r);
    }
    return res;
  }
    
};

int main()
{
  int n,q;
  cin >> n >> q;
  vector<ll> a(n);
  vector<ll> z(q);
  rep(i,n) cin >> a[i];
  rep(i,q) cin >> z[i];
  
  ShakuTori<ll> arr(a);
  arr.make_sum();
  
  rep(i,q) cout << arr.worm_count(z[i]) << "\n";
  

  
  return 0;
}

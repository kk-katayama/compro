#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template <typename X>
class DST
{
private:
  int n;
  vector<X> dat,delay,arr;
  const X init = 0;

  void eval(int k,int l,int r)
  {
    if(delay[k] != 0){
      if(k>=n-1) dat[k] += delay[k]*arr[k];
      else if(k<n-1){
	delay[2*k+1] += delay[k]/2;
	delay[2*k+2] += delay[k]/2;
      }
      delay[k] = 0;
    }
  }
  

  
public:  
  DST(int _n,vector<X> _arr)
  {
    n = 1;
    while(n < _n) n *= 2;
    dat.assign(2*n-1,init);
    delay.assign(2*n-1,init);
    arr.resize(2*n-1,init);
    rep(i,_arr.size()){
      arr[n-1+i]=_arr[i];
    }
  }

  void update(int a,int b,X x,int k,int l,int r)
  {
    eval(k,l,r);
    
    if(r<=a||b<=l) return ;
    
    if(a<=l&&r<=b){
      delay[k] += (r-l)*x;
      eval(k,l,r);
    }
    else{
      update(a,b,x,2*k+1,l,(l+r)/2);
      update(a,b,x,2*k+2,(l+r)/2,r);
      //      dat[k] = dat[2*k+1] + dat[2*k+2];
    }
  }

  void query(int a,X x,int k,int l,int r)
  {
    eval(k,l,r);
    if(a<l||r<=a) return ;

    if(k>=n-1) arr[k] += x;
    else{
      query(a,x,2*k+1,l,(l+r)/2);
      query(a,x,2*k+2,(l+r)/2,r);      
    }
  }

  int size(){
    return n;
  }

  int get_dat(int x){
    return dat[n-1+x];
  }    
  
  void all_eval(){
    rep(i,2*n-1){
      eval(i,0,0);
    }
  }
  
  void show(){
    int index = 0;
    int num = 1;
    while(index<n){
      rep(i,num){
	cout << dat[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;
    }
    index = 0;
    num = 1;
    while(index<n){
      rep(i,num){
	cout << delay[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;    
    }
    index = 0;
    num = 1;
    while(index<n){
      rep(i,num){
	cout << arr[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;    
    }    
  }

  void solve(int nn){
    rep(i,nn) cout << dat[n-1+i] << " ";
    cout  << "\n";
  }
  
};



int main()
{
  int n,q;cin >> n >> q;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  DST<ll> dst(n,a);
  rep(i,q){
    char c;int x,y;
    cin >> c >> x >> y;
    if(c=='A'){
      dst.query(x-1,y,0,0,dst.size());
    }
    else{
      dst.update(x-1,y,1,0,0,dst.size());
    }
    //    dst.show();
  }  
  dst.all_eval();
  //  dst.show();
  dst.solve(n);
  
  return 0;
}

# Bellmanford

最短経路問題を解くアルゴリズムの一つ  

頂点sをスタートにする  
d[i] := 頂点sから頂点iに行くのにかかる最短コスト  
初期値は  
d[s]=0  
d[i]=INF (i!=s)  

* 全ての辺について以下の操作をする  
頂点v→wにコストcで行く辺があったとする。  
d[v]!=INFかつd[w]>d[v]+cならば、d[w]=d[v]+cと更新する。

この操作を(頂点の数)回繰り返すと全ての頂点に対して最短距離が求まる。ただし、負閉路があるときは、最短距離の更新が無限に続く。

* 負閉路の検出  
負閉路があるときは最短距離の更新が無限に続くことを用いて負閉路を検出する。  
具体的には更新フラグを持っておき、頂点数を越える回数目でも更新がされているようなら負閉路が存在。  




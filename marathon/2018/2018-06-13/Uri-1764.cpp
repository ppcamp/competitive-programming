/** Uri:1764
 * Problem: Itinerário do Papai Noel
 * Subject: Grafos/Kruskal
 **/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

struct route
{
  int _x, _y, _z;
  route() {}
  route(int x, int y, int z) : _x(x), _y(y), _z(z){};
};

class UnionFind
{
private:
  vi p, rank, setSize; // most-closed parent, pos,
  int numSets;

public:
  UnionFind(int N)
  {
    setSize.assign(N, 1);
    numSets = N;
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++)
      p[i] = i;
  }

  int findSet(int i)
  {
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  }
  bool isSameSet(int i, int j)
  {
    return findSet(i) == findSet(j);
  }

  bool unionSet(int i, int j)
  {
    if (!isSameSet(i, j))
    {
      numSets--;
      int x = findSet(i), y = findSet(j);
      // rank is used to keep the tree short
      if (rank[x] > rank[y])
      {
        p[y] = x;
        setSize[x] += setSize[y];
      }
      else
      {
        p[x] = y;
        setSize[y] += setSize[x];
        if (rank[x] == rank[y])
          rank[y]++;
      }
      return true;
    }
    return false;
  }
  int numDisjointSets()
  {
    return numSets;
  }
  int sizeOfSet(int i)
  {
    return setSize[findSet(i)];
  }
  void clear()
  {
    p.clear();
    rank.clear();
    setSize.clear();
    numSets = 0;
  }
};

bool s_compare(route x, route y)
{
  return x._z < y._z;
}

int main()
{
  ll m, n, count;

  while ((cin >> m >> n) && (n | m))
  {
    count = 0;
    UnionFind UF(m);
    vector<route> vr(n);
    for (auto &i : vr)
      cin >> i._x >> i._y >> i._z;
    sort(vr.begin(), vr.end(), s_compare);
    for (auto i : vr)
      if (UF.unionSet(i._x, i._y))
        count += i._z;
    cout << count << endl;
    UF.clear();
  }
  return 0;
}
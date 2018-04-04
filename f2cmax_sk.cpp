/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>
#include "optimization.h" // http://acm.math.spbu.ru/~sk1/algo/lib/optimization.h.html

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n = readInt();
  vector<int> a(n), b(n), p1, p2;
  forn(i, n) a[i] = readInt();
  forn(i, n) b[i] = readInt();
  forn(i, n) (a[i] <= b[i] ? p1 : p2).push_back(i);
  sort(p1.begin(), p1.end(), [&]( int i, int j ){ return a[i] < a[j]; });
  sort(p2.begin(), p2.end(), [&]( int i, int j ){ return b[i] > b[j]; });
  p1.insert(p1.end(), p2.begin(), p2.end());

  long long ta = 0, tb = 0;
  for (int i : p1)
    tb = max(ta += a[i], tb) + b[i];
  
  writeInt(tb, '\n');
  forn(t, 2)
    forn(i, n)
      writeInt(p1[i] + 1, " \n"[i == n - 1]);
}

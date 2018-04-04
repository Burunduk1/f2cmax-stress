/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int n;
vector<int> a, b;

int solve_ok() {
  struct job {
    int a, b, id;
    int type() const {
      return a <= b;
    }
    bool operator<(const job& j) const {
      if (type() != j.type())
        return type() > j.type();
      return type() ? a < j.a : b > j.b;
    }
  };

  vector<job> j(n);
  for (int i = 0; i < n; i++) {
    j[i] = {a[i], b[i], i + 1};
  }
  sort(j.begin(), j.end());
  long long t1 = 0;
  long long t2 = 0;
  for (int i = 0; i < n; i++) {
    t1 += j[i].a;
    t2 = max(t1, t2) + j[i].b;
  }
  return t2;
}

enum {BUBBLE_SORT, STD_SORT, STD_STABLE_SORT, SPLIT_SORT, ALL_SORTS, EMAXX_SORT};

int solve_emaxx() {
  struct item {
    int a, b, id;
   
    bool operator< (item p) const {
      return min(a,b) < min(p.a,p.b);
    }
  };
  vector<item> v(n);
  forn(i, n) v[i].a = a[i];
  forn(i, n) v[i].b = b[i];
  forn(i, n) v[i].id = i;
  sort(v.begin(), v.end());
  vector<item> a, b;
  forn(i, n)
    (v[i].a <= v[i].b ? a : b).push_back (v[i]);
  a.insert(a.end(), b.rbegin(), b.rend());
  
  long long t1 = 0, t2 = 0;
  forn(i, n) {
    t1 += a[i].a;
    t2 = max(t2, t1) + a[i].b;
  }  
  return t2;
}

int solve_wa( int sort_type ) {
  if (sort_type == EMAXX_SORT) {
    return solve_emaxx();
  }

  int p[n];
  forn(i, n) p[i] = i;
  auto less = [&]( int i, int j ){ return min(a[i], b[j]) < min(a[j], b[i]); };

  if (sort_type == STD_SORT) {
    sort(p, p + n, less);
  } else if (sort_type == STD_STABLE_SORT) {
    stable_sort(p, p + n, less);
  } else if (sort_type == BUBBLE_SORT) {
    forn(i, n)
      forn(j, n - 1)
        if (less(p[j + 1], p[j]))
          swap(p[j], p[j + 1]);
  } else if (sort_type == SPLIT_SORT) {
    sort(p, p + n, less);
    vector<int> p1, p2;
    forn(i, n)
      (a[p[i]] <= b[p[i]] ? p1 : p2).push_back(p[i]);
    int k = 0;
    for (int i : p1) p[k++] = i;
    for (int j : p2) p[k++] = j;
  } else {
    assert(0); // invalid sort type
  }

  long long ta = 0, tb = 0;
  forn(i, n) 
    tb = max(ta += a[p[i]], tb) + b[p[i]];
  return tb;  
}

void output_test() {
    printf("%d\n", n);
    forn(i, n) printf("%d%c", a[i], " \n"[i == n - 1]);
    forn(i, n) printf("%d%c", b[i], " \n"[i == n - 1]);
    // forn(i, n) printf("%d %d\n", a[i], b[i]);
}

int __id = 1;
#define GET(type, var) if (__id >= argc) Usage(); type var; { std::stringstream ss(argv[__id++]); assert(ss >> (var)); }
#define GET_IF(type, var, default) type var; if (__id >= argc) var = default; else { std::stringstream ss(argv[__id++]); assert(ss >> (var)); }

void Usage() {
  puts("Usage: <n> <min> <max> <sort_type>");
  puts("  generates n numbers in [min..max]");
  printf("  sort_type: %d=bubble, %d=std::sort, %d=std::stable_sort, %d=split_sort, %d=ALL, %d=emaxx\n", 
    BUBBLE_SORT, STD_SORT, STD_STABLE_SORT, SPLIT_SORT, ALL_SORTS, EMAXX_SORT);
  exit(1);
}

int main( int argc, char *argv[] ) {
  GET(int, n);
  GET(int, A);
  GET(int, B);
  GET(int, sort_type);
  a.resize(n), b.resize(n);
  for (int t = 0, next = 1;; t++) {
    if (t == next) fprintf(stderr, "[%d tests passed]\n", t), next *= 2;
    ::n = n;
    forn(i, n) a[i] = rand() % (B - A + 1) + A;
    forn(i, n) b[i] = rand() % (B - A + 1) + A;
    long long answer = solve_ok();
    if (sort_type == ALL_SORTS) {
      const int sorts = ALL_SORTS;
      long long results[sorts];
      bool good = 1;
      forn(i, sorts)
        results[i] = solve_wa(i), good &= (results[i] != answer);
      if (good) {
        printf("test found [#%d]: answer = %lld, outputs = ", t, answer);
        forn(i, sorts)
          printf("%lld%c", results[i], " \n"[i == sorts - 1]);
        output_test();
        return 0;

      }
    } else {
      long long output = solve_wa(sort_type);
      if (answer != output) {
        printf("test found [#%d]: answer = %lld, output = %lld\n", t, answer, output);
        output_test();
        return 0;
      }
    }
  }
}

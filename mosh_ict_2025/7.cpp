/*
TASK 7
68/100 points
solution by @PD758
*/

#include <functional>
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>

template <typename T>
class SegTree {
 public:
  SegTree(size_t n, std::function<T(const T&, const T&)> reduce)
      : reduce(reduce), size(n), tree(4 * n) {}

  void insert(size_t index, T&& val) {
    if (index >= size) throw std::out_of_range("Index OoR");
    insert(0, 0, size - 1, index, std::move(val));
  }

  template <typename... Args>
  inline void emplace(size_t index, Args... args) {
    insert(index, T(args...));
  }

  const T& get(size_t index) const {
    if (index >= size) throw std::out_of_range("Index OoR");
    return tree[index + size];
  }

  T get(size_t l, size_t r) const {
    if (l > r || l >= size || r >= size)
      throw std::out_of_range("Invalid range");
    return get(0, 0, size - 1, l, r);
  }

 private:
  std::function<T(const T&, const T&)> reduce;
  size_t size;
  std::vector<T> tree;

  void insert(size_t v, size_t tl, size_t tr, size_t pos, T&& new_val) {
    if (tl == tr)
      tree[v] = std::move(new_val);
    else {
      size_t tm = (tl + tr) / 2;
      if (pos <= tm)
        insert(2 * v + 1, tl, tm, pos, std::move(new_val));
      else
        insert(2 * v + 2, tm + 1, tr, pos, std::move(new_val));
      tree[v] = reduce(tree[2 * v + 1], tree[2 * v + 2]);
    }
  }

  T get(size_t v, size_t tl, size_t tr, size_t l, size_t r) const {
    if (l > r) return T();
    if (l == tl && r == tr) return tree[v];
    size_t tm = (tl + tr) / 2;
    return reduce(get(2 * v + 1, tl, tm, l, std::min(r, tm)),
                  get(2 * v + 2, tm + 1, tr, std::max(l, tm + 1), r));
  }
};

struct ModaVault {
  using _mp = std::unordered_map<int, int>;
  _mp counts;
  int max_v = 0;
  int max_vv = 0;
  bool cpmveq = true;

  ModaVault() {}
  ModaVault(const int& v) {
    counts[v]++;
    max_v = v;
    max_vv = 1;
    cpmveq = false;
  }

  ModaVault(const ModaVault& mv)
      : counts(mv.counts),
        max_v(mv.max_v),
        max_vv(mv.max_vv),
        cpmveq(mv.cpmveq) {}

  ModaVault& operator=(const ModaVault& mv) {
    counts = mv.counts;
    max_v = mv.max_v;
    max_vv = mv.max_vv;
    cpmveq = mv.cpmveq;
    return *this;
  }

  void addNew(const int& v) {
    counts[v]++;
    if (counts[v] > max_vv) {
      max_vv = counts[v];
      max_v = v;
    }
  }

  inline bool empty() const { return max_vv < 1; }

  void find_max() {
    max_vv = 0;
    cpmveq = true;
    for (const std::pair<int, int>& p : counts) {
      if (p.second > max_vv) {
        max_v = p.first;
        max_vv = p.second;
        cpmveq = false;
      } else if (p.second == max_vv) {
        cpmveq = true;
      }
    }
  }

  void merge(const ModaVault& other) {
    if (other.empty()) return;
    if (empty()) {
      counts = other.counts;
      max_v = other.max_v;
      max_vv = other.max_vv;
      return;
    }
    _mp cp(other.counts);
    counts.merge(cp);
    for (const std::pair<int, int>& p : cp) counts[p.first] += p.second;
    find_max();
  }

  inline int get_moda() const { return max_v; }
};

/*ostream& operator<<(ostream& os, const ModaVault& mv) {
    os << "{mx_v=" << mv.max_v << " ctn=" << mv.max_vv << " eq=" << mv.cpmveq <<
" data={"; for (const pair<int, int>& p : mv.counts) { cout << p.first << ':' <<
p.second << ", ";
    }
    cout << "}}";
    return os;
}*/

ModaVault reduce(const ModaVault& m1, const ModaVault& m2) {
  // cout << "merging " << m1 << ' ' << m2 << endl;
  ModaVault nw(m1);
  if (!m1.empty() && !m2.empty())
    nw.merge(m2);
  else if (m1.empty())
    nw = m2;
  // cout << "new st " << nw << endl;
  return nw;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  /*SegTree<ModaVault> test(5, reduce);
  test.emplace(0, 1);
  test.emplace(1, 1);
  test.emplace(2, 3);
  test.emplace(3, 3);
  test.emplace(4, 5);
  cout << test.get(1, 3).get_moda() << endl;*/
  int n, q, tmp;
  std::cin >> n >> q;

  SegTree<ModaVault> st(n, reduce);

  for (int i = 0; i < n; i++) {
    std::cin >> tmp;
    st.emplace(i, tmp);
  }

  int l, r;
  for (int i = 0; i < q; i++) {
    std::cin >> l >> r;
    l--;
    r--;
    ModaVault res = st.get(l, r);
    if (res.cpmveq || res.max_vv <= (r - l + 1) / 2) {
      std::cout << "-1" << '\n';
    } else {
      std::cout << res.get_moda() << '\n';
    }
  }

  std::cout.flush();
  return 0;
}

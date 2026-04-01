// #include <climits>
// #include <iostream>

// struct item {
//   int key, prior;
//   item *l, *r;
//   item() {}
//   item(int key) : key(key), prior(rand()), l(nullptr), r(nullptr) {}
//   item(int key, int prior) : key(key), prior(prior), l(nullptr), r(nullptr)
//   {}
// };

// typedef item* pitem;

// void split(pitem t, int key, pitem& l, pitem& r) {
//   if (!t) {
//     l = r = nullptr;
//   } else if (t->key <= key) {
//     split(t->r, key, t->r, r), l = t;
//   } else {
//     split(t->l, key, l, t->l), r = t;
//   }
// }

// void insert(pitem& t, pitem it) {
//   if (!t) {
//     t = it;
//   } else if (it->prior > t->prior) {
//     split(t, it->key, it->l, it->r), t = it;
//   } else {
//     insert(t->key <= it->key ? t->r : t->l, it);
//   }
// }

// void merge(pitem& t, pitem l, pitem r) {
//   if (!l || !r) {
//     t = l ? l : r;
//   } else if (l->prior > r->prior) {
//     merge(l->r, l->r, r), t = l;
//   } else {
//     merge(r->l, l, r->l), t = r;
//   }
// }

// class solution {
//   pitem tree = nullptr;

//   int pitem_find_min(pitem node, int key) {
//     if (node == nullptr) {
//       return INT_MAX;
//     }

//     auto res = (node->key >= key) ? node->key : INT_MAX;

//     if (node->l) res = std::min(res, pitem_find_min(node->l, key));
//     if (node->r) res = std::min(res, pitem_find_min(node->r, key));

//     return res;
//   }

//  public:
//   solution() {}

//   void add(int key) {
//     if (this->next(key) == -1) {
//       insert(this->tree, new item(key));
//     }
//   }

//   int next(int key) {
//     auto res = this->pitem_find_min(this->tree, key);
//     if (res == INT_MAX) {
//       return -1;
//     }

//     return res;
//   }
// };

// int main() {
//   int n, query, last_query;
//   std::cin >> n;
//   std::string op;
//   char last_op = 0;

//   solution sol;

//   for (int i = 0; i < n; i++) {
//     std::cin >> op >> query;

//     if (op[0] == '+') {
//       if (last_op == 0 || last_op == '+') {
//         sol.add(query);
//       } else if (last_op == '?') {
//         sol.add((query + last_query) % 1000000000);
//       }
//     } else if (op[0] == '?') {
//       auto res = sol.next(query);
//       std::cout << res << '\n';
//       last_query = res;
//     }

//     last_op = op[0];
//   }

//   // разделить структуру по x -> найти минимальный элемент

//   return 0;
// }

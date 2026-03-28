#include <algorithm>
#include <iostream>
#include <vector>

struct node {
  int x, y;
  int index;
  node *left = nullptr, *right = nullptr, *parent = nullptr;

  node(int x, int y, int num) {
    this->x = x;
    this->y = y;
    this->index = num;
  }
};

bool compare(node* a, node* b) { return a->x < b->x; }

node* build_tree(node* root, int n, std::vector<int>& node_y,
                 std::vector<node*>& sorted_nodes) {
  root = sorted_nodes[0];
  node* last = root;

  for (int i = 1; i < n; i++) {
    if (last->y < node_y[i]) {
      last->right = sorted_nodes[i];
      last->right->parent = last;
      last = last->right;
      continue;
    }

    node* current = last;
    while (current->parent != nullptr && current->y > sorted_nodes[i]->y)
      current = current->parent;

    if (current->y > sorted_nodes[i]->y) {
      last = sorted_nodes[i];
      last->left = current;
      current->parent = last;
    } else {
      last = sorted_nodes[i];
      last->left = current->right;
      current->right->parent = last;
      last->parent = current;
      current->right = last;
    }
  }

  while (last->parent != nullptr) last = last->parent;
  return last;
}

int main() {
  int n, a, b;
  std::cin >> n;

  std::vector<int> node_x, node_y, node_num;
  std::vector<node*> nodes, sorted_nodes;
  node* root = nullptr;

  for (int i = 1; i <= n; i++) {
    std::cin >> a >> b;
    node* e = new node(a, b, i);

    sorted_nodes.push_back(e);
    nodes.push_back(e);
  }

  std::sort(sorted_nodes.begin(), sorted_nodes.end(), compare);

  for (int i = 0; i < n; i++) {
    node_x.push_back(sorted_nodes[i]->x);
    node_y.push_back(sorted_nodes[i]->y);
    node_num.push_back(sorted_nodes[i]->y);
  }

  root = build_tree(root, n, node_y, sorted_nodes);

  std::cout << "YES\n";

  for (int i = 0; i < n; i++) {
    node* current = nodes[i];
    auto parent = (current->parent != nullptr) ? current->parent->index : 0;
    auto left = (current->left != nullptr) ? current->left->index : 0;
    auto right = (current->right != nullptr) ? current->right->index : 0;
    std::cout << parent << ' ' << left << ' ' << right << '\n';
  }

  return 0;
}

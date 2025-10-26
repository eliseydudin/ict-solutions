/* doesnt work */

#include <iostream>
#include <vector>

class segment_tree_node {
  typedef std::vector<int>::iterator iterator;

  iterator begin;
  iterator end;

  segment_tree_node *left_child;
  segment_tree_node *right_child;

  void build_children() {
    int diff = this->end - this->begin;

    if (diff == 1) {
      this->left_child = nullptr;
      this->right_child = nullptr;
    } else {
      int first_len = diff / 2 + (diff % 2);
      iterator sep = this->begin + first_len;

      this->left_child = new segment_tree_node(this->begin, sep);
      this->right_child = new segment_tree_node(sep, this->end);
    }
  }

 public:
  segment_tree_node(iterator begin, iterator end) {
    this->begin = begin;
    this->end = end;

    this->build_children();
  }

  ~segment_tree_node() {
    // this node has no children
    if (this->left_child == nullptr || this->right_child == nullptr) {
      return;
    }

    delete this->left_child;
    delete this->right_child;
  }

  int count_zeroes(iterator z_begin, iterator z_end) {
    if (this->left_child == nullptr) {
      if (this->begin >= z_begin && this->end <= z_end) {
        return (*this->begin) == 0;
      } else {
        return 0;
      }
    } else {
      return left_child->count_zeroes(z_begin, z_end) +
             right_child->count_zeroes(z_begin, z_end);
    }
  }

  // void print() {
  //   for (auto start = begin; start < end; start++) {
  //     std::cout << *start << ' ';
  //   }
  //   std::cout << std::endl;

  //   if (left_child != nullptr) {
  //     left_child->print();
  //     right_child->print();
  //   }
  // }
};

class segment_tree {
  std::vector<int> array;
  segment_tree_node root;

 public:
  segment_tree(std::vector<int> arr)
      : array(arr), root(array.begin(), array.end()) {}

  // void print() { this->root.print(); }

  void update(size_t index, int value) { this->array[index] = value; }
  int count_zeroes(int start, int end) {
    auto z_begin = this->array.begin() + start;
    auto z_end = this->array.end() + end;

    return root.count_zeroes(z_begin, z_end);
  }
};

int main() {
  int n, q;
  std::cin >> n;
  std::vector<int> nums(n);
  for (auto &el : nums) std::cin >> el;
  segment_tree tree(nums);
  std::cin >> q;

  for (int i = 0; i < q; i++) {
    char query;
    int left, right;
    std::cin >> query >> left >> right;

    if (query == 'u') {
      tree.update(--left, right);
    } else {
      std::cout << tree.count_zeroes(--left, --right) << ' ';
    }
  }
  std::cout << std::endl;

  return 0;
}

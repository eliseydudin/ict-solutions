#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using ind_vector = std::vector<std::pair<int, size_t>>;

std::vector<size_t> find_x_deers(size_t x, ind_vector &deer,
                                 ind_vector &elves) {
  size_t i = 0, j = 0, k = elves.size() - x;
  const size_t number_of_deers = deer.size();
  std::vector<size_t> found_deer;

  while (i < number_of_deers && j < x && elves[j].first < elves[k].first &&
         deer[i].first < elves[k].first) {
    if (elves[j].first < deer[i].first && deer[i].first < elves[k].first) {
      found_deer.push_back(deer[i].second);
      j++;
      k++;
    }

    i++;
  }

  return (found_deer.size() == x) ? found_deer : std::vector<size_t>{};
}

std::vector<size_t> find_max_deer(ind_vector &deer, ind_vector &elves) {
  size_t n = elves.size();
  size_t m = deer.size();

  size_t left = 1, right = std::min(n / 2, m);

  std::vector<size_t> max_found_deer;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    std::vector<size_t> found_deer = find_x_deers(mid, deer, elves);

    if (!found_deer.empty()) {
      max_found_deer = std::move(found_deer);

      left = mid + 1;

    } else {
      right = mid - 1;
    }
  }

  return max_found_deer;
}

ind_vector scan_indexed_vector(size_t size) {
  ind_vector iv(size);

  for (size_t i = 0; i < size; i++) {
    int value;
    std::cin >> value;
    iv[i] = {value, i + 1};
  }

  return iv;
}

int main() {
  size_t n, m;
  std::cin >> m >> n;

  ind_vector a = scan_indexed_vector(m), b = scan_indexed_vector(n);

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  std::vector<size_t> deer = find_max_deer(a, b);

  size_t k = deer.size();
  std::cout << k << std::endl;

  for (size_t i = 0; i < k; i++) {
    std::cout << deer[i] << " " << b[i].second << " " << b[n - k + i].second
              << std::endl;
  }

  return 0;
}

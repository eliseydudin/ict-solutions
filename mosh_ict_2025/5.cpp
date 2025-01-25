/*
TASK 5
45/100 points
solution by @PD758
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

void solve_for_king(const char& fc, const short& fd, const char& tc,
                    const short& td) {
  std::cout << std::max(std::abs(tc - fc), std::abs(td - fd));
}

void solve_for_queen(const char& fc, const short& fd, const char& tc,
                     const short& td) {
  int c_diff = std::abs(fc - tc);
  int d_diff = std::abs(fd - td);
  if (!c_diff || !d_diff || c_diff == d_diff) {
    std::cout << "1";
  } else {
    std::cout << "2";
  }
}

void solve_for_rook(const char& fc, const short& fd, const char& tc,
                    const short& td) {
  std::cout << ((fc != tc) + (fd != td));
}

void solve_for_bishop(const char& fc, const short& fd, const char& tc,
                      const short& td) {
  if (tc % 2 + td % 2 != fc % 2 + fd % 2) {
    std::cout << -1;
    return;
  }

  if (tc - td == fc - fd) {
    std::cout << 1;
  } else {
    std::cout << 2;
  }
}

void solve_for_knight(const char& fc, const short& fd, const char& tc,
                      const short& td) {
  int c_diff = abs(fc - tc);
  int d_diff = abs(fd - td);
  if ((c_diff == 2 && d_diff == 1) || (c_diff == 1 && d_diff == 2)) {
    std::cout << 1;
    return;
  }

  std::queue<std::pair<char, short>> q;
  std::vector<std::vector<bool>> visited(8, std::vector<bool>(8, false));
  q.push({fc, fd});
  visited[fc - 'a'][fd - 1] = true;
  int moves = 0;
  while (!q.empty()) {
    int s = q.size();
    for (int i = 0; i < s; i++) {
      auto [curr_c, curr_d] = q.front();
      q.pop();
      if (curr_c == tc && curr_d == td) {
        std::cout << moves;
        return;
      }
      static const std::pair<int, int> directions[] = {
          {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
          {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
      for (const auto& [dx, dy] : directions) {
        char new_c = curr_c + dx;
        short new_d = curr_d + dy;
        if (new_c >= 'a' && new_c <= 'h' && new_d >= 1 && new_d <= 8 &&
            !visited[new_c - 'a'][new_d - 1]) {
          q.push({new_c, new_d});
          visited[new_c - 'a'][new_d - 1] = true;
        }
      }
    }
    moves++;
  }
}
void solve_for_pawn(const char& fc, const short& fd, const char& tc,
                    const short& td) {
  if (fd == 8) {
    solve_for_queen(fc, fd, tc, td);
    return;
  }

  int r_way = (td >= fd && tc == fc ? td - fd : -1);

  if (fd == 2 && td >= 4) {
    r_way--;
  }
  int q_way = (8 - fd) + 1;
  if (tc != fc) {
    q_way += 1;
  }

  if (r_way < q_way && r_way != -1) {
    std::cout << r_way;
  } else {
    std::cout << q_way;
  }
}

void solve() {
  std::string type, pos_n, pos_r;
  std::cin >> type >> pos_n >> pos_r;

  char pos_nc = pos_n[0], pos_rc = pos_r[0];
  short posNd = pos_n[1] - '0', posRd = pos_r[1] - '0';

  if (pos_nc == pos_rc && posNd == posRd) {
    std::cout << 0 << '\n';
    return;
  }

  if (type == "KING") {
    solve_for_king(pos_nc, posNd, pos_rc, posRd);
  } else if (type == "QUEEN") {
    solve_for_queen(pos_nc, posNd, pos_rc, posRd);
  } else if (type == "ROOK") {
    solve_for_rook(pos_nc, posNd, pos_rc, posRd);
  } else if (type == "BISHOP") {
    solve_for_bishop(pos_nc, posNd, pos_rc, posRd);
  } else if (type == "KNIGHT") {
    solve_for_knight(pos_nc, posNd, pos_rc, posRd);
  } else if (type == "PAWN") {
    solve_for_pawn(pos_nc, posNd, pos_rc, posRd);
  }

  std::cout << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;
  std::cin >> t;
  for (int _case = 0; _case < t; _case++) {
    solve();
  }

  std::cout.flush();
  return 0;
}

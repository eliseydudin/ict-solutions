"""
#include <iostream>
int main() {
    int n, a, b, c;
    std::cin >> n;
    //base
    a = 3;
    b = 8;
    c = 22;
    for (int i = 0; i < n-1; ++i) {
        c = b * 2 + a * 2;
        a = b;
        b = c;
    }
    std::cout << a << std::endl;
}
"""


def main():
    n = int(input())
    a, b, c = 3, 8, 22

    for _ in range(n - 1):
        c = b * 2 + a * 2
        a = b
        b = c

    print(a)


if __name__ == "__main__":
    main()

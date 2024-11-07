"""
#include <iostream>
using namespace std;
int rec(int p, int col, int n)
{
    if(col==n)
        return 1;
    int t=rec(2,col+1,n)+rec(3,col+1,n);
    if(p!=1)
        t+=rec(1,col+1,n);
    return t;
}
 int main()
 {
     int n;
     cin>>n;
     cout<<rec(1,1,n)+rec(2,1,n)+rec(3,1,n);
     return 0;
 }
"""


def rec(p: int, col: int, n: int) -> int:
    if col == n:
        return 1

    t = rec(2, col + 1, n) + rec(3, col + 1, n)
    if p != 1:
        t += rec(1, col + 1, n)

    return t


def main():
    n = int(input())
    print(rec(1, 1, n) + rec(2, 1, n) + rec(3, 1, n))


if __name__ == "__main__":
    main()

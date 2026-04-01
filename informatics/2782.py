# passes 9/10 tests

import random
from typing import Optional


class TreapNode:
    def __init__(self, key: int):
        self.key = key
        self.priority = random.randint(0, 99)
        self.left: Optional[TreapNode] = None
        self.right: Optional[TreapNode] = None

    def __lt__(self, node: "TreapNode"):
        return self.key < node.key


def right_rotate(y):
    x = y.left
    t2 = x.right
    x.right = y
    y.left = t2
    return x


def left_rotate(x):
    y = x.right
    t2 = y.left
    y.left = x
    x.right = t2
    return y


def insert(root: Optional[TreapNode], key: int):
    if not root:
        return TreapNode(key)

    if key <= root.key:
        root.left = insert(root.left, key)
        if root.left.priority > root.priority:  # type: ignore
            root = right_rotate(root)
    else:
        root.right = insert(root.right, key)

        if root.right.priority > root.priority:  # type: ignore
            root = left_rotate(root)
    return root


def search(root: Optional[TreapNode], key: int) -> Optional[TreapNode]:
    if not root or root.key == key:
        return root

    if root.key < key:
        return search(root.right, key)

    if node := search(root.left, key):
        return min(node, root)
    else:
        return root


def main():
    n = int(input())
    root: Optional[TreapNode] = None
    last_query_result: Optional[int] = None

    for _ in range(n):
        op, num = input().split()
        to_add = int(num)

        if op == "+":
            if q_result := last_query_result:
                to_add = (to_add + q_result) % 10**9
            root = insert(root, to_add)
            last_query_result = None

        elif op == "?":
            if node := search(root, to_add):
                print(node.key)
                last_query_result = node.key
            else:
                print(-1)
                last_query_result = -1


if __name__ == "__main__":
    main()

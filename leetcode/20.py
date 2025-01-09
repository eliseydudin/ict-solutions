class Solution:
    def isValid(self, s: str) -> bool:
        stk: list[str] = []
        d = {"()", "[]", "{}"}
        for c in s:
            if c in "({[":
                stk.append(c)
            elif not stk or stk.pop() + c not in d:
                return False
        return not stk

    def __init__(self):
        pass


def main():
    sol = Solution()
    s = input()
    print(sol.isValid(s))


if __name__ == "__main__":
    main()

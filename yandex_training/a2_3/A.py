def main():
    yes_pile = set(map(str, range(1, int(input()) + 1)))

    for line in iter(input, "HELP"):
        guesses = yes_pile & set(line.split())
        if len(guesses) > (len(yes_pile) - len(guesses)):
            print("YES")
            yes_pile = guesses
        else:
            print("NO")
            yes_pile -= guesses

    print(*sorted(yes_pile, key=int))


if __name__ == "__main__":
    main()

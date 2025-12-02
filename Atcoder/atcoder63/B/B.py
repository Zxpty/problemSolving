def GA():
    x = input()
    mp = {}
    for p in x:
        if p in mp:
            print("no")
            return
        mp[p] = 1
    print("yes")

def main():
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()


def GA():
    n = int(input())
    r = list(map(int, input().split()))
    mn = min(r)
    mx = max(r)
    print(mx - mn)

def main():
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()


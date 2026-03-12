def GA():
    n = int(input())
    arr = []
    mx = 0
    for _ in range(n):
        s = input()
        arr.append(s)
        mx = max(mx, len(s))

    for s in arr:
        left = mx - len(s)
        if left % 2 == 0:
            dots = left // 2
            print("." * dots + s + "." * dots)
        else:
            left_dots = left // 2
            righ_dots = left - left_dots
            print("." * left_dots + s + "." * righ_dots)


def main():
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()

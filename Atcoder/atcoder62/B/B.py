
def GA():
    h, w = [int(i) for i in input().split()]
    r = []
    for _ in range(h):
        r.append(input())

    for i in range(w + 2):
        print("#", end = "")
    print()
    for i in range(h):
        print("#", end = "")
        for j in range(w):
            print(r[i][j], end = "")
        print("#")

    for i in range(w + 2):
        print("#", end = "")
    print()


def main():
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()


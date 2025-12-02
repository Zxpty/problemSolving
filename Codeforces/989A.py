def GA():
    x = input('')
    x = x.upper()
    cn = 0
    for k in range(1, len(x) - 1):
        arr = [x[k - 1], x[k], x[k + 1]]
        arr.sort()
        if arr == ['A', 'B', 'C']:
            cn = cn + 1
    if cn == 0:
        print("No")
        return

    print("Yes")

def main():
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()


def GA():
    n = int(input())
    s = ["-"] * (n + 1)
    for i in range(n + 1):
        for j in range(1, 10):
            if n % j == 0 and i % (n / j) == 0:
                s[i] = str(j)
                break
    ans = "".join(s)
    print(ans)
    

def main():
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()



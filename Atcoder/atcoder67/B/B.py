def GA():
    n, k = [int(i) for i in input().split()]
    r = [int(i) for i in input().split()]
    r.sort()
    r.reverse()
    sum = 0
    for i in range(k):
        sum += r[i]
    print(sum)
    

def main():
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()


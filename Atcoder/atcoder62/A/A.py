def GA():
    a = [1, 3, 5, 7, 8, 10, 12]
    b = [4, 6, 9, 11]
    mp1 = list(map(int, a))
    mp2 = list(map(int, b))

    x, y = [int(i) for i in input().split()]
    if mp1.count(x) and mp1.count(y):
        print("Yes")
        return

    if mp2.count(x) and mp2.count(y):
        print("Yes")
        return
    if(x == 2 and y == 2):
        print("Yes")
        return
    print("No")
    

def main():
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()


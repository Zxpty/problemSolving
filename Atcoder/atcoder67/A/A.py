def GA():
    a, b = [int(i) for i in input().split()]
    if a % 3 == 0 or (a + b) % 3 == 0 or b % 3 == 0:
        print("Possible")
        return
    print("Impossible")

def main():
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()


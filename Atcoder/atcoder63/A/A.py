def GA():
    a, b = [int(i) for i in input().split()]
    if a + b >= 10:
        print("error")
        return
    print(a + b)
    

def main():
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()


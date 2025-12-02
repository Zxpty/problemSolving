def GA():
    s = input()
    ans = s.replace(" ", "")
    num = int(ans)
    if num % 4 == 0:
        print("YES")
        return
    print("NO")
    

def main():
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()


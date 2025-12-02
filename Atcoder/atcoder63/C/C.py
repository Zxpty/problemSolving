def GA():
 n = int(input())
 r = [] 
 for i in range(n):
     r.append(int(input()))
 acc = 0
 for i in range(n):
     acc = acc + r[i]
 if acc % 10 != 0:
     print(acc)
     return
 r.sort()
 for i in range(n):
     if (acc - r[i]) % 10 != 0:
         print(acc - r[i])
         return
 print(0)



def main():
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()


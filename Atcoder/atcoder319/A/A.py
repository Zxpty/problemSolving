import sys

input = sys.stdin.readline
def read(): return sys.stdin.readline().strip()
def read_int(): return int(read())
def read_ints(): return map(int, read().split())
def read_list(): return list(map(int, read().split()))

# Print helpers
def ps(*args, sep=' ', end='\n'):
    sys.stdout.write(sep.join(map(str, args)) + end)

# Useful aliases
INF = float('inf')
MOD = 10**9 + 7


def GA():
    s = read()
    if s == "tourist":
        ps(3858)
        return

    if s == "ksun48":
        ps(3679)
        return

    if s == "Benq":
        ps(3658)
        return

    if s == "Um_nik":
        ps(3648)
        return

    if s == "apiad":
        ps(3638)
        return


    if s == "Stonefeang":
        ps(3630)
        return

    if s == "ecnerwala":
        ps(3613)
        return


    if s == "mnbvmar":
        ps(3555)
        return

    if s == "newbiedmy":
        ps(3516)
        return

    if s == "semiexp":
        ps(3481)
        return






def main():
    sys.setrecursionlimit(10**6)
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()



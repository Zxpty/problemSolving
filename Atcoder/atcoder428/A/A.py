import sys
from math import *
from collections import *
from itertools import *
from bisect import *
from heapq import *

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
    s, a, b, x = read_ints()
    seconds = 0
    calc = 0
    ok = True
    while seconds < x:
        if ok:
            if seconds + a > x:
                calc += (x - seconds) * s
            else:
                calc += a * s
            seconds += a
            ok = False
        else:
            seconds += b
            ok = True
    print(calc)


def main():
    sys.setrecursionlimit(10**6)
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()



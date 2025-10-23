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
    n, r = read_ints()
    if n < 10:
        print(r +100 * (10 - n))
    else:
        print(r)
    


def main():
    sys.setrecursionlimit(10**6)
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()



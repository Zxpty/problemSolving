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
    n = read_int()
    arr = read_list()
    sum_pos = 0
    sum_nega = 0
    for x in arr:
        if x > 0:
            sum_pos += x
        else:
            sum_nega += x

    calc = abs(sum_nega) - sum_pos
    ps(calc)
    


def main():
    sys.setrecursionlimit(10**6)
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()



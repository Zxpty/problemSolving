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
    a = read_list()
    b = read_list()
    suma = 0
    for i in range(0, 9):
        suma = suma + a[i]
    sumb = 0
    for i in range(0, 8):
        sumb = sumb + b[i]

    print(suma - sumb + 1)


def main():
    sys.setrecursionlimit(10**6)
    t = 1
    # t = read_int()
    for _ in range(t):
        GA()


if __name__ == "__main__":
    main()



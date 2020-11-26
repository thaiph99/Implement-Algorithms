import sys
sys.stdin = open("INPUT.INP", "r")
sys.stdout = open("OUTPUT.OUT", "w")

dic = {}


def call(x, y):
    if x < 1 or y < 1 or x > 15 or y > 15:
        return 1
    if (x, y) in dic:
        return dic[(x, y)]
    state = 1
    state = state and call(x-1, y-2)
    state = state and call(x+1, y-2)
    state = state and call(x-2, y+1)
    state = state and call(x-2, y-1)
    dic[(x, y)] = int(state == 0)
    return dic[(x, y)]


t = int(input())

for _ in range(t):
    x, y = map(int, input().split())
    if call(x, y) == 0:
        print("Second")
    else:
        print("First")

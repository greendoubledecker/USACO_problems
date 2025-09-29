def getInput():
    numlines = int(input())
    lines = []
    for i in range(numlines):
        lines.append(list(map(int, input().split())))
    return lines

def shell():
    swaps = getInput()
    shells = [0, 0, 0]
    points = 0
    maxp = 0
    temp = 0
    for i in range(3):
        shells[i] = 1
        for swap in swaps:
            temp = shells[swap[0] - 1]
            shells[swap[0] - 1] = shells[swap[1] - 1]
            shells[swap[1] - 1] = temp
            if shells[swap[2] - 1] == 1:
                points += 1
        if points > maxp:
            maxp = points
        points = 0
        shells = [0, 0, 0]
    print(maxp)

shell()

def bucket():
    positions = findPositions()
    barn = positions[0]
    rock = positions[1]
    lake = positions[2]
    dist = abs(barn[0]-lake[0]) + abs(barn[1]-lake[1]) - 1
    if rock[0] == barn[0] == lake[0] and (barn[1] < rock[1] < lake[1] or barn[1] > rock[1] > lake[1]):
        dist += 2
    if rock[1] == barn[1] == lake[1] and (barn[0] < rock[0] < lake[0] or barn[0] > rock[0] > lake[0]):
        dist += 2
    return dist

def findPositions():
    inpt = get10x10(10)
    #print("findPositions")
    output = [None, None, None]
    for i in range(len(inpt)):
        for j in range(len(inpt[i])):
            if inpt[i][j] == "B":
                output[0] = [i, j]
                #print("barn")
            if inpt[i][j] == "R":
                output[1] = [i, j]
                #print("rock")
            if inpt[i][j] == "L":
                output[2] = [i, j]
                #print("lake")aa
            #print(output)
            done = True
            for k in range(3):
                if not 0 <= k < len(output) or output[k] is None:
                    done = False
            if(done):
                return output

def get10x10(numrows):
    grid = []
    for i in range(numrows):
        grid.append(list(input()))
    #print(grid)
    return grid

print(bucket())
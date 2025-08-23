def get_input():
    numpoints = int(input())
    xcoords = list(map(int, input().split()))
    ycoords = list(map(int, input().split()))
    return [numpoints, xcoords, ycoords]

def maxdist():
    numpoints, xcoords, ycoords = get_input()
    record = 0
    for i in range(numpoints):
        for j in range(i):
            xdist = abs(xcoords[i] - xcoords[j])
            ydist = abs(ycoords[i] - ycoords[j])
            euclid_square = xdist ** 2 + ydist ** 2
            if euclid_square > record:
                record = euclid_square
    return record

print(maxdist())

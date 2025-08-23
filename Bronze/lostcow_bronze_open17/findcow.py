def getInput():
    inp = list(map(int, input().split()))
    return inp[1] - inp[0]

def findCow():
    pos = 0
    cowp = getInput()
    dist = 0
    move = 1
    first = True
    while True:
        if(cowp < 0 and pos > 0 and pos + move <= cowp):
            dist += pos - cowp
            print (dist)
            return
        elif(cowp > 0 and pos < 0 and pos + move >= cowp):
            dist += cowp - pos
            print (dist)
            return 
        else:
            pos += move
            dist += abs(move)
            if(first):
                move *= -3
                first = False
            else:
                move *= -2
            print("pos " + str(pos) + " dist " + str(dist) + " move " + str(move))

findCow()
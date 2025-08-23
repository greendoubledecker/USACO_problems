def get_input(numbuckets):
    rows = []
    for i in range(numbuckets):
        rows.append(list(map(int, input().split())))
    return rows

def mix(numbuckets, operations, printop):
    input = get_input(numbuckets)
    #print(input)
    current = 0
    prev = 2
    buckets = []
    sub = 0
    for i in range(numbuckets):
        buckets.append(input[i][1])
    #print(buckets)
    for i in range(operations):
        prev = current
        if current == numbuckets-1 :
            current = 0
        else :
            current += 1
        sub = min(buckets[prev], input[current][0] - buckets[current])
        buckets[prev] -= sub
        buckets[current] += sub
        if printop :
            print(str(buckets))
    for bucket in buckets:
        print(str(bucket))

mix(3, 100, False) 
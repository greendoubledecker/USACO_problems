def get_input():
    numcows = int(input())
    cows = []
    for i in range(numcows):
        cows.append(list(map(int, input().split())))
    return cows

def allocateBuckets():
    cows = get_input()
    times = []
    buckets_in_use = []
    max_bucket = 0
    for cow in cows:
        times.append(cow[1])
    for timestep in range(max(times)):
        for i in range(len(cows)):
            if cows[i][0] == timestep:
                for i in range(cows[i][2]):
                    bucket = findSpot(buckets_in_use)
                    if bucket > max_bucket:
                        max_bucket = bucket
                    buckets_in_use.append(bucket)
            if cows[i][1] == timestep:
                for i in range(cows[i][2]):
                    buckets_in_use.pop()#If something goes wrong, it's most likely here!
    print(max_bucket + 1)

def findSpot(array):
    bucket = 0
    while True:
        #print(bucket)
        if bucket not in array:
            return bucket
        bucket += 1

allocateBuckets()

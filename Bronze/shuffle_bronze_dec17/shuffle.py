def get_input():
    numcows = int(input())
    shuffle = list(map(int, input().split()))
    cowids = list(map(int, input().split()))
    return [numcows, shuffle, cowids]

def unravel(shuffle):
    reverse_array = []
    for i in range(len(shuffle)):
        reverse_array.append(0)
    #print(len(reverse_array))
    #print(len(shuffle))
    #print(reverse_array)
    for i in range(len(shuffle)):
        #print(shuffle[i])
        reverse_array[shuffle[i] - 1] = i
    return reverse_array

def shuffle(numshuf):
    input = get_input()
    numcows = input[0]
    shuffle = unravel(input[1])
    cowids = input[2]
    cows = []
    prev = [0 for i in range(numcows)]
    for i in range(numcows):
        cows.append(cowids[i])
    for i in range(numshuf):
        for j in range(numcows):
            prev[j] = cows[j]
        for j in range(numcows):
            cows[shuffle[j]] = prev[j]
    for cow in cows:
        print(cow)

shuffle(3)
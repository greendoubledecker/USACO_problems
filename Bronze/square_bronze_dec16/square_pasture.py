# rect1 = [6,6,8,8]
# rect2 = [1,8,4,9]
def square_pasture():
    rects = std_in()
    record = 0
    for i in range(len(rects)):
        for j in range(len(rects)):
            size = rects[i][2] - rects[j][0]
            if size > record:
                record = size
            size = rects[i][3] - rects[j][1]
            if size > record:
                record = size
    print(record ** 2)

def std_in():
    row1 = list(map(int, input().split()))
    row2 = list(map(int, input().split()))
    return [row1, row2]

square_pasture()

def open_file(num):
    with open(str(num) + ".in", "r") as file:
        array = []
        for line in file:  # .strip() removes newline characters
            split_line = line.strip().split()
            for i in range(len(split_line)):
                split_line[i] = int(split_line[i])
            array.append(split_line)
    return array

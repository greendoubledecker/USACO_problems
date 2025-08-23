def get_input():
    numbers = list(map(int, input().split()))
    rectangle = []
    for i in range(numbers[0]):
        rectangle.append(list(input()))
    return [rectangle, numbers[2]]

def amplify_signal():
    rectangle, factor = get_input()
    for i in range(len(rectangle)):
        for j in range(factor):
            for k in range(len(rectangle[i])):
                for l in range(factor):
                    print(rectangle[i][k], end = "")
            print("")
amplify_signal()
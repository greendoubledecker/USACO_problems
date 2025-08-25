def get_input():
    inital_string = input()
    censor_content = input()
    return [inital_string, censor_content]

def censor():
    inp = get_input()
    censored = inp[0]
    while inp[1] in censored:
        censored = censored.replace(inp[1], "", 1)
    return censored

print(censor())
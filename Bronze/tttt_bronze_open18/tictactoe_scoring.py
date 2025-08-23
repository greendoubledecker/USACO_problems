def get_input(size):
    rows = []
    for i in range(size):
        rows.append(list(input()))
    return rows

def score(size):
    input = get_input(size)
    single = []
    team = []
    for i in range(size):
        letters = []
        for j in range(size):
            if not input[i][j] in letters:
                letters.append(input[i][j])
            if len(letters) > 2:
                break
        if len(letters) == 1:
            if not letters[0] in single:
                single.append(letters[0])
        if len(letters) == 2:
            if not [letters[0], letters[1]] in team and not [letters[1], letters[0]] in team:
                team.append([letters[0], letters[1]])
        letters = []
        for j in range(size):
            if not input[j][i] in letters:
                letters.append(input[j][i])
            if len(letters) > 2:
                break
        if len(letters) == 1:
            if not letters[0] in single:
                single.append(letters[0])
        if len(letters) == 2:
            if not [letters[0], letters[1]] in team and not [letters[1], letters[0]] in team:
                team.append([letters[0], letters[1]])
    letters = []
    for i in range(size):
        if not input[i][i] in letters:
            letters.append(input[i][i])
        if len(letters) > 2:
            break
    if len(letters) == 1:
        if not letters[0] in single:
            single.append(letters[0])
    if len(letters) == 2:
        if not [letters[0], letters[1]] in team and not [letters[1], letters[0]] in team:
            team.append([letters[0], letters[1]])
    for i in range(size):
        if not input[i][size - i - 1] in letters:
            letters.append(input[i][size - i - 1])
        if len(letters) > 2:
            break
    if len(letters) == 1:
        if not letters[0] in single:
            single.append(letters[0])
    if len(letters) == 2:
        if not [letters[0], letters[1]] in team and not [letters[1], letters[0]] in team:
            team.append([letters[0], letters[1]])
    print(len(single))
    print(len(team))

score(3)
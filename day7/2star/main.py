def step(matrix):
    # print("INSIDE")
    beam_splits = 0
    for i in range(0, len(matrix)):
        for j in range(0, len(line)):
            if i == len(matrix) - 1:
                # print("KONIEC!")
                return matrix, beam_splits
            char = matrix[i][j]
            # print(char)
            if char == '|':
                if matrix[i+1][j] == '^':
                    matrix[i+1][j-1] = '|'
                    matrix[i+1][j+1] = '|'
                    beam_splits += 1
                else:
                    matrix[i+1][j] = '|'
    return matrix, beam_splits


with open("input.txt", "r") as f:
    input_tab = []
    lines = f.readlines()
    for line in lines:
        line = line.strip().replace('S', '|')
        line_tab = []
        for char in line:
            line_tab.append(char)
        input_tab.append(line_tab)
        # print(line_tab)
    final_matrix, beam_splits = step(input_tab)
    for line in final_matrix:
        for char in line:
            print(char, end='')
        print("\n", end='')
        #print(line)
    print(f"beam_splits: {beam_splits}")
    
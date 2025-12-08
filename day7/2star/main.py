def step(matrix):
    # print("INSIDE")
    beam_splits = 0
    for i in range(0, len(matrix)):
        for j in range(0, len(matrix[i])):
            if i == len(matrix) - 1:
                # print("KONIEC!")
                return matrix, beam_splits
            char = matrix[i][j]
            # print(char)
            if char == '|':
                if matrix[i+1][j] == '^':
                    if not matrix[i+1][j-1] == '|':
                        matrix[i+1][j-1] = '|'
                        beam_splits += 1
                    if not matrix[i+1][j+1] == '|':
                        matrix[i+1][j+1] = '|'
                        beam_splits += 1
                else:
                    matrix[i+1][j] = '|'
    return matrix, beam_splits

# memo needed cuz recursion is just too big
def count_recursive(matrix, i, j, memo=None):
    if memo is None:
        memo = {}

    if j < 0 or j >= len(matrix[i]):
        return 0
    
    if (i, j) in memo:
        return memo[(i, j)]
    if i == len(matrix) - 1:
        return 1
    result = 0
    char = matrix[i][j]
    # print(f"i: {i} j: {j}")
    if char == '^':
        left = count_recursive(matrix, i + 1, j-1, memo)
        right = count_recursive(matrix, i + 1, j+1, memo)
        result = left + right
    elif char == '|':
        result = count_recursive(matrix, i + 1, j, memo)
    memo[(i, j)] = result
    return result


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
    final_matrix, beams = step(input_tab)
    """for line in final_matrix:
        for char in line:
            print(char, end='')
        print("\n", end='')"""
        #print(line)
    # print(f"Beam splits: ", beams)
    # print("I: ", int(len(final_matrix[0]) / 2))
    # print("CHAR: ", final_matrix[0][int(len(final_matrix[0]) / 2)])
    timelines = count_recursive(final_matrix, 0, int(len(final_matrix[0]) / 2))
    
    print(f"timelines: {timelines}")
    
import sys

def read_matrix():
    """
    Reads a 4x4 matrix from standard input.
    Each matrix is represented by 4 lines of 4 digits,
    followed by a blank line.
    """
    matrix = []
    for _ in range(4):
        # Reads a line, removes leading/trailing whitespace, and converts chars to ints
        line = sys.stdin.readline().strip()
        if not line: # Handles potential empty lines between matrices
            line = sys.stdin.readline().strip()
        matrix.append([int(c) for c in line])
    # Consume the blank line after a matrix block
    sys.stdin.readline()
    return matrix

def print_matrix(matrix):
    """Prints a 4x4 matrix to standard output."""
    for row in matrix:
        print("".join(map(str, row)))

def apply_rule1_color_inversion(matrix):
    """
    Applies Rule 1: Inverts colors (0->1, 1->0).
    """
    new_matrix = [[0] * 4 for _ in range(4)]
    for r in range(4):
        for c in range(4):
            new_matrix[r][c] = 1 - matrix[r][c]
    return new_matrix

def apply_rule2_corner_to_center(matrix):
    """
    Applies Rule 2: Moves corner elements to the center 2x2 area.
    """
    new_matrix = [[0] * 4 for _ in range(4)]
    new_matrix[1][1] = matrix[0][0] # Top-left
    new_matrix[1][2] = matrix[0][3] # Top-right
    new_matrix[2][1] = matrix[3][0] # Bottom-left
    new_matrix[2][2] = matrix[3][3] # Bottom-right
    return new_matrix

def apply_rule3_right_fold_overwrite(matrix):
    """
    Applies Rule 3: Folds vertically, right side overwrites left, then right side becomes 0.
    """
    new_matrix = [row[:] for row in matrix] # Create a copy to modify
    for r in range(4):
        # Column 4 overwrites Column 1 if non-zero
        if new_matrix[r][3] != 0:
            new_matrix[r][0] = new_matrix[r][3]
        # Column 3 overwrites Column 2 if non-zero
        if new_matrix[r][2] != 0:
            new_matrix[r][1] = new_matrix[r][2]
        
        # Clear the right half
        new_matrix[r][2] = 0
        new_matrix[r][3] = 0
    return new_matrix

def solve():
    """
    Main function to solve the problem.
    Reads data, identifies the rule, applies it, and prints the result.
    """
    # Read the three input-output example pairs
    input1 = read_matrix()
    output1 = read_matrix()
    input2 = read_matrix()
    output2 = read_matrix()
    input3 = read_matrix()
    output3 = read_matrix()

    # Read the final test image
    test_image = read_matrix()

    # Identify the correct transformation rule
    active_rule = None
    if (apply_rule1_color_inversion(input1) == output1 and
        apply_rule1_color_inversion(input2) == output2 and
        apply_rule1_color_inversion(input3) == output3):
        active_rule = apply_rule1_color_inversion
    elif (apply_rule2_corner_to_center(input1) == output1 and
          apply_rule2_corner_to_center(input2) == output2 and
          apply_rule2_corner_to_center(input3) == output3):
        active_rule = apply_rule2_corner_to_center
    else:
        # If it's not rule 1 or 2, it must be rule 3
        active_rule = apply_rule3_right_fold_overwrite

    # Apply the identified rule to the test image
    result_matrix = active_rule(test_image)

    # Print the final result
    print_matrix(result_matrix)

if __name__ == "__main__":
    solve()
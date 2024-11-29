from collections import deque
import itertools

def bfs_shortest_path(grid, N):
    """
    Performs BFS to find the shortest path from 'S' (start) to 'D' (destination) in the grid.
    """
    start, end = None, None

    # Locate the start ('S') and destination ('D') points
    for i in range(N):
        for j in range(N):
            if grid[i][j] == 'S':
                start = (i, j)
            elif grid[i][j] == 'D':
                end = (i, j)

    # BFS initialization
    queue = deque([(start, 0)])
    visited = {start}

    while queue:
        (x, y), distance = queue.popleft()
        if (x, y) == end:
            return distance  # Found the destination

        # Explore all 4 possible directions
        for nx, ny in [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]:
            if 0 <= nx < N and 0 <= ny < N and (nx, ny) not in visited and grid[nx][ny] != 'T':
                visited.add((nx, ny))
                queue.append(((nx, ny), distance + 1))

    return float('inf')  # Return infinity if no path exists


def divide_into_sheets(grid, N, M):
    """
    Divides the grid into smaller sheets of size MxM.
    """
    sheets = []
    for i in range(0, N, M):
        for j in range(0, N, M):
            sheet = [grid[i + x][j:j + M] for x in range(M)]
            sheets.append(sheet)
    return sheets


def reconstruct_grid(order, sheets, N, M):
    """
    Reconstructs the grid based on the order of sheets.
    """
    reconstructed = [["" for _ in range(N)] for _ in range(N)]
    num_sheets_per_row = N // M

    for idx, sheet_index in enumerate(order):
        sheet = sheets[sheet_index]
        base_i = (idx // num_sheets_per_row) * M
        base_j = (idx % num_sheets_per_row) * M

        for i in range(M):
            for j in range(M):
                reconstructed[base_i + i][base_j + j] = sheet[i][j]

    return reconstructed


def solve():
    # Input size of grid (N) and size of subgrid (M)
    N, M = map(int, input().split())
    original_grid = [list(input().strip()) for _ in range(N)]

    # Divide the grid into sheets
    sheets = divide_into_sheets(original_grid, N, M)
    num_sheets = len(sheets)

    # Find the indices of the sheets containing 'S' and 'D'
    start_sheet, dest_sheet = None, None
    for i, sheet in enumerate(sheets):
        for row in sheet:
            if 'S' in row:
                start_sheet = i
            if 'D' in row:
                dest_sheet = i

    # Calculate the shortest path through all possible permutations of sheets
    min_distance = float('inf')
    all_sheet_indices = list(range(num_sheets))
    all_sheet_indices.remove(start_sheet)
    all_sheet_indices.remove(dest_sheet)

    for middle_order in itertools.permutations(all_sheet_indices):
        sheet_order = [start_sheet] + list(middle_order) + [dest_sheet]
        reconstructed_grid = reconstruct_grid(sheet_order, sheets, N, M)
        min_distance = min(min_distance, bfs_shortest_path(reconstructed_grid, N))

    return min_distance


if __name__ == "__main__":
    print(solve())

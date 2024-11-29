import math
def cal_edge_length(x1, y1, x2, y2):
    return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)
def cal_height(x1, y1, x2, y2, x3, y3, edge_len):
    return abs((y2 - y1) * x3 - (x2 - x1) * y3 + x2 * y1 - y2 * x1) / edge_len
def find_max_edge_length(n, coordi):
    max_edge = 0
    for i in range(n):
        x1, y1 = coordi[i]
        x2, y2 = coordi[(i + 1) % n]
        edge_length = cal_edge_length(x1, y1, x2, y2)
        max_edge = max(max_edge, edge_length)
    return max_edge
def find_max_height(n, coor, max_edge):
    max_height = 0
    epsilon = 1e-6
    for i in range(n):
        x1, y1 = coor[i]
        x2, y2 = coor[(i + 1) % n]
        edge_length = cal_edge_length(x1, y1, x2, y2)
        if abs(edge_length - max_edge) < epsilon:
            for j in range(n):
                if j != i and j != (i + 1) % n:
                    x3, y3 = coor[j]
                    height = cal_height(x1, y1, x2, y2, x3, y3, edge_length)
                    max_height = max(max_height, height)
    return max_height
def find_min_plank_size(n, coordi):
    if n < 3: 
        return (0, 0)
    max_edge = find_max_edge_length(n, coordi)
    max_height = find_max_height(n, coordi, max_edge)
    length = math.ceil(max_edge)
    height = math.ceil(max_height)
    return (min(height, length), max(height, length))
if __name__ == "__main__":
    n = int(input())
    coordi = []
    for _ in range(n):
        x, y = map(float, input().split())
        coordi.append((x, y))   
    w, h = find_min_plank_size(n, coordi)
    print(w, h)

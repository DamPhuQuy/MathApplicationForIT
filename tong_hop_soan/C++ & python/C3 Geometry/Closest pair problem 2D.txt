import math

def dis(p1, p2) :
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])
    #return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

def brute_force(points) :
    min_dis = float('inf')
    n = len(points)
    for i in range (n) :
        for j in range (i + 1, n) :
            min_dis = min(min_dis, dis(points[i], points[j]))
    return min_dis

def strip_closest(strip, d) :
    min_d = d
    strip.sort(key = lambda point: point[1])
    for i in range (len(strip)) :
        for j in range (i + 1, len(strip)) :
            if abs(strip[i][1] - strip[j][1]) >= min_d :
                break
            min_d = min(min_d, dis(strip[i], strip[j]))
    return min_d

def closest(points, left, right) :
    if right - left <= 3:
        return brute_force(points[left: right + 1])
    mid = (left + right) // 2
    mid_point = points[mid]

    d_left = closest(points, left, mid)
    d_right = closest(points, mid + 1, right)

    d = min(d_left, d_right)
    strip = []
    for i in range (left, right + 1) :
        if abs(points[i][0] - mid_point[0]) < d:
            strip.append(points[i]);
    return min(d, strip_closest(strip, d))

def closest_pair(points) :
    points_sorted = sorted(points, key = lambda points: points[0])
    return closest(points_sorted, 0, len(points_sorted) - 1)

points = [(12, 41), (31, 21), (52, 17), (24, 19), (8, 19), (24, 29), (14, 27), (41, 52), (16,27), (28, 40)]
min_dis = closest_pair(points)
print(f"Khoảng cách nhỏ nhất giữa hai điểm trong tập hợp điểm trên là: {min_dis}")

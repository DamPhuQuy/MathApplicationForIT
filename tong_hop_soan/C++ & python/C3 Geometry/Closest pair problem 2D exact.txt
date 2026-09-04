import math

def dis(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])
    # return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

def brute_force(points):
    min_dis = float('inf')
    n = len(points)
    p1, p2 = None, None
    for i in range(n):
        for j in range(i + 1, n):
            distance = dis(points[i], points[j])
            if distance < min_dis:
                min_dis = distance
                p1, p2 = points[i], points[j]
    return min_dis, p1, p2

def strip_closest(strip, d):
    min_d = d
    strip.sort(key=lambda point: point[1])
    p1, p2 = None, None
    for i in range(len(strip)):
        for j in range(i + 1, len(strip)):
            if abs(strip[i][1] - strip[j][1]) >= min_d:
                break
            distance = dis(strip[i], strip[j])
            if distance < min_d:
                min_d = distance
                p1, p2 = strip[i], strip[j]
    return min_d, p1, p2

def closest(points, left, right):
    if right - left <= 3:
        return brute_force(points[left: right + 1])
    mid = (left + right) // 2
    mid_point = points[mid]

    d_left, p1_left, p2_left = closest(points, left, mid)
    d_right, p1_right, p2_right = closest(points, mid + 1, right)

    d = min(d_left, d_right)
    if d == d_left:
        p1, p2 = p1_left, p2_left
    else:
        p1, p2 = p1_right, p2_right

    strip = []
    for i in range(left, right + 1):
        if abs(points[i][0] - mid_point[0]) < d:
            strip.append(points[i])
    d_strip, p1_strip, p2_strip = strip_closest(strip, d)

    if d_strip < d:
        return d_strip, p1_strip, p2_strip
    else:
        return d, p1, p2

def closest_pair(points):
    points_sorted = sorted(points, key=lambda x: x[0])
    return closest(points_sorted, 0, len(points_sorted) - 1)

points = [(12, 41), (31, 21), (52, 17), (24, 19), (8, 19),
          (24, 29), (14, 27), (41, 52), (16, 27), (28, 40)]
min_dis, p1, p2 = closest_pair(points)
print(f"Khoảng cách nhỏ nhất giữa hai điểm trong tập hợp điểm trên là: {min_dis}")
print(f"Cặp điểm có khoảng cách nhỏ nhất: ({p1[0]}, {p1[1]}) và ({p2[0]}, {p2[1]})")

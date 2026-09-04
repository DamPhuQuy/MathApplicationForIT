import math

def orientation(p1, p2, p3):
    x1, y1, x2, y2, x3, y3 = *p1, *p2, *p3
    d = (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2)
    if d > 0:
        return 1
    elif d < 0:
        return -1
    else:
        return 0
      

def dist(p1, p2):
    x1, y1, x2, y2 = *p1, *p2
    return math.sqrt((y2-y1)**2 + (x2-x1)**2)
  

def gift_wrapping(points):
    on_hull = min(points)
    hull = []
    while True:
        hull.append(on_hull)
        next_point = points[0]
        for point in points:
            o = orientation(on_hull, next_point, point)
            if (o == 0 and dist(on_hull, point) > dist(on_hull, next_point)) or next_point == on_hull or o == 1:
                next_point = point
        on_hull = next_point
        if on_hull == hull[0]:
            break
    return hull

n = int(input())
points = []
for _ in range(n):
    point = list(map(int, input().split()))
    points.append(point)

print(gift_wrapping(points))
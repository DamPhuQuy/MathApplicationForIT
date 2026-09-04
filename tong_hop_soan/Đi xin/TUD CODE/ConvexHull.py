# import random

# """
# Computes the Convex Hull with the Graham Scan algorithm
# Use:
	
# """

# class ConvexHull:
# 	def __init__(self, points = None):
# 		if not points:
# 			self.points = [(random.randint(0,100),random.randint(0,100)) for i in range(50)]
# 		else:
# 			self.points = points
# 		self.hull = self.compute_convex_hull()
    
# 	def get_cross_product(self,p1, p2, p3):
# 		return ((p2[0] - p1[0])*(p3[1] - p1[1])) - ((p2[1] - p1[1])*(p3[0] - p1[0]))

# 	def get_slope(self,p1, p2):
# 		if p1[0] == p2[0]:
# 			return float('inf')
# 		else:
# 			return 1.0*(p1[1]-p2[1])/(p1[0]-p2[0])

# 	def compute_convex_hull(self):
# 		hull = []
# 		self.points.sort(key=lambda x:[x[0],x[1]])
# 		start = self.points.pop(0)
# 		hull.append(start)
# 		self.points.sort(key=lambda p: (self.get_slope(p,start), -p[1],p[0]))
# 		for pt in self.points:
# 			hull.append(pt)
# 			while len(hull) > 2 and self.get_cross_product(hull[-3],hull[-2],hull[-1]) < 0:
# 				hull.pop(-2)
# 		return hull


# h = ConvexHull()
# print(h.hull)

import numpy as np

# xác định hướng quay
def determinant(p1, p2, p3):
    return (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0])

points = np.array([
    [30, 60], [50, 40], [0, 30], [70, 30], [15, 25], [45, 20], [60, 10], [20, 0]
])

points = sorted(points, key=lambda p: (p[0], p[1]))

lower = []
upper = []

for p in points:
    # xác định hướng quay, nếu hướng quay ngược chiều kim đồng hồ thì pop, nếu hướng quay cùng chiều kim đồng hồ thì append
    while len(lower) >= 2 and determinant(lower[-2], lower[-1], p) <= 0:
        lower.pop()
    lower.append(p)
    while len(upper) >= 2 and determinant(upper[-2], upper[-1], p) >= 0:
        upper.pop()
    upper.append(p)

print(lower)
print(upper)




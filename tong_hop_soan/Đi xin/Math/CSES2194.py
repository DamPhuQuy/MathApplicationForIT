# Le Duc Phuc Long, 2024
# If you don't think twice, you twice

# This part for importing

from sys import stdin 

input = stdin.readline

# Constan numbers

# These are function needed

def closest(points):
	xsorted = sorted(points, key = lambda point: point[0])
	ysorted = sorted(points, key = lambda point: point[1])
	return rec(xsorted, ysorted)

def distance(A, B):
	return (A[0]-B[0])**2 + (A[1]-B[1])**2

def closest_brute_force(points):
	minDis = int(1e20)
	p1, p2 = [], []
	for i in range(len(points)-1):
		for j in range(i+1, len(points)):
			dis = distance(points[i], points[j])
			if dis < minDis:
				minDis = dis
				p1, p2 = points[i], points[j]
	return (p1, p2, minDis)


def rec(xsorted, ysorted):
	n = len(xsorted)
	if n <= 3:
		return closest_brute_force(xsorted)

	midPoint = xsorted[n//2]

	xsortedLeft = xsorted[:n//2]
	xsortedRight = xsorted[n//2:]

	ysortedLeft = []
	ysortedRight = []
	for point in ysorted:
		if (point[0] <= midPoint[0]):
			ysortedLeft.append(point)  
		else:
			ysortedRight.append(point)

	(p1Left, p2Left, deltaLeft) = rec(xsortedLeft, ysortedLeft)
	(p1Right, p2Right, deltaRight) = rec(xsortedRight, ysortedRight)

	p1, p2, delta = [], [], 0
	if (deltaLeft < deltaRight):
		p1, p2, delta = p1Left, p2Left, deltaLeft
	else:
		p1, p2, delta = p1Right, p2Right, deltaRight

	pointsInBand = []
	for point in ysorted:
		if midPoint[0]-delta < point[0] < midPoint[0]+delta:
			pointsInBand.append(point)

	for i in range(len(pointsInBand)):
		for j in range(i+1, min(len(pointsInBand), i+7)):
			dis = distance(pointsInBand[i], pointsInBand[j])
			if dis  < delta:
				p1, p2, delta = pointsInBand[i], pointsInBand[j], dis

	return (p1, p2, delta)



# Drive part

points = []

n = int(input())
for _ in range(n):
	x, y = map(int, input().split())
	points.append([x, y])

print(closest(points)[2])



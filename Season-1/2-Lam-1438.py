# This program draws a circle if possible,
# otherwise no circle is drawn, and "NO SUCH CIRCLE"
# is logged in the console
# Percentage of points is rounded down to nearest integer
# Also, I had to draw the points as larger than 1 pixel, otherwise
# they were nearly invisible. This means some points may look like
# they touch the circle, but are actually outside.

# ---------------------------------------
# CHANGE THESE VALUES FOR TESTING
# Number of points
NUM_OF_POINTS_MIN = 1
NUM_OF_POINTS_MAX = 100
# Canvas size in pixels
CANVAS_WIDTH = 300
CANVAS_HEIGHT = 300
# Percentage of points to lie in circle
PERCENTAGE = 0.5
# ---------------------------------------
# Importing modules
import pygame, random, math

# FUNCTIONS FOR POINTS
# ---------------------------------------
# Generate a single point (x,y) where x,y runs [0,1]
def generatePoint():
    x = random.randint(0, CANVAS_WIDTH)
    y = random.randint(0, CANVAS_HEIGHT)
    return (x, y)
# Generate list of N points
def generateNPoints(N):
    points = []
    for i in range(N):
        points.append(generatePoint())
    return points
# Generate a single number N where N runs [x,y]
def generateN(x, y):
    return random.randint(x, y)
# Generate a random list of points
def generatePoints():
    N = generateN(NUM_OF_POINTS_MIN, NUM_OF_POINTS_MAX)
    NPoints = generateNPoints(N)
    return NPoints
# Draw points on screen given a list of points
def drawPoints(points, surface):
    for point in points:
        pygame.draw.circle(surface, (0, 0, 0), point, 3)
# Calculate distance between 2 given points
def calculateDist(point1, point2):
    return math.hypot(point1[0] - point2[0], point1[1] - point2[1])
# ---------------------------------------
# END FUNCTIONS FOR POINTS

# FUNCTIONS FOR CIRCLES
# ---------------------------------------
# Create a circle given center and radius
def createCircle(center, radius):
    return (center, radius)
# Check if a given circle is within bounds
def circleInBounds(circle):
    center, radius = circle
    centerX, centerY = center
    leftBound, rightBound, upBound, downBound = centerX - radius, centerX + radius, centerY - radius, centerY + radius
    return leftBound in range(0, CANVAS_WIDTH + 1) and rightBound in range(0, CANVAS_WIDTH + 1) and upBound in range(0, CANVAS_HEIGHT + 1) and downBound in range(0, CANVAS_HEIGHT + 1)
# Draw circle on screen given circle 
def drawCircle(circle, surface):
    center, radius = circle
    pygame.draw.circle(surface, (255, 0, 0), center, radius, 1)
# ---------------------------------------
# END FUNCTIONS FOR CIRCLES

# FUNCTIONS FOR MAIN ALGORITHM
# ---------------------------------------
# Given a circle and list of points, count the number of points
# that fall on / in the circle
def countPointsInCircle(circle, points):
    count = 0
    center, radius = circle
    for point in points:
        count += 1 if calculateDist(point, center) <= radius else 0
    return count
# Given a a specific radius and a number of points,
# Find a circle of that radius that covers that many points
def circleRcoverN(radius, points, N):
    for x in range(radius, CANVAS_WIDTH - radius + 1):
        for y in range(radius, CANVAS_HEIGHT - radius + 1):
            circle = createCircle((x, y), radius)
            if (countPointsInCircle(circle, points) == N): return circle
    return None
# Given points and percentage, find a circle to cover
# that many points
def findCircle(points, percentage):
    N = int(percentage * len(points))
    maxRadius = int(CANVAS_WIDTH / 2)
    for radius in range(maxRadius, -1, -1):
        circle = circleRcoverN(radius, points, N)
        if (circle != None): return circle
    return None
# ---------------------------------------
# END FUNCTIONS FOR MAIN ALGORITHM

# FUNCTIONS FOR PYGAME
# ---------------------------------------
# Main call for PyGame 
def main():
    # Initialize PyGame
    def initPyGame():
        pygame.init()
        canvas = pygame.display.set_mode([CANVAS_WIDTH, CANVAS_HEIGHT])
        canvas.fill((150, 150, 150))
        # Event loop
        def loopPyGame():
            running = True
            p = generatePoints()
            drawPoints(p, canvas)
            c = findCircle(p, PERCENTAGE)
            drawCircle(c, canvas) if c != None else print("NO SUCH CIRCLE")
            while running:
                pygame.display.update()
                for event in pygame.event.get():
                    if event.type == pygame.QUIT:
                        running = False
        loopPyGame()
    initPyGame()
main()
# ---------------------------------------
# END OF FILE
import pygame
import pymunk
import random

WIDTH, HEIGHT = 1200, 800
WHITE = (255, 255, 255)
BLUE = (0, 0, 255)
RED = (255, 0, 0)
FPS = 60
RADIUS = 15
# RANGE_Vel
a = 100

pygame.init()
pygame.display.set_caption("collisions")
screen = pygame.display.set_mode((WIDTH, HEIGHT))
Clock = pygame.time.Clock()
Space = pymunk.Space()


class Ball():
    def __init__(self, x, y, collision_type):
        self.body = pymunk.Body(1, 100, body_type=pymunk.Body.DYNAMIC)
        self.body.position = x, y
        self.shape = pymunk.Circle(self.body, RADIUS)
        self.shape.elasticity = 1
        self.body.velocity = random.randint(-a, a), random.randint(-a, a)
        self.shape.collision_type = collision_type
        Space.add(self.body, self.shape)

    def draw(self):
        if self.shape.collision_type != 2:
            pygame.draw.circle(screen, RED, self.body.position, RADIUS)
        else:
            pygame.draw.circle(screen, BLUE, self.body.position, RADIUS)

    def change_to_blue(self, arbiter, space, data):
        self.shape.collision_type = 2


class Walls():
    def __init__(self, x1, y1, x2, y2):
        self.body = pymunk.Body(body_type=pymunk.Body.STATIC)
        self.shape = pymunk.Segment(self.body, [x1, y1], [x2, y2], 2)
        self.shape.elasticity = 1
        Space.add(self.body, self.shape)

    def draw(self, x1, y1, x2, y2):
        pygame.draw.lines(screen, RED, 0, [(x1, y1), (x2, y2)], 2)


balls = [Ball(random.randint(0, 1200), random.randint(0, 800), i + 3)
         for i in range(100)]
balls.append(Ball(400, 400, 2))

handlers = [Space.add_collision_handler(2, i + 3) for i in range(100)]
for i, handler in enumerate(handlers):
    handler.separate = balls[i].change_to_blue

floor_d = Walls(0, 798, 1200, 798)
floor_u = Walls(0, 0, 1200, 0)
Wall_l = Walls(0, 0, 0, 800)
Wall_r = Walls(1198, 0, 1198, 800)


def main():
    run = True
    while run == True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return
        screen.fill(WHITE)
        [ball.draw() for ball in balls]
        Wall_l.draw(0, 0, 0, 800)
        Wall_r.draw(1198, 0, 1198, 800)
        floor_d.draw(0, 798, 1200, 798)
        floor_u.draw(0, 0, 1200, 0)
        Space.step(1/FPS)
        Clock.tick(FPS)
        pygame.display.update()


main()
pygame.quit()

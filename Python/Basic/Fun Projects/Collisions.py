import pygame
import pymunk
import random
import math

pygame.init()

a = 400
WIDTH, HEIGHT = 900, 500
BLACK = (255, 255, 255)
RED = (255, 0, 0)
BLACK = (0, 0, 0)
GREEN = (0, 255, 0)
YELLOW = (255, 255, 0)
BLUE = (0, 0, 255)
RADIUS = 15
FPS = 100

screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()
space = pymunk.Space()


class Ball():
    def __init__(self, x, color, category, mask):
        self.body = pymunk.Body(1, 100, body_type=pymunk.Body.DYNAMIC)
        self.body.position = x, 10
        self.shape = pymunk.Circle(self.body, RADIUS)
        self.body.velocity = (random.randint(-a, a),
                              random.randint(-a, a))
        self.shape.elasticity = 1
        self.shape.filter = pymunk.ShapeFilter(categories=category, mask=mask)
        space.add(self.body, self.shape)
        self.color = color

    def draw(self):
        pygame.draw.circle(screen, self.color, self.body.position, RADIUS)


class Floor():
    def __init__(self, y, color, category):
        self.floor_body = pymunk.Body(body_type=pymunk.Body.STATIC)
        self.floor_body_position_x = 0, y
        self.floor_body_position_y = 900, y
        self.floor_shape = pymunk.Segment(self.floor_body, [0, y], [900, y], 5)
        self.floor_shape.elasticity = 1
        self.floor_shape.filter = pymunk.ShapeFilter(categories=category)
        space.add(self.floor_body, self.floor_shape)
        self.color = color

    def draw(self):
        pygame.draw.lines(screen, self.color, 0, [
                          (self.floor_body_position_x), (self.floor_body_position_y)], 5)


class Walls():
    def __init__(self, x, color, category):
        self.walls_body = pymunk.Body(body_type=pymunk.Body.STATIC)
        self.walls_body_position_x = x, 0
        self.walls_body_position_y = x, 500
        self.walls_shape = pymunk.Segment(self.walls_body, [x, 0], [x, 500], 5)
        self.walls_shape.elasticity = 1
        self.walls_shape.filter = pymunk.ShapeFilter(categories=category)
        space.add(self.walls_body, self.walls_shape)
        self.color = color

    def draw(self):
        pygame.draw.lines(screen, self.color, 0, [
                          (self.walls_body_position_x), (self.walls_body_position_y)], 5)


def game():
    run = True
    ball_1 = Ball(200, RED, 1, 126)
    ball_2 = Ball(450, BLUE, 2, 125)
    ball_3 = Ball(700, GREEN, 4, 189)
    floor_1 = Floor(300, BLACK, 64)
    floor_2 = Floor(500, BLACK, 128)
    floor_3 = Floor(0, BLACK, 32)
    walls_1 = Walls(0, BLACK, 8)
    walls_2 = Walls(900, BLACK, 16)
    while run == True:
        i = 1
        i += 0.1
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return

        screen.fill(BLACK)
        space.gravity = (random.randint(-a, a) * math.cos(i),
                         random.randint(-a, a) * math.sin(i))
        floor_1.draw()
        floor_2.draw()
        floor_3.draw()
        walls_1.draw()
        walls_2.draw()
        ball_1.draw()
        ball_2.draw()
        ball_3.draw()
        clock.tick(FPS)
        space.step(1/FPS)
        pygame.display.update()


game()
pygame.quit()

import pygame
import pymunk

pygame.init()

WIDTH, HEIGHT = 900, 500
WHITE = (255, 255, 255)
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
space.gravity = (0, 300)


class Ball():
    def __init__(self, x, color, category, mask):
        self.body = pymunk.Body(1, 100, body_type=pymunk.Body.DYNAMIC)
        self.body.position = x, 0
        self.shape = pymunk.Circle(self.body, RADIUS)
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


def game():
    run = True
    ball_1 = Ball(200, RED, 1, 21)
    ball_2 = Ball(450, GREEN, 2, 22)
    ball_3 = Ball(700, BLUE, 4 ,31)
    floor_1 = Floor(300, BLACK, 8)
    floor_2 = Floor(400, YELLOW, 16)
    while run == True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return

        screen.fill(WHITE)
        ball_1.draw()
        ball_2.draw()
        ball_3.draw()
        floor_1.draw()
        floor_2.draw()
        clock.tick(FPS)
        space.step(1/FPS)
        pygame.display.update()


game()
pygame.quit()

import pygame
import pymunk

RED = (255, 0, 0)
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
WIDTH = 900
HEIGHT = 500
FPS = 60
RADIUS = 30

pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
image = pygame.transform.scale(pygame.image.load(
    "12-basketball-ball-png-image.png"), (RADIUS*2, RADIUS*2))
Clock = pygame.time.Clock()
space = pymunk.Space()
space.gravity = (0, 1000)


class Ball():
    def __init__(self, x=400):
        self.body = pymunk.Body(1, 100, body_type=pymunk.Body.DYNAMIC)
        self.body.position = x,0
        self.shape = pymunk.Circle(self.body, RADIUS)
        self.shape.elasticity = 0.99
        space.add(self.body, self.shape)

    def draw(self):
        #pygame.draw.circle(screen, RED, self.body.position, RADIUS)
        screen.blit(image, (self.body.position.x - RADIUS,
                    self.body.position.y - RADIUS))


class Floor():
    def __init__(self):
        self.segment_body = pymunk.Body(body_type=pymunk.Body.STATIC)
        self.segment_shape = pymunk.Segment(
            self.segment_body, (0, 350), (900, 500), 5)
        self.segment_shape.elasticity = 0.99
        space.add(self.segment_body, self.segment_shape)

    def draw(self):
        pygame.draw.lines(screen, BLACK, 0, [(0, 350), (900, 500)], 5)


run = True
ball_1 = Ball()
ball_2 = Ball(200)
floor = Floor()
while run == True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit
            run = False

    screen.fill(WHITE)
    ball_1.draw()
    ball_2.draw()
    floor.draw()
    pygame.display.update()
    Clock.tick(FPS)
    space.step(1/FPS)
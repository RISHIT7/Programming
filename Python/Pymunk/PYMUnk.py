import pygame
import pymunk

WHITE = (255, 255, 255)
RED = (255,0,0)
BLACK = (0,0,0)
WIDTH = 900
HEIGHT = 500
FPS = 60
RADIUS = 15

space = pymunk.Space()
space.gravity = (0,1000)
screen = pygame.display.set_mode((WIDTH, HEIGHT))
Clock = pygame.time.Clock()

body = pymunk.Body(1, 100, body_type=pymunk.Body.DYNAMIC)
body.position = (1,0)
shape = pymunk.Circle(body, RADIUS)
shape.elasticity = 0.99
shape.friction = 0.5
space.add(body, shape)

segment_body = pymunk.Body(body_type=pymunk.Body.STATIC)
segment_shape = pymunk.Segment(segment_body, [0, 450], [900,500], 5)
space.add(segment_body, segment_shape)
segment_shape.elasticity = 0.67
segment_shape.friction = 0.5

run = True
while run == True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit
            run = False

    pygame.draw.circle(screen, RED, body.position, RADIUS)
    pygame.draw.lines(screen, BLACK, 0, [(0,450), (900,500)], 5)
    pygame.display.update()
    space.step(1/FPS)
    screen.fill(WHITE)
    Clock.tick(FPS)
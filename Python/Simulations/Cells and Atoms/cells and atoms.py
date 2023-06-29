from re import X
import pygame
import pymunk
import random
import math

WHITE = (255, 255, 255)
RED = (255,0,0)
BLACK = (0,0,0)
WIDTH = 900
HEIGHT = 500
FPS = 60
RADIUS = 15
TIMESTEP = 1/3600

space = pymunk.Space()
space.gravity = (0,300)
screen = pygame.display.set_mode((WIDTH, HEIGHT))
Clock = pygame.time.Clock()

body1 = pymunk.Body(101, 1, body_type=pymunk.Body.DYNAMIC)
body1.position = random.randint(200,300), random.randint(200,300)
body1.velocity = random.randint(200,300), random.randint(200,300)
shape1 = pymunk.Circle(body1, RADIUS)
shape1.elasticity = 1
space.add(body1, shape1)

body2 = pymunk.Body(101, 1, body_type=pymunk.Body.DYNAMIC)
body2.position = random.randint(200,300), random.randint(200,300)
body2.velocity = random.randint(200,300), random.randint(200,300)
shape2 = pymunk.Circle(body2, RADIUS)
shape2.elasticity = 1
space.add(body2, shape2)

segment1_body = pymunk.Body(body_type=pymunk.Body.STATIC)
segment1_shape = pymunk.Segment(segment1_body, [0, 0], [0,500], 1)
space.add(segment1_body, segment1_shape)
segment1_shape.elasticity = 1

segment2_body = pymunk.Body(body_type=pymunk.Body.STATIC)
segment2_shape = pymunk.Segment(segment2_body, [0, 500], [900,500], 1)
space.add(segment2_body, segment2_shape)
segment2_shape.elasticity = 1

segment3_body = pymunk.Body(body_type=pymunk.Body.STATIC)
segment3_shape = pymunk.Segment(segment3_body, [900, 500], [900,0], 1)
space.add(segment3_body, segment3_shape)
segment3_shape.elasticity = 1

segment4_body = pymunk.Body(body_type=pymunk.Body.STATIC)
segment4_shape = pymunk.Segment(segment4_body, [900, 0], [0,0], 1)
space.add(segment4_body, segment4_shape)
segment4_shape.elasticity = 1

run = True
while run == True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit
            run = False

    pygame.draw.circle(screen, RED, body1.position, RADIUS)
    pygame.draw.circle(screen, RED, body2.position, RADIUS)
    pygame.display.update()
    space.step(1/FPS)
    screen.fill(WHITE)
    Clock.tick(FPS)

import pymunk
import pygame
import pymunk.pygame_util
import math

pygame.init()

WHITE = (255, 255, 255)
RED = (255, 0, 0, 100)
BLACK = (0, 0, 0)
WIDTH, HEIGHT = 1200, 800
RADIUS = 15
window = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Tech with Tim")


def calculateDistance(p1, p2):
    return math.sqrt((p2[1] - p1[1])**2 + (p2[0] - p1[0])**2)


def calcAngle(p1, p2):
    return math.atan2(p2[1] - p1[1], p2[0] - p1[0])


def draw(space, window, draw_options, line):
    window.fill(WHITE)

    if line:
        pygame.draw.line(window, BLACK, line[0], line[1], 3)

    space.debug_draw(draw_options)
    pygame.display.update()


def create_boundaries(space, width, height):
    rects = [
        [(width/2, height - 10), (width, 20)],
        [(width/2, 10), (width, 20)],
        [(10, height/2), (20, height)],
        [(width - 10, height/2), (20, height)],
    ]

    for pos, size in rects:
        body = pymunk.Body(body_type=pymunk.Body.STATIC)
        body.position = pos
        shape = pymunk.Poly.create_box(body, size)
        shape.elasticity = 0.5
        shape.friction = 0.4
        space.add(body, shape)


def addObject(space, pos):
    body = pymunk.Body(1, 100, body_type=pymunk.Body.STATIC)
    shape = pymunk.Circle(body, RADIUS)
    body.position = pos
    shape.color = RED
    shape.elasticity = 0.9
    space.add(body, shape)
    return shape


def run(window, width, height):
    run = True
    clock = pygame.time.Clock()
    FPS = 60

    space = pymunk.Space()
    space.gravity = (0, 300)

    ball = None
    pressed_pos = None

    create_boundaries(space, width, height)

    draw_options = pymunk.pygame_util.DrawOptions(window)

    while run:
        line = None
        if ball and pressed_pos:
            line = [pressed_pos, event.pos]
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
                break

            if event.type == pygame.MOUSEBUTTONDOWN:
                if not ball:
                    pressed_pos = event.pos
                    ball = addObject(space, pressed_pos)
                elif pressed_pos:
                    ball.body.body_type = pymunk.Body.DYNAMIC
                    ball.body.apply_impulse_at_local_point((1000, 0), (0, 0))
                    pressed_pos = None
                else:
                    space.remove(ball, ball.body)
                    ball = None

        draw(space, window, draw_options, line)
        space.step(1/FPS)
        clock.tick(FPS)

    pygame.quit()


if __name__ == "__main__":
    run(window, WIDTH, HEIGHT)

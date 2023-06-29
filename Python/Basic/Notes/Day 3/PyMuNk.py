import pygame
import pymunk

WIDTH, HEIGHT = 800,800
WHITE = (255,255,255)
FPS = 60
RED = (255,0,0)
BLACK = (0,0,0)
RADIUS = 15

pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Game")
Clock = pygame.time.Clock()
Space = pymunk.Space()
Space.gravity = (0,300)

class Ball():
    def __init__(self):
        self.body = pymunk.Body(1, 100 ,body_type=pymunk.Body.DYNAMIC)
        self.body.position = 1, 0
        self.shape = pymunk.Circle(self.body, RADIUS)
        self.shape.elasticity = 1
        Space.add(self.body, self.shape)

    def draw(self):
        pygame.draw.circle(screen, RED, self.body.position, RADIUS)


class Floor():
    def __init__(self):
        self.body = pymunk.Body(body_type=pymunk.Body.STATIC)
        self.shape = pymunk.Segment(self.body, [0,700], [800,800], 5)
        self.shape.elasticity = 1
        Space.add(self.body, self.shape)
    def draw(self):
        pygame.draw.lines(screen, BLACK, 0, [(0,700), (800,800)], 5)



ball = Ball()
floor = Floor()

def main():
    run = True
    while run == True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return
        screen.fill(WHITE)
        ball.draw()
        floor.draw()
        Clock.tick(FPS)
        Space.step(1/FPS)
        pygame.display.update()
main()
pygame.quit()

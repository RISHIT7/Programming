import pygame
import pymunk

WIDTH, HEIGHT = 1200, 800
WHITE = (255, 255, 255)
ORANGE = (240, 120, 50)
BLACK = (0, 0, 0)
FPS = 60
RADIUS = 15

pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Bouncing BasketBall")
image = pygame.transform.scale(pygame.image.load(
    "12-basketball-ball-png-image.png"), (RADIUS*2, RADIUS*2))
Clock = pygame.time.Clock()
Space = pymunk.Space()
Space.gravity = (0, 300)
Space.damping = 0.9


class Ball():
    def __init__(self):
        self.body = pymunk.Body(1, 100, body_type=pymunk.Body.DYNAMIC)
        self.body.position = 1, 0
        self.shape = pymunk.Circle(self.body, RADIUS)
        self.shape.elasticity = 1
        self.shape.friction = 0.1
        Space.add(self.body, self.shape)

    def draw(self):
        screen.blit(image, (self.body.position.x - RADIUS, self.body.position.y - RADIUS))


class Floor():
    def __init__(self):
        self.body = pymunk.Body(body_type=pymunk.Body.STATIC)
        self.shape = pymunk.Segment(self.body, [0, 700], [1200, 800], 2)
        self.shape.elasticity = 1
        self.shape.friction = 0.1
        Space.add(self.body, self.shape)

    def draw(self):
        pygame.draw.lines(screen, BLACK, 0, [(0, 700), (1200, 800)], 2)


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
        Space.step(1/FPS)
        Clock.tick(FPS)
        pygame.display.update()


main()
pygame.quit()

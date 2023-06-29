import pygame
import pymunk

pygame.init()

WIDTH = 800
HEIGHT = 800
BLUE = (47, 47, 247)
WHITE = (255, 255, 255)
FPS = 60
RADIUS = 10

screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()
space = pymunk.Space()
pygame.display.set_caption("Joints")
space.gravity = (0, 900)
space.damping = 0.9


class Ball():
    def __init__(self, x, y):
        self.body = pymunk.Body(1, 100, body_type=pymunk.Body.DYNAMIC)
        self.body.position = x, y
        self.shape = pymunk.Circle(self.body, RADIUS)
        self.shape.elasticity = 1
        space.add(self.body, self.shape)

    def draw(self):
        pygame.draw.circle(screen, BLUE, self.body.position, RADIUS)


class String():
    def __init__(self, body1, attachment, identifier="body"):
        self.body1 = body1
        if identifier == "body":
            self.body2 = attachment
        elif identifier == "position":
            self.body2 = pymunk.Body(body_type=pymunk.Body.STATIC)
            self.body2.position = attachment
        joint = pymunk.PinJoint(self.body1, self.body2)
        space.add(joint)

    def draw(self):
        pos1 = self.body1.position
        pos2 = self.body2.position
        pygame.draw.line(screen, (0, 0, 0), pos1, pos2, 2)


def game():
    ball_1 = Ball(400, 300)
    ball_2 = Ball(300, 200)
    string_1 = String(ball_1.body, (WIDTH / 2, HEIGHT / 2), "position")
    string_2 = String(ball_1.body, ball_2.body)

    run = True
    while run == True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return
                run = False
        screen.fill(WHITE)
        string_1.draw()
        string_2.draw()
        ball_1.draw()
        ball_2.draw()
        pygame.display.update()
        clock.tick(FPS)
        space.step(1/FPS)


game()
pygame.quit()

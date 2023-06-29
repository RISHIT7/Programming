import random
import pygame
import pymunk

pygame.init()

BLACK = (0, 0, 0)
MIDX, MIDY = 600, 400
WHITE = (255, 255, 255)
WIDTH, HEIGHT = 1200, 800
FPS = 100
RADIUS = 8
THICKNESS = 10
vel = 300

top = 25
bottom = 775
right = 1150
left = 50

pygame.display.set_caption("Pong")
screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()
space = pymunk.Space()


class Ball:
    def __init__(self):
        self.body = pymunk.Body(1, 100, body_type=pymunk.Body.DYNAMIC)
        self.body.position = MIDX, MIDY
        self.body.velocity = random.randint(-vel,
                                            vel) + vel, random.randint(-vel, vel) + vel
        self.shape = pymunk.Circle(self.body, RADIUS)
        self.shape.elasticity = 1
        self.shape.collision_type = 1
        space.add(self.body, self.shape)

    def draw(self):
        pygame.draw.circle(screen, WHITE, self.body.position, RADIUS)


class Wall:
    def __init__(self, p1, p2, collision_type=None):
        self.body = pymunk.Body(body_type=pymunk.Body.STATIC)
        self.shape = pymunk.Segment(self.body, p1, p2, THICKNESS)
        self.shape.elasticity = 1
        space.add(self.body, self.shape)
        if collision_type:
            self.shape.collision_type = 2

    def draw(self):
        pygame.draw.line(screen, WHITE, self.shape.a, self.shape.b, THICKNESS)

class Player:
    def __init__(self, x):
        self.body = pymunk.Body(body_type=pymunk.Body.KINEMATIC)
        self.body.position = x, MIDY
        self.shape = pymunk.Segment(self.body, [0, -30], [0, 30], THICKNESS)
        self.shape.elasticity = 1
        self.shape.friction = 0.3
        space.add(self.body, self.shape)
    
    def draw(self):
        p1 = self.body.local_to_world(self.shape.a)
        p2 = self.body.local_to_world(self.shape.b)
        pygame.draw.line(screen, WHITE, p1 ,p2, THICKNESS)
    
    def handleMovement(self, keys):
        if keys[pygame.K_UP] or keys[pygame.K_w]:
            self.body.velocity = 0, -300
        elif keys[pygame.K_DOWN] or keys[pygame.K_s]:
            self.body.velocity = 0, 300
    
    def stop(self):
        self.body.velocity = 0, 0

player1 = Player(left + 15)
player2 = Player(right - 15)
ball = Ball()
wall_right = Wall([right, top], [right, bottom], 2)
wall_left = Wall([left, top], [left, bottom], 2)
wall_top = Wall([left, top] ,[right, top])
wall_bottom = Wall([left, bottom], [right, bottom])

def main():
    run = True
    while run:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
                break
        keys = pygame.key.get_pressed()
        if keys[pygame.K_UP] or keys[pygame.K_DOWN]:
            player2.handleMovement(keys)
        elif keys[pygame.K_w] or keys[pygame.K_s]:
            player1.handleMovement(keys)
        else :
            player1.stop()
            player2.stop()


        screen.fill(BLACK)
        player1.draw()
        player2.draw()
        ball.draw()
        wall_bottom.draw()
        wall_top.draw()
        wall_right.draw()
        wall_left.draw()
        clock.tick(FPS)
        space.step(1/FPS)
        pygame.display.update()

    pygame.quit()


if __name__ == "__main__":
    main()

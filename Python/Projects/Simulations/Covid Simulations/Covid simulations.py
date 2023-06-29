from cgitb import handler
from logging import handlers
import pygame
import pymunk
import random
import matplotlib.pyplot as plt


WIDTH, HEIGHT = 800, 800
pygame.init()
pygame.display.set_caption("Covid Simulation")
Space = pymunk.Space()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
Clock = pygame.time.Clock()
FPS = 60


population = 400
recovery_time = 5 * FPS


class Ball():
    def __init__(self, x, y, collision_type):
        self.body = pymunk.Body(1, 100, body_type=pymunk.Body.DYNAMIC)
        self.shape = pymunk.Circle(self.body, 10)
        self.shape.elasticity = 1
        self.body.position = x, y
        self.body.velocity = random.uniform(-100,
                                            100), random.uniform(-100, 100)
        self.shape.collision_type = collision_type
        self.infected_time = 0
        Space.add(self.body, self.shape)

    def pass_time(self):
        if self.shape.collision_type == 1:
            self.infected_time += 1
            if self.infected_time >= recovery_time:
                self.shape.collision_type = 0
            elif self.infected_time < recovery_time:
                pass

    def infect(self, arbiter, space, data):
        self.shape.collision_type = 1

    def draw(self):
        if self.shape.collision_type != 1 and self.shape.collision_type != 0:
            pygame.draw.circle(screen, (255, 255, 255), self.body.position, 10)
        elif self.shape.collision_type == 0:
            pygame.draw.circle(screen, (0, 0, 255), self.body.position, 10)
        else:
            pygame.draw.circle(screen, (255, 0, 0), self.body.position, 10)


class Walls():
    def __init__(self, x1, y1, x2, y2):
        self.body = pymunk.Body(body_type=pymunk.Body.STATIC)
        self.shape = pymunk.Segment(self.body, [x1, y1], [x2, y2], 2)
        self.shape.elasticity = 1
        Space.add(self.body, self.shape)

    def draw(self, x1, y1, x2, y2):
        pygame.draw.lines(screen, (0, 0, 0), 0, [(x1, y1), (x2, y2)], 2)


balls = [Ball(random.randint(0, WIDTH), random.randint(0, HEIGHT), i + 2)
         for i in range(population)]
balls.append(Ball(400, 400, 1))
handlers = [Space.add_collision_handler(1, i + 2) for i in range(population)]
for i, handler in enumerate(handlers):
    handler.separate = balls[i].infect


floor_d = Walls(0, HEIGHT - 2, WIDTH, HEIGHT - 2)
floor_u = Walls(0, 0, WIDTH, 0)
Wall_l = Walls(0, 0, 0, HEIGHT)
Wall_r = Walls(WIDTH - 2, 0, WIDTH - 2, HEIGHT)

infected_count = []
def main():
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return
        screen.fill((0, 0, 0))
        infected_count_thisframe = 0
        for ball in balls:
            ball.draw()
            ball.pass_time()
            if ball.shape.collision_type == 1:
                infected_count_thisframe += 1
        if len(infected_count) <= 1000:
            infected_count.append(infected_count_thisframe)
        pygame.display.update()
        Space.step(1/FPS)
        Clock.tick(FPS)
main()

pygame.quit()


plt.plot(range(0, len(infected_count)), infected_count)
plt.show()

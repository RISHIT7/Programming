import pygame
import pymunk
pygame.init()

screen = pygame.display.set_mode((800,800))
clock = pygame.time.Clock()
space = pymunk.Space()
space.gravity = 0,300
image = pygame.image.load(r"C:\Users\rishi\Desktop\Programming\Python\Modules\Pygame\Pygame_1\Apple.png")

class Apple():
    def __init__(self, pos):
        self.body = pymunk.Body(1, 100, body_type=pymunk.Body.DYNAMIC)
        self.body.position = pos
        self.shape = pymunk.Circle(self.body, 32)
        space.add(self.body, self.shape)
    def draw(self):
        screen.blit(image, (self.body.position.x - 40, self.body.position.y - 40))

class Static():
    def __init__(self, x, y):
        self.body = pymunk.Body(body_type=pymunk.Body.STATIC)
        self.body.position = x, y
        self.shape = pymunk.Circle(self.body, 35)
        space.add(self.body, self.shape)

    def draw(self):
        pygame.draw.circle(screen, (255,0,0), self.body.position, 35)

apples = []
ball_1 = Static(300,300)
ball_2 = Static(500,400)
def main():
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return
            if event.type == pygame.MOUSEBUTTONDOWN:
                apples.append(Apple(event.pos))
        screen.fill((0,0,0))
        [apple.draw() for apple in apples]
        ball_1.draw()
        ball_2.draw()
        clock.tick(60)
        space.step(1/60)
        pygame.display.update()

main()
pygame.quit()
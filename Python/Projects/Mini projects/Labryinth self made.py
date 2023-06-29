import pygame


WIDTH, HEIGHT = 800, 800
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)
FPS = 60
RED = (255, 0, 0)

pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Labyrinth")
clock = pygame.time.Clock()

class Player():
    def draw(self, x, y):
        self.x = x
        self.y = y
        pygame.draw.polygon(
            screen, GREEN, [(x-10, y-10), (x-10, y+10), (x+10, y+10), (x+10, y-10)])


class Destination():
    def draw(self, X, Y):
        pygame.draw.polygon(
            screen, RED, [(X-10, Y-10), (X-10, Y+10), (X+10, Y+10), (X+10, Y-10)])


player = Player()
destination = Destination()
def main():
    run = True
    x = 400
    y = 400
    while run == True:
        screen.fill(WHITE)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return
        key = pygame.key.get_pressed()
        if key[pygame.K_LEFT]:
            x -= 5
        if key[pygame.K_RIGHT]:
            x += 5
        if key[pygame.K_DOWN]:
            y += 5
        if key[pygame.K_UP]:
            y -= 5
        player.draw(x, y)
        destination.draw(10,10)
        clock.tick(FPS)
        pygame.display.update()


main()
pygame.quit()
run = False

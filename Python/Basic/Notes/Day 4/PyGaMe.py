import pygame
import sys
# Don't name your file pygame

# To initiate pygame
pygame.init()
# Set a clock in pygame
Clock = pygame.time.Clock()
# A display screen
screen = pygame.display.set_mode((900, 500))
# Pygame does not display regular surfaces, hence "screen.blit" must be used
second_surface = pygame.Surface([100,200])
second_surface.fill((0,0,125))

# You may also load a pictur using variable = pygame.image.load("file name.extension")
# Ans use screen.blit(variable, (x,y)) to show the photo

# Main loop
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit

    screen.fill((125, 125, 125))
    screen.blit(second_surface, (0, 50))
    pygame.display.flip()
    Clock.tick(60)

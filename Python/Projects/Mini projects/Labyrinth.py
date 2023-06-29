import os
import sys
import pygame
 
class Player(object):
 
    def __init__(self):
        self.rect = pygame.Rect(32, 32, 16, 16)
 
    def move(self, dx, dy):
        if dx != 0:
            self.move_single_axis(dx, 0)
        if dy != 0:
            self.move_single_axis(0, dy)
 
    def move_single_axis(self, dx, dy):
        self.rect.x += dx
        self.rect.y += dy
        self.collision(dx, dy)
 
    def collision(self, dx, dy):
        for wall in walls:
            if self.rect.colliderect(wall.rect):
                if dx > 0:
                    self.rect.right = wall.rect.left
                if dx < 0:
                    self.rect.left = wall.rect.right
                if dy > 0:
                    self.rect.bottom = wall.rect.top
                if dy < 0:
                    self.rect.top = wall.rect.bottom
 
 
class Wall(object):
 
    def __init__(self, pos):
        walls.append(self)
        self.rect = pygame.Rect(pos[0], pos[1], 16, 16)
 
 
os.environ["SDL_VIDEO_CENTERED"] = "1"
pygame.init()
 
 
pygame.display.set_caption("Get to the red square!")
screen = pygame.display.set_mode((360, 270))
 
clock = pygame.time.Clock()
walls = []
player = Player()
 
# Holds the level layout in a list of strings.
level = """
WWWWWWWWWWWWWWWWWWWW
W                  W
W         WWWWWW   W
W   WWWW       W   W
W   W        WWWW  W
W WWW  WWWW        W
W   W     W W      W
W   W     W   WWW WW
W   WWW WWW   W W  W
W     W   W   W W  W
WWW   W   WWWWW W  W
W W      WW        W
W W   WWWW   WWW   W
W     W    E   W   W
WWWWWWWWWWWWWWWWWWWW
""".splitlines()[1:]
 
# Parse the level string above. W = wall, E = exit
x = y = 1
for row in level:
    for col in row:
        if col == "W":
            Wall((x, y))
        if col == "E":
            end_rect = pygame.Rect(x, y, 10, 10)
        x += 18
    y += 18
    x = 1
 
running = True
while running:
    
    clock.tick(60)
    
    for e in pygame.event.get():
        if e.type == pygame.QUIT:
            running = False
        if e.type == pygame.KEYDOWN and e.key == pygame.K_ESCAPE:
            running = False
 
    # Move the player if an arrow key is pressed
    key = pygame.key.get_pressed()
    if key[pygame.K_LEFT]:
        player.move(-2, 0)
    if key[pygame.K_RIGHT]:
        player.move(2, 0)
    if key[pygame.K_UP]:
        player.move(0, -2)
    if key[pygame.K_DOWN]:
        player.move(0, 2)
 
    # Just added this to make it slightly fun ;)
    if player.rect.colliderect(end_rect):
        pygame.quit()
        sys.exit()
 
    # Draw the scene
    screen.fill((0, 0, 0))
    for wall in walls:
        pygame.draw.ellipse(screen, (0, 128, 64), wall.rect)
    pygame.draw.rect(screen, (255, 0, 0), end_rect)
    pygame.draw.rect(screen, (255, 200, 0), player.rect)
    # gfxdraw.filled_circle(screen, 255, 200, 5, (0,128,128))
    pygame.display.flip()
    clock.tick(360)
 
pygame.quit()
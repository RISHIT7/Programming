import random
import pygame
import math
pygame.init()

screen = pygame.display.set_mode((1200, 800))
clock = pygame.time.Clock()


def ball1(x1, y1):
    pygame.draw.circle(screen, (0, 0, 0), (x1, y1), 8)

def ball2(x2, y2):
    pygame.draw.circle(screen, (0,0,0), (x2, y2), 8)

def main():
    run = True
    t = 1/50
    v1x = 50
    v1y = 40
    v2x = -60
    v2y = -50
    mass = 10
    x1, y1 = 100, 100
    x2, y2 = 400, 400
    while run:

        delx = x2 - x1
        dely = y2 - y1
        sqdis = math.sqrt(delx**2 + dely**2)
        if sqdis < 50:
            x1 = random.randint(0, 1200)
            y1 = random.randint(0, 800)
            x2 = random.randint(0, 1200)
            y2 = random.randint(0, 800)

        theta = math.atan2(dely, delx)

        force = 10**7/sqdis**2
        forcex = force*math.cos(theta)
        forcey = force*math.sin(theta)


        a1x = forcex / mass
        a1y = forcey / mass
        a2x = -forcex / mass
        a2y = -forcey / mass

        x1 += v1x*t
        x2 += v2x*t
        y1 += v1y*t
        y2 += v2y*t

        v1x += a1x*t
        v1y += a1y*t
        v2x += a2x*t
        v2y += a2y*t

        if 0 > x1 or x1 > 1200:
            v1x = -v1x
        if 0 > y1 or y1 > 800:
            v1y = -v1y
        if 0 > x2 or x2 > 1200:
            v2x = -v2x
        if 0 > y2 or y2 > 800:
            v2y = -v2y


        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
                break
        screen.fill((255, 255, 255))
        ball1(x1, y1)
        ball2(x2, y2)
        clock.tick(100)
        pygame.display.update()

    pygame.quit()


if __name__ == "__main__":
    main()

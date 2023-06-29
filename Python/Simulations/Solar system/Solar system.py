import pygame
import math
pygame.init()

WIDTH, HEIGHT = 800, 800
WIN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Planet Simulation")
Back_ground = pygame.transform.scale(
    (pygame.image.load("BackG.jpg")), (WIDTH, HEIGHT))

WHITE = (255, 255, 255)
YELLOW = (255, 255, 0)
BLUE = (100, 149, 247)
RED = (188, 39, 50)
DARK_GREY = (80, 78, 80)
AU = 149.6e6 * 1000

FONT = pygame.font.SysFont("comicsans", 16)


class Planet:

    AU = 149.6e6 * 1000
    G = 6.7428e-11
    SCALE = 250 / AU  # 1 AU = 250px
    TIMESTEP = 3600*24  # 1 day

    def __init__(self, x, y, radius, color, mass):
        self.x = x
        self.y = y
        self.color = color
        self.mass = mass
        self.radius = radius

        self.orbit = []
        self.sun = False
        self.distance_to_sun = 0

        self.x_vel = 0
        self.y_vel = 0

    def draw(self, win):
        x = self.x * self.SCALE + WIDTH / 2
        y = self.y * self.SCALE + HEIGHT / 2

        if len(self.orbit) > 2:
            updated_points = []
            for point in self.orbit:
                x, y = point
                x = x * self.SCALE + WIDTH / 2
                y = y * self.SCALE + HEIGHT / 2
                updated_points.append((x, y))
        
            pygame.draw.lines(win, self.color, 0, updated_points, 2)

        pygame.draw.circle(win, self.color, (x, y), self.radius)
        if not self.sun:
            distance_text = FONT.render(f"{round(self.distance_to_sun/AU, 2)}AU", 1, WHITE)
            WIN.blit(distance_text, (x - distance_text.get_width()/2, y - distance_text.get_height()/2))

    def new_method(self):
        return False

    def attraction(self, other):
        other_x, other_y = other.x, other.y
        distance_x = other.x - self.x
        distance_y = other.y - self.y
        distance = math.sqrt(distance_x ** 2 + distance_y ** 2)

        if other.sun:
            self.distance_to_sun = distance

        force = self.G * (self.mass * other.mass) / (distance**2)
        theta = math.atan2(distance_y, distance_x)
        force_x = math.cos(theta)*force
        force_y = math.sin(theta)*force
        return force_x, force_y

    def update_position(self, planets):
        total_fx = total_fy = 0
        for planet in planets:
            if self == planet:
                continue
            fx, fy = self.attraction(planet)
            total_fx += fx
            total_fy += fy

        self.x_vel += total_fx / self.mass * self.TIMESTEP
        self.y_vel += total_fy / self.mass * self.TIMESTEP

        self.x += self.x_vel * self.TIMESTEP
        self.y += self.y_vel * self.TIMESTEP
        self.orbit.append((self.x, self.y))


def main():
    run = True
    clock = pygame.time.Clock()

    sun = Planet(0, 0, 30, YELLOW, 1.98892 * 10**30)
    sun.sun = True

    earth = Planet(-1 * Planet.AU, 0, 16, BLUE, 5.9742 * 10**24)
    earth.y_vel = 29.077 * 1000

    mars = Planet(-1.524 * Planet.AU, 0, 12, RED, 6.39 * 10**23)
    mars.y_vel = 24.077 * 1000

    mercury = Planet(0.387 * Planet.AU, 0, 8, DARK_GREY, 0.330 * 10**24)
    mercury.y_vel = 47.4 * 1000

    Venus = Planet(0.723 * Planet.AU, 0, 14, WHITE, 4.8685 * 10**24)
    Venus.y_vel = -35.02 * 1000

    planets = [sun, earth, mars, mercury, Venus]

    while run:
        clock.tick(60)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

        for planet in planets:
            planet.update_position(planets)
            planet.draw(WIN)
        pygame.display.update()
        WIN.blit(Back_ground, (0, 0))

    pygame.quit()


main()

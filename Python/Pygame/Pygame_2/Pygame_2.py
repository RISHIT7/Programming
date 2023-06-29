import pygame
import os
pygame.font.init()
pygame.mixer.init()

WIDHT, HEIGHT = 900, 500
WIN = pygame.display.set_mode((WIDHT, HEIGHT))
pygame.display.set_caption("First Game")

BORDER = pygame.Rect(445, 0, 10, 500)

BULLET_HIT_SOUND = pygame.mixer.Sound(r"Python\Pygame\Pygame_2\Assets\Grenade+1.mp3")
BULLET_FIRE_SOUND = pygame.mixer.Sound(os.path.join("Assets", "Gun+Silencer.mp3"))
WINNER_SOUND = pygame.mixer.Sound(os.path.join("Assets", "Trumpet.mp3"))

HEALTH_FONT = pygame.font.SysFont("comicsans", 40)
WINNER_FONT = pygame.font.SysFont("comicsans", 100)

FPS = 60
Vel = 5
BULLET_Vel = 7
MAX_BULLETS = 3
BLACK = (0, 0, 0)
RED = (255, 0, 0)
YELLOW = (255, 255, 0)

YELLOW_HIT = pygame.USEREVENT + 1
RED_HIT = pygame.USEREVENT + 2

YELLOW_SPACESHIP_IMAGE = pygame.image.load(
    os.path.join("Assets", "spaceship_yellow.png"))
YELLOW_SPACESHIP = pygame.transform.rotate(
    pygame.transform.scale(YELLOW_SPACESHIP_IMAGE, (55, 40)), 270)

RED_SPACESHIP_IMAGE = pygame.image.load(
    os.path.join("Assets", "spaceship_red.png"))
RED_SPACESHIP = pygame.transform.rotate(
    pygame.transform.scale(RED_SPACESHIP_IMAGE, (55, 40)), 90)

SPACE = pygame.transform.scale(pygame.image.load(
    os.path.join("Assets", "space.png")), (WIDHT, HEIGHT))


def draw_window(red, yellow, red_bullets, yellow_bullets, red_health, yellow_health):
    WIN.blit(SPACE, (0, 0))
    pygame.draw.rect(WIN, BLACK, BORDER)

    red_health_text = HEALTH_FONT.render(
        "Health: " + str(red_health), 1, (255, 255, 255))
    yellow_health_text = HEALTH_FONT.render(
        "Health: " + str(yellow_health), 1, (225, 255, 255))
    WIN.blit(red_health_text, (WIDHT - red_health_text.get_width() - 10, 10))
    WIN.blit(yellow_health_text, (10, 10))
    WIN.blit(YELLOW_SPACESHIP, (yellow.x, yellow.y))
    WIN.blit(RED_SPACESHIP, (red.x, red.y))

    for bullet in red_bullets:
        pygame.draw.rect(WIN, RED, bullet)

    for bullet in yellow_bullets:
        pygame.draw.rect(WIN, YELLOW, bullet)

    pygame.display.update()


def yellow_handlemovement(keys_pressed, yellow):
    if keys_pressed[pygame.K_a] and yellow.x - Vel > 0:  # Left
        yellow.x -= Vel
    if keys_pressed[pygame.K_d] and yellow.x + Vel < BORDER.x - 40:  # Right
        yellow.x += Vel
    if keys_pressed[pygame.K_w] and yellow.y - Vel > 0:  # Up
        yellow.y -= Vel
    if keys_pressed[pygame.K_s] and yellow.y + Vel < HEIGHT - yellow.height - 15:  # Down
        yellow.y += Vel


def red_handlemovement(keys_pressed, red):
    if keys_pressed[pygame.K_LEFT] and red.x - Vel > BORDER.x + 10:  # Left
        red.x -= Vel
    if keys_pressed[pygame.K_RIGHT] and red.x + Vel < WIDHT - 40:  # Right
        red.x += Vel
    if keys_pressed[pygame.K_UP] and red.y - Vel > 0:  # Up
        red.y -= Vel
    if keys_pressed[pygame.K_DOWN] and red.y - Vel < HEIGHT - red.height - 25:  # Down
        red.y += Vel


def handle_bullets(yellow_bullets, red_bullets, yellow, red):
    for bullets in yellow_bullets:
        bullets.x += BULLET_Vel
        if red.colliderect(bullets):
            pygame.event.post(pygame.event.Event(RED_HIT))
            yellow_bullets.remove(bullets)
        elif bullets.x > WIDHT:
            yellow_bullets.remove(bullets)

    for bullets in red_bullets:
        bullets.x -= BULLET_Vel
        if yellow.colliderect(bullets):
            pygame.event.post(pygame.event.Event(YELLOW_HIT))
            red_bullets.remove(bullets)
        elif bullets.x < 0:
            red_bullets.remove(bullets)


def draw_winner(text):
    draw_text = WINNER_FONT.render(text, 1, (255,255,255))
    WIN.blit(draw_text, (WIDHT/2 - draw_text.get_width()/2, HEIGHT/2 - draw_text.get_height()/2))
    pygame.display.update()
    pygame.time.delay(3000)


def main():
    red = pygame.Rect(700, 300, 55, 40)
    yellow = pygame.Rect(100, 300, 55, 40)

    red_bullets = []
    yellow_bullet = []

    red_health = 10
    yellow_health = 10

    clock = pygame.time.Clock()
    run = True
    while run:
        clock.tick(FPS)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
                pygame.quit()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LSHIFT and len(yellow_bullet) < MAX_BULLETS:
                    bullet = pygame.Rect(
                        yellow.x + yellow.width, yellow.y + yellow.height//2 - 2, 10, 5)
                    yellow_bullet.append(bullet)
                    BULLET_FIRE_SOUND.play()

                if event.key == pygame.K_RSHIFT and len(red_bullets) < MAX_BULLETS:
                    bullet = pygame.Rect(
                        red.x, red.y + red.height//2 - 2, 10, 5)
                    red_bullets.append(bullet)
                    BULLET_FIRE_SOUND.play()

            if event.type == RED_HIT:
                red_health -= 1
                BULLET_HIT_SOUND.play()

            if event.type == YELLOW_HIT:
                yellow_health -= 1
                BULLET_HIT_SOUND.play()
        winner_text = ""

        if red_health <= 0:
            winner_text = "Yellow Wins!"

        if yellow_health <= 0:
            winner_text = "Red Wins!"

        if winner_text != "":
            WINNER_SOUND.play()
            draw_winner(winner_text)
            break

        keys_pressed = pygame.key.get_pressed()
        yellow_handlemovement(keys_pressed, yellow)
        red_handlemovement(keys_pressed, red)

        handle_bullets(yellow_bullet, red_bullets, yellow, red)

        draw_window(red, yellow, red_bullets, yellow_bullet,
                    red_health, yellow_health)

    main()


if __name__ == "__main__":
    main()

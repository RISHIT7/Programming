import random
import pygame
pygame.init()


WIDTH, HEIGHT = 1200, 800
MULTIPLIER = 7
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
FONT = pygame.font.SysFont('Arial', 15)
MAIN = pygame.font.SysFont('Arial', 15, bold=True)

screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()
pygame.display.set_caption("Visualizer")


def text(FPS, algo_name):
    startstop = FONT.render(
        "R - Reset | SPACE - Start Sorting | BACKSPACE - End Sorting", 1, WHITE)
    screen.blit(startstop, ((WIDTH - startstop.get_width())//2, 5))

    choosesort = FONT.render("i - Insertion Sort | b - Bubble Sort | s - Selection Sort", 1, WHITE)
    screen.blit(choosesort, ((WIDTH - choosesort.get_width())//2, 25))

    choosePace = FONT.render(
        "up key - Fast | Equals sign - Medium | down key - Slow pace", 1, WHITE)
    screen.blit(choosePace, ((WIDTH - choosePace.get_width())//2, 45))

    CHOICE = MAIN.render(f"Pace - {FPS} | Algorithm - {algo_name}", 1, WHITE)
    screen.blit(CHOICE, ((WIDTH - CHOICE.get_width())//2, 65))


class Bars:
    def __init__(self, arr, height, pos, current=False):
        self.width = WIDTH / len(arr)
        self.height = (HEIGHT - height)
        self.pos = pos
        self.current = current

    def draw(self):
        if self.current:
            pygame.draw.polygon(screen, RED, [(self.pos, self.height), (
                self.pos+self.width, self.height), (self.pos+self.width, HEIGHT), (self.pos, HEIGHT)])
        else:
            pygame.draw.polygon(screen, WHITE, [(self.pos, self.height), (
                self.pos+self.width, self.height), (self.pos+self.width, HEIGHT), (self.pos, HEIGHT)])


def randomise():
    arr = []
    for _ in range(100):
        arr.append(random.randint(10, 90))
    return arr

def bubble_sort(arr):
    for i in range(len(arr)-1):
        for j in range(len(arr)-1-i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                yield True
    return arr

def selection_sort(A):
    for i in range(0, len(A)-1):
        minIndex = i
        for j in range(1+i, len(A)):
            if A[j] < A[minIndex]:
                minIndex = j
        if minIndex != i:
            A[i], A[minIndex] = A[minIndex], A[i]
            yield True

    return A

def insertion_sort(arr):
    for i in range(1, len(arr)):
        current = arr[i]
        while True:
            sort = i > 0 and arr[i-1] > current
            if not sort:
                break
            arr[i] = arr[i-1]
            i = i - 1
            arr[i] = current
            yield True
    return arr

def Graph(arr):
    bars = []
    for i in range(100):
        bar = Bars(arr, arr[i]*MULTIPLIER, WIDTH*i/len(arr))
        bars.append(bar)
    return bars


def main():
    run = True

    sorting_algo = insertion_sort
    algo_name = "Insertion Sort"
    arr = randomise()
    sorting = False
    FPS = 60

    while run:
        if sorting:
            try:
                next(sorting_algo(arr))
            except StopIteration:
                sorting = False
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
                return
            if event.type != pygame.KEYDOWN:
                continue
            if event.key == pygame.K_BACKSPACE and sorting:
                sorting = False
            if event.key == pygame.K_r and not sorting:
                arr = randomise()
            if event.key == pygame.K_b and not sorting:
                sorting_algo = bubble_sort
                algo_name = "Bubble Sort"
            elif event.key == pygame.K_i and not sorting:
                sorting_algo = insertion_sort
                algo_name = "Insertion Sort"
            elif event.key == pygame.K_s and not sorting:
                sorting_algo = selection_sort
                algo_name = "Selection Sort"
            if event.key == pygame.K_SPACE and not sorting:
                sorting_algo(arr)
                sorting = True
            if event.key == pygame.K_UP and not sorting:
                FPS = 120
            elif event.key == pygame.K_EQUALS and not sorting:
                FPS = 60
            elif event.key == pygame.K_DOWN and not sorting:
                FPS = 10
        screen.fill(BLACK)
        for bar in Graph(arr):
            bar.draw()
        text(FPS, algo_name)
        clock.tick(FPS)
        pygame.display.update()
    pygame.quit()


if __name__ == "__main__":
    main()

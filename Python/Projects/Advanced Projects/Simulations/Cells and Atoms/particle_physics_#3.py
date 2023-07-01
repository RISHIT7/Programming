from math import sqrt
import random
import sys
import pygame
from pygame.locals import *
pygame.init()

#display 
wid = 800
hig = 600
display = pygame.display.set_mode((wid,hig))
pygame.display.set_caption("Gravity...?")

#clock
fps = 60
clock = pygame.time.Clock()

#colors
white = (225,225,225)
black = (0,0,0)
red = (255,30,30)


class particle(pygame.sprite.Sprite):
    def __init__(self,mass,color,radius):
        super().__init__()
        self.xpos = random.randint(30,wid-30)
        self.ypos = random.randint(30,hig-30)
        self.xvel = 0
        self.yvel = 0
        self.mass = mass
        self.color = color
        self.radius = radius
    def update(self):
        G = 0.01 #universal constant
        force = 0
        #this part is to stop the particles from leaving the screen x axis
        if self.xpos < 30 or self.xpos > wid-30:
            #self.xpos = wid - self.xpos
            self.xvel = -self.xvel/2
            if self.xpos < 30:
                self.xpos = 31
            elif self.xpos > wid - 30:
                self.xpos = wid - 31
        #this part is to stop the particles from leaving the screen y axis    
        elif self.ypos < 30 or self.ypos > hig-30:
            #self.ypos = hig - self.ypos
            self.yvel = -self.yvel/2
            if self.ypos < 30:
                self.ypos = 31
            elif self.ypos > hig - 30:
                self.ypos = hig - 31
        

        #speed limit for particle to prevent excess chaos
        elif sqrt(self.xvel**2 + self.xvel**2)>20:
            self.xvel = self.xvel/2
            self.yvel = self.yvel/2

        #this part is responsible for actual update 
        else:
            for i in particles_list:#made a particle list below till then follow through
                xdist = i.xpos - self.xpos
                ydist = i.ypos - self.ypos
                dist = sqrt(xdist**2 + ydist**2)

                #if statement to prevent running into zero division error
                if dist>2:
                    force = (G*i.mass*self.mass)/dist**2

                    #i know i did something wrong below but i dont want to touch it
                    if i.color == self.color and self.color == red:
                        if dist < 20:
                            force = - force

                    #used this instead of sine and cos
                    xforce = (xdist/(abs(xdist)+abs(ydist)))*force
                    yforce = (ydist/(abs(xdist)+abs(ydist)))*force


                    #made particles repel each other at specific diatances
                    if i.color == self.color and self.color == red:
                        if dist < 200:
                            xforce = - xforce*2
                            yforce = - yforce*2
                    if i.color != self.color and self.color == white:
                        if dist < 100:
                            xforce = - xforce*2
                            yforce = - yforce*2
                    if i.color == self.color and self.color == white:
                        if dist < 50:
                            xforce = - xforce*2
                            yforce = - yforce*2
                    
                    #simple physics
                    xacc = xforce/self.mass
                    yacc = yforce/self.mass 
                    self.xvel = self.xvel + xacc #time == 1 unit as we are calculating vel for every next frame
                    self.yvel = self.yvel + yacc
        #code out of conditional statements
        self.xpos = self.xpos + self.xvel #time == 1 unit as we are calculating vel for every next frame
        self.ypos = self.ypos + self.yvel
        


    def draw(self,surface):
        #fuction to actually display the particles
        pygame.draw.circle(surface,self.color,(self.xpos,self.ypos),self.radius)


#making particle objects
particles_list = []
for i in range(200):
    particles_list.append(particle(100,white,5))
for i in range(4):
    particles_list.append(particle(500000,red,5))


#gameloop
while True:
    #start with clean slate
    display.fill(black)
    #update spirite positions
    for i in particles_list:
        i.update()
        i.draw(display)

    for i in pygame.event.get():
        if i.type == QUIT:
            pygame.quit()
            sys.exit()
    #updating changes on screen
    pygame.display.update()
    clock.tick(fps)
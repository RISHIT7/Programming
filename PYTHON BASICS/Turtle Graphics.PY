# draw a ninja 
import turtle 
ninja = turtle.Turtle()
ninja.speed(10)

for i in range(180):
    ninja.forward(12.5)
    ninja.right(9)
    ninja.forward(80)
    ninja.left(69)
    ninja.forward(500)
    ninja.right(21)

    ninja.penup()
    ninja.setposition(0, 0)
    ninja.pendown()

    ninja.right(2)
turtle.done()
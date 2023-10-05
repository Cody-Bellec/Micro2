# simple snake game in Python 3 for beginners
# by @TokyoEdTech
# modified by Yan Luo
# further modified by Joe Taylor, Cody Bellec, and Elizabeth Brown
#
# the following packages are required to run:
#   pyserial
#   tkinter

import turtle
import time
import random
import serial

# note the serial port dev file name
# need to change based on the particular host machine
serialDevFile = '/dev/ttyUSB0'
ser=serial.Serial(serialDevFile, 9600, timeout=0)

# score and delay setup
delay = 0.1
score = 0
high_score = 0
ppa = 10

# screen setup
wn = turtle.Screen()
wn.title("Snake Game by @TokyoEdTech (mod by YL)")
wn.bgcolor("green")
wn.setup(width=600, height=600)
wn.tracer(0) # turns off screen updates

# snake head setup
head = turtle.Turtle()
head.speed(0)
head.shape("square")
head.color("black")
head.penup()
head.goto(0,0)
head.direction = "stop"

# snake food setup
food = turtle.Turtle()
food.speed(0)
food.shape("circle")
food.color("red")
food.penup()
food.goto(0,100)

segments = []

# pen setup
pen = turtle.Turtle()
pen.speed(0)
pen.shape("square")
pen.color("white")
pen.penup()
pen.hideturtle()
pen.goto(0, 260)
pen.write("Score: 0  High Score: 0  P/A: 10", align="center", font=("Courier", 20, "normal"))

# function definitions
def go_up():
    if head.direction != "down":
        head.direction = "up"

def go_down():
    if head.direction != "up":
        head.direction = "down"

def go_left():
    if head.direction != "right":
        head.direction = "left"

def go_right():
    if head.direction != "left":
        head.direction = "right"

def bonus_apple():
    global ppa
    ppa = 20
    food.color("gold")
    pen.clear()
    pen.write("Score: {}  High Score: {}  P/A: {}".format(score, high_score, ppa), align="center", font=("Courier", 20, "normal")) 

def reset_apple():
    global ppa
    ppa = 10
    food.color("red")

def move():
    if head.direction == "up":
        y = head.ycor()
        head.sety(y + 20)

    if head.direction == "down":
        y = head.ycor()
        head.sety(y - 20)

    if head.direction == "left":
        x = head.xcor()
        head.setx(x - 20)

    if head.direction == "right":
        x = head.xcor()
        head.setx(x + 20)

# keybinds
wn.listen()
wn.onkey(go_up, "w")
wn.onkey(go_down, "s")
wn.onkey(go_left, "a")
wn.onkey(go_right, "d")
wn.onkey(bonus_apple, "b")

# main game loop 
while True:
    wn.update()

    # this section handles input from the Arduino
    line = ser.read()
    if line == b'W':
        go_up()
    elif line == b'A':
        go_left()
    elif line == b'S':
        go_down()
    elif line == b'D':
        go_right()
    elif line == b'B':
        bonus_apple()

    # check for collision with border
    if head.xcor()>290 or head.xcor()<-290 or head.ycor()>290 or head.ycor()<-290:
        time.sleep(1)
        head.goto(0,0)
        head.direction = "stop"

        # hide segments offscreen
        for segment in segments:
            segment.goto(1000, 1000)
        
        # clear segments list then reset score, delay, and apple
        segments.clear()
        score = 0
        delay = 0.1
        reset_apple()
 
        # update scoreboard
        pen.clear()
        pen.write("Score: {}  High Score: {}  P/A: {}".format(score, high_score, ppa), align="center", font=("Courier", 20, "normal")) 


    # check for collision with the food
    if head.distance(food) < 20:

        # increase score and check for new high score
        score += ppa 
        if score > high_score:
            high_score = score

        # move the food to a random spot
        x = random.randint(-290, 290)
        y = random.randint(-290, 290)
        food.goto(x,y)

        # add a segment and shorten delay
        new_segment = turtle.Turtle()
        new_segment.speed(0)
        new_segment.shape("square")
        new_segment.color("grey")
        new_segment.penup()
        segments.append(new_segment)
        delay -= 0.001
        
        # beep to indicate food has been eaten and reset bonus apple
        ser.write(b'E')
        reset_apple()
       
        # update scoreboard 
        pen.clear()
        pen.write("Score: {}  High Score: {}  P/A: {}".format(score, high_score, ppa), align="center", font=("Courier", 20, "normal")) 

    # move end segments first in reverse order
    for index in range(len(segments)-1, 0, -1):
        x = segments[index-1].xcor()
        y = segments[index-1].ycor()
        segments[index].goto(x, y)

    # move segment 0 to where the head is
    if len(segments) > 0:
        x = head.xcor()
        y = head.ycor()
        segments[0].goto(x,y)

    move()    

    # check for collision with body
    for segment in segments:
        if segment.distance(head) < 20:
            time.sleep(1)
            head.goto(0,0)
            head.direction = "stop"
        
            # hide the segments offscreen
            for segment in segments:
                segment.goto(1000, 1000)
        
            # clear segments list then reset score, delay, and apple
            segments.clear()
            score = 0
            delay = 0.1
            reset_apple()
        
            # update scoreboard
            pen.clear()
            pen.write("Score: {}  High Score: {}  P/A: {}".format(score, high_score, ppa), align="center", font=("Courier", 20, "normal")) 

    time.sleep(delay)

wn.mainloop()

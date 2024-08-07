#I implemented the intersting background and explosion.
# -*- coding: utf-8 -*-
import turtle, random, math

class Game:
    '''
    Purpose:  sets the player, obstacles, and game setting
    Instance variables:  
                    player:the player's spacecraft
                    obstacles: a list of instances of the class "Alien_obstacle"
    Methods: init: Sets up the environment
             explosion: creates an explosion animation 
             gameloop: controls player movement and obstacles
    '''
    def __init__(self):
        screen=turtle.Screen()
        screen.bgcolor("light blue")
        turtle.done
        
        #Bottom left corner of screen is (0, 0)
        #Top right corner is (500, 500)
        turtle.setworldcoordinates(0, 0, 500, 500)
        cv = turtle.getcanvas()
        cv.adjustScrolls()

        #Ensure turtle is running as fast as possible
        turtle.delay(0)

        self.obstacles = []
        i = 0
        while i < 8:
            obstacle = Alien_obstacle()
            self.obstacles.append(obstacle)
            i += 1

        #These two lines must always be at the BOTTOM of __init__
        self.player = SpaceCraft(random.uniform(100, 400), random.uniform(250, 450), random.uniform(-4, 4), random.uniform(-2, 0))
        turtle.onkeypress(self.player.thrust, 'Up')
        turtle.onkeypress(self.player.left_turn, 'Left')
        turtle.onkeypress(self.player.right_turn, 'Right')
        self.gameloop()

        turtle.listen()
        turtle.mainloop()


    def gameloop(self):
        i = 0
        while i < len(self.obstacles):
            obstacle = self.obstacles[i]
            obstacle.move()
            if self.player.distance(obstacle) > 500:
                obstacle.goto(random.uniform(150, 400), random.uniform(80, 500))
                obstacle.radius = random.uniform(100, 250)
                obstacle.angle = random.uniform(0, 360)
            else:
                i += 1

        self.player.move()
        if self.player.ycor() < 20:
            if -3 <= self.player.velocity_x <= 3 and -3 <= self.player.velocity_y <= 3:
                print("Successful landing!")
            else:
                self.explosion(self.player.xcor(), self.player.ycor())
                print("You crashed!")
            return
        turtle.ontimer(self.gameloop, 30)

    def explosion(self, x, y):
            explosion = turtle.Turtle()
            explosion.speed(0)
            explosion.penup()
            explosion.shape('circle')
            explosion.color('orange')
            explosion.goto(x,y)
            explosion.showturtle()

   
class SpaceCraft(turtle.Turtle):
    '''
    Purpose: represents the spaceship 
    Instance variables: velocity_x: represent the craft’s velocity in the x directions
                        velocity_y: represent the craft’s velocity in the y directions
                         fuel: how much fuel is left in the spacecraft
    Methods: init: defines the features of the spacecraft
             move: moves the SpaceCraft to a new position each step, based on its current velocity.
             thrust:  the remaining fuel
             left_turn: turns left 15 degrees whenever the left arrow key is pressed 
             right_turn: turns right 15 degrees whenever the right arrow key is pressed.
    '''

    def __init__(self, start_x, start_y, start_vx, start_vy):
        super().__init__()
        self.velocity_x = start_vx
        self.velocity_y = start_vy
        self.fuel = 40
        self.left(90)  
        self.penup()
        self.speed(0)
        self.goto(start_x, start_y)
        self.turtlesize(2) 
        
    def move(self):
        self.velocity_y -= 0.0486
        self.goto( self.xcor() + self.velocity_x,  self.ycor() + self.velocity_y)

    def thrust(self):
        if self.fuel > 0:
            self.fuel -= 1
            angle_radians = math.radians(self.heading())
            self.velocity_x += math.cos(angle_radians)
            self.velocity_y += math.sin(angle_radians)
            print("Fuel remaining:", self.fuel)
        else:
            print("Out of fuel.")
    def left_turn(self):
        if self.fuel > 0:
            self.fuel -= 1
            self.left(15)
            print("Fuel remaining:", self.fuel)
        else:
            print("Out of fuel")

    def right_turn(self):
        if self.fuel > 0:
            self.fuel -= 1
            self.right(15)
            print("Fuel remaining:", self.fuel)
        else:
            print("Out of fuel")

class Alien_obstacle(turtle.Turtle):
    '''
    Purpose: represents the alien obstacles
    Instance variables: shape: the shape of the obstacle
                        color: The color of the obstacle 
                        speed: The speed of the turtle
                        radius: how far the obstacle is from its center and where it is right now.
                        angle: The current angle of the obstacle.
    Methods: __init__(self): 
                move(self): 
    '''

    def __init__(self):
        super().__init__()
        self.shape("circle")
        self.color("blue")
        self.penup()
        self.speed(0)
        self.goto(random.uniform(150, 420), random.uniform(80, 500))
        self.radius = random.uniform(100, 250)
        self.angle = random.uniform(0, 360)

    def move(self):
        self.angle += random.uniform(5, 15)
        self.goto(self.xcor() + self.radius * math.cos(math.radians(self.angle)), self.ycor() + self.radius * math.sin(math.radians(self.angle)))


if __name__ == '__main__':
    Game()


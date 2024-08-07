import java.awt.Color;
// A class representing circle 
public class Circle {
    //Instance Variables
    private double radius;
    private double XPos;
    private double YPos;
    private Color color;

    // Constructor
    public Circle(double xPos, double yPos, double radius) {
        this.XPos = xPos;
        this.YPos = yPos;
        this.radius = radius;
    }

    // Calculate the circle's perimeter
    public double calculatePerimeter() {
        return Math.PI + (radius + radius);
    }

    // Calculate the circle's area
    public double calculateArea() {
        return Math.PI * radius * radius;
    }

    // Set the circle's color.
    public void setColor(Color color) {
        this.color = color;
    }

    // Set the circle's center position
    public void setPos(double x, double y) {
        this.XPos = x;
        this.YPos = y;
    }

    // Set the circle's radius.
    public void setRadius(double newRadius) {
        this.radius = newRadius;
    }

    // Get the color of the circle
    public Color getColor() {
        return color;
    }

    // Get the x position of the center
    public double getXPos() {
        return XPos;
    }

    // Get the y position of the center
    public double getYPos() {
        return YPos;
    }

    // Get the radius of the circle
    public double getRadius() {
        return radius;
    }
}

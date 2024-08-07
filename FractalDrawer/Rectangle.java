import java.awt.Color;
//A class representing Rectangle
public class Rectangle {
    //Instance Variables
    private double XPos;      
    private double YPos;      
    private double width;     
    private double height;    
    private Color color;

    // Constructor
    public Rectangle(double xPos, double yPos, double width, double height) {
        this.XPos = xPos;
        this.YPos = yPos;
        this.width = width;
        this.height = height;

    }

    //  Calculate the rectangle's perimeter
    public double calculatePerimeter() {
        return 2 * (width + height);
    }

    // Calculate rectangle's area
    public double calculateArea() {
        return width * height;
    }

    // Set the color of the rectangle
    public void setColor(Color color) {
        this.color = color;
    }

    // Set the x position 
    public void setPos(double x, double y) {
        this.XPos = x;
        this.YPos = y;
    }

    // Set the height of the rectangle
    public void setHeight(double height) {
        this.height = height;
    }

    // Set the width of the rectangle
    public void setWidth(double width) {
        this.width = width;
    }

    // Get the color of the rectangle
    public Color getColor() {
        return color;
    }

    // Get the x position
    public double getXPos() {
        return XPos;
    }

    // Get the y position
    public double getYPos() {
        return YPos;
    }

    // Get the height of the rectangle
    public double getHeight() {
        return height;
    }

    // Get the width of the rectangle
    public double getWidth() {
        return width;
    }
}

import java.awt.Color;

public class Triangle {
    //Instance Variables
    private double XPos;      // x position 
    private double YPos;      // y position 
    private double width;     // width of the triangle
    private double height;    // height of the triangle
    private Color color;

    // Constructor
    public Triangle(double xPos, double yPos, double width, double height) {
        this.XPos = xPos;
        this.YPos = yPos;
        this.width = width;
        this.height = height;
    }

    // Calculate the triangle's perimeter
    public double calculatePerimeter() {
        double hypotenuse = Math.sqrt(Math.pow(width / 2, 2) + Math.pow(height, 2));
        return width + 2 * hypotenuse;
    }

    // Calculate the triangle's area
    public double calculateArea() {
        return 1/2*(width * height) ;
    }

    // Set the color of the triangle
    public void setColor(Color color) {
        this.color = color;
    }

    // Set the x position 
    public void setPos(double x, double y) {
        this.XPos = x;
        this.YPos = y;
    }

    // Set the height of the triangle
    public void setHeight(double height) {
        this.height = height;
    }

    // Set the width of the triangle
    public void setWidth(double width) {
        this.width = width;
    }

    // Get the color of the triangle
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

    // Get the height of the triangle
    public double getHeight() {
        return height;
    }

    // Get the width of the triangle
    public double getWidth() {
        return width;
    }
}



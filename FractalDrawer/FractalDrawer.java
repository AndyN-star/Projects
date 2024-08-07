// FractalDrawer class draws a fractal of a shape indicated by user input
import java.awt.Color;
import java.util.Scanner;
import java.util.Random;
public class FractalDrawer {
    private double totalArea=0;  // member variable for tracking the total area

    public FractalDrawer() {}  // contructor


    //TODO:
    // drawFractal creates a new Canvas object
    // and determines which shapes to draw a fractal by calling appropriate helper function
    // drawFractal returns the area of the fractal
    public double drawFractal(String type) {
        //Canvas Size
        Canvas canvas = new Canvas(1000, 1000);
        // Checks if the value of the type is equal to the string
        //Calls drawTriangleFractal and determines the location, color, total area, 
        //and how many levels of the shape is drawn
        //Black is the default color
        if (type.equals("triangle")) {
            drawTriangleFractal(200,200 ,375 , 525, Color.black, canvas, 7);
            return totalArea;
        }
        else if(type.equals("circle")){
            drawCircleFractal(50,500 , 500, Color.black, canvas, 7);
            return totalArea;
        }
        else if(type.equals("rectangle")){
            drawRectangleFractal(100,200, 400, 400, Color.black, canvas, 7);
            return totalArea;
        }
        else {
            System.out.println("Invalid shape type");
            return 0;
        }
}
    
    



    //TODO:
    // drawTriangleFractal draws a triangle fractal using recursive techniques
    public void drawTriangleFractal(double width, double height, double x, double y, Color c, Canvas can, int level){
        if (level == 0){ //Base Case
            return;
        }
        //Draws the pattern and calculate the area
        Triangle triangle = new Triangle(x, y, width, height);
        can.drawShape(triangle);
        //Creates random color for the fractal pattern
        Random rand = new Random();
        float r = rand.nextFloat();
        float g = rand.nextFloat();
        float b = rand.nextFloat();
        triangle.setColor(new Color(r, g, b));
        totalArea += triangle.calculateArea();
        //A recursive method that changes the position of the fractal
        drawTriangleFractal(width/2, height/2, x + width/4 , y-height, c, can, level-1);
        drawTriangleFractal(width/2, height/2, x - width/2, y, c, can, level-1);
        drawTriangleFractal(width/2, height/2, x + width, y, c, can, level-1);
        
    }

    // TODO:
    // drawCircleFractal draws a circle fractal using recursive techniques
    public void drawCircleFractal(double radius, double x, double y, Color c, Canvas can, int level) {
        if (level == 0) { //Base Case
            return;

        }
        //Draws the pattern and calculate the area
        Circle circle = new Circle(x, y, radius); 
        can.drawShape(circle); 
        //Creates random color for the fractal pattern
        Random rand = new Random();
        float r = rand.nextFloat();
        float g = rand.nextFloat();
        float b = rand.nextFloat();
        circle.setColor(new Color(r, g, b));
        totalArea += circle.calculateArea(); 
        //A recursive method that changes the position of the fractal
        drawCircleFractal(radius/2, x - (2*radius), y + (2*radius), c, can, level-1);
        drawCircleFractal(radius/2, x - (2*radius), y - (2*radius), c, can, level-1);
        drawCircleFractal(radius/2, x + (2*radius), y + (2*radius), c, can, level-1);
        drawCircleFractal(radius/2, x + (2*radius), y - (2*radius), c, can, level-1);
    }

    //TODO:
    // drawRectangleFractal draws a rectangle fractal using recursive techniques
    public void drawRectangleFractal(double width, double height, double x, double y, Color c, Canvas can, int level) {
        if (level == 0){  //Base case
            return;
        }
        //Draws the pattern and calculate the area
        Rectangle newRec = new Rectangle(x, y, width, height); 
        can.drawShape(newRec); 
        //Creates random color for the fractal pattern
        Random rand = new Random();
        float r = rand.nextFloat();
        float g = rand.nextFloat();
        float b = rand.nextFloat();
        newRec.setColor(new Color(r, g, b));
        totalArea += newRec.calculateArea();
         //A recursive method that changes the position of the fractal
       drawRectangleFractal(width/2, height/2, x - width/3, y+height+2, c, can, level-1);
       drawRectangleFractal(width/2, height/2, x - width/3, y-height/3, c, can, level-1);
       drawRectangleFractal(width/2, height/2, x + width+2, y+height+2, c, can, level-1);
       drawRectangleFractal(width/2, height/2, x + width+2, y-height/3, c, can, level-1);
        
     

        
    }


    //TODO:
    // main should ask user for shape input, and then draw the corresponding fractal.
    // should print area of fractal
    public static void main(String[] args){
        //prompt the user a question and ask for input
        //print the area to the screen
        System.out.println("triangle, rectangle, or circle fractal?"); 
        Scanner scanner = new Scanner(System.in);
        String message = scanner.nextLine(); 
        FractalDrawer frac = new FractalDrawer(); 
        System.out.println("The total area of all shapes in this fractal is " + frac.drawFractal(message));
    }

}

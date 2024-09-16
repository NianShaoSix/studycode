import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

import java.util.Random;
import java.util.Scanner;

public class CircleDrawer extends Application {
    private CustomCircle[] circles;
    private int circleCount;

    @Override
    public void start(Stage primaryStage) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of circles: ");
        circleCount = scanner.nextInt();
        scanner.close();

        circles = new CustomCircle[circleCount];

        Random random = new Random();
        for (int i = 0; i < circleCount; i++) {
            double x, y, radius;
            do {
                x = random.nextDouble() * 400;
                y = random.nextDouble() * 400;
                radius = 10 + random.nextDouble() * 10;
            } while (!isValidLocation(x, y, radius));

            Color color = new Color(random.nextDouble(), random.nextDouble(), random.nextDouble(), 1);
            circles[i] = new CustomCircle(x, y, radius, color);
        }

        Pane pane = new Pane();
        for (CustomCircle circle : circles) {
            Circle fxCircle = new Circle(circle.getX(), circle.getY(), circle.getRadius());
            fxCircle.setFill(circle.getColor());
            pane.getChildren().add(fxCircle);
        }

        Scene scene = new Scene(pane, 800, 800);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private boolean isValidLocation(double x, double y, double radius) {
        for (CustomCircle circle : circles) {
            if (circle != null && circle.intersects(new CustomCircle(x, y, radius, Color.TRANSPARENT))) {
                return false;
            }
        }
        return true;
    }



    public static void main(String[] args) {
        launch(args);
    }
}

class CustomCircle {
    private double x,y,radius;
    private Color color;

    public CustomCircle(double x,double y,double radius,Color color){
        this.x=x;
        this.y=y;
        this.radius=radius;
        this.color=color;
    }

    //判断两个圆是否相交
    public boolean intersects(CustomCircle other){
        double distance = Math.sqrt(Math.pow(this.x-other.getX(),2) +Math.pow(this.y - other.getY(), 2));
        return distance < this.radius + other.getRadius();
    }

    double getRadius() { return radius;
    }

    public double getX() { return x;
    }

    public double getY() { return y;
    }


    public Paint getColor() { return color;
    }
}
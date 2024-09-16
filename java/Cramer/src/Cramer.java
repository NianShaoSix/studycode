import java.util.Scanner;
public class Cramer{
    public static void main(String[] args) {
        System.out.printf("请输入方程组的系数和值：a,b,e,c,d,f\nax+by=e.cx+by=f\n");
        Scanner input = new Scanner(System.in);
        double a = input.nextDouble();
        double b = input.nextDouble();
        double e = input.nextDouble();
        double c = input.nextDouble();
        double d = input.nextDouble();
        double f = input.nextDouble();
        double x = (e * d - b * f) / (a * d - b * c);
        double y = (a * f - e * c) / (a * d - b * c);
        System.out.println("x = " + x + "  " + "y = " + y);


    }
}
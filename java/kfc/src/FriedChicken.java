import java.util.Scanner;

public class FriedChicken {
    String name;
    double price;

    FriedChicken(){
        double price=0;
    }
    FriedChicken(String newName,double newPrice) {
        name=newName;
        price=newPrice;

    }
    public static int getNumber(){
        java.util.Scanner input=new Scanner(System.in);
        int number=input.nextInt();
        return number;
}
}

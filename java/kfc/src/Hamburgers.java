import java.util.Scanner;

public class Hamburgers {
    String name;
    double price;
    Hamburgers(){
        price=0;
    }
    Hamburgers( String newName,double newPrice) {
        name=newName;
        price=newPrice;
    }
    public static int getNumber(){
        java.util.Scanner input=new Scanner(System.in);
        int number=input.nextInt();
        return number;
    }

}

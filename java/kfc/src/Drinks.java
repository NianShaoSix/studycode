import java.util.Scanner;

public class Drinks {
    String name;String size;
    double price;
    Drinks(String newName,double newPrice,String newSize){
        name=newName;
        price=newPrice;
        size=newSize;

    }
    public static int getNumber(){
        java.util.Scanner input=new Scanner(System.in);
        int number=input.nextInt();
        return number;
}
}

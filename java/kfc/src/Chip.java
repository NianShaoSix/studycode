import java.util.Scanner;

public class Chip {
    String name;
    double price;
    String size;
    Chip(String newName,double newPrice,String newSize){
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

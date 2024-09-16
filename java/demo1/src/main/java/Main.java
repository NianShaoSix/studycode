import java.util.Scanner;

class Main{

    public static void main(String []args){

        Scanner scanner = new Scanner(System.in);

        String x=scanner.nextLine();

        if(x.length()==6){

            String years=x.substring(0,4);

            String month=x.substring(4);

            System.out.println(years+"-"+month);}

        else{

            String years=x.substring(0,2);

            String month=x.substring(2);

            int year = Integer.parseInt(years.substring(0));

            if(year>=22){

                System.out.print("19"+years+"-"+month);}

            else{

                System.out.print("20"+years+"-"+month);

            }

        }

    }}
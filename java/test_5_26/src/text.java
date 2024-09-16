import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class text {
    public static void main(String[] args) {
        List<Student> studentArrayList = new ArrayList<>();
        Student student1=new Student();
        studentArrayList.add(student1);
        Scanner input=new Scanner(System.in);
        student1.setName(input.next());
        try {
        student1.setSex(input.next());
        }

        catch (SexException x){
         System.out.println(x.getMessage());
        }
        try{
            student1.setAge(input.next());
        }
        catch (AgeException e) {
            System.out.println(e.getMessage());
        }

        }
    }
















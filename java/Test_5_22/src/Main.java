//import java.util.ArrayList;
//
//public class Main {
//    public static void main(String[] args){
//       ArrayList<Character> list = new ArrayList<>();
//       list = toCharacterArray("abc");
//      for(int i =0; i<list.size();i++) System.out.print(list.get(i) + " ");
//    }
//    public static ArrayList<Character> toCharacterArray(String s){
//        ArrayList<Character> list = new ArrayList<>();
//        for(int i=0; i<s.length();i++){
//            list.add(s.charAt(i));
//        }
//        return list;
//    }
//}

//import java.util.ArrayList;
//import java.util.Date;
//import javafx.scene.shape.Circle;
//
//
//public class Main {
//    public static void main(String[] args){
//        ArrayList<Object> list = new ArrayList<>();
//
//        Loan loan = new Loan(10000);
//        Date date = new Date(1);
//        String string = new String("welcome to java!");
//        Circle circle = new Circle(1);
//
//        list.add(loan);
//        list.add(date);
//        list.add(string);
//        list.add(circle);
//
//        for(int i=0;i<list.size();i++){
//          System.out.println(list.get(i).toString());
//        }
//    }
//}
//class Loan{
//    private int money;
//    String time;
//    public Loan(int money){
//        this.money=money;
//        Date date = new Date();
//        time = date.toString();
//    }
//
//    public String toString(){
//        return time +"  "+ money;
//    }
//
//}
//
//import java.util.ArrayList;
//
//public class Main {
//    public static void main(String[] args){
//
//
//    }
//}
//
//class MyStack extends ArrayList{
//    public MyStack(){
//
//    }
//}
//
import java.util.ArrayList;
import java.util.Scanner;

class Mystack extends ArrayList {
    private ArrayList a=new ArrayList();
    public boolean isEmpty(){
        return a.isEmpty();
    }
    public int getSize(){
        return a.size();
    }
    public Object peek(){
        return a.get(a.size()-1);
    }
    public  void push(Object o){
        a.add(o);
    }
    public Object pop(){
        if(!a.isEmpty()){
            Object o=a.get(getSize()-1);
            a.remove(getSize()-1);
            return o;
        }
        else{
            return "栈为空，弹出失败";
        }
    }
}
 public class Main{
    public static void main(String[] args) {
        System.out.println("请输入五个字符串");
        java.util.Scanner input = new Scanner(System.in);
        for(int j=0;j<5;j++){
        String s = input.next();
        Mystack m=new Mystack();
        for(int i=0;i<s.length();i++){
            m.push(s.charAt(i));
        }
        while(!m.isEmpty()){
            System.out.print(m.pop());
        }
    }
   }
}



































public class Parent{
    String one,two;
    public Parent(String a,String b){
        one = a;
        two = b;
    }
    public void print(){System.out.println(one);}
}

 class Child extends Parent{
    public Child(String a,String b){


        super(a,b);
    }
    public void print(){
        System.out.println(one + " to "+two);
    }
    public static void main(String args[]){
        Parent p=new Parent("south","north");
        Parent t=new Child("east","west");
        p.print();
        t.print();
    }

}
//public class Test{
//    public static void main(String[] args){
//        String s;
//
//    }
//}
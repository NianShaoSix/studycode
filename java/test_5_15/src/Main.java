public class Main {
    public static void main(String[] args) {
        Person person=new Person("张三","江西","07966258479","12345678901@163.com");
        Student student=new Student("李四","浙江","07966635665","15179696073@163.com","大一");
        Employee employee=new Employee("王五","北京","13452352352","253532523@163.com","一楼",8000);
        Faculty faculty=new Faculty("赵六","成都","13455552352","25677532523@163.com","二楼",8000,13,"办公室主任");
        Staff staff=new Staff("付七","上海","13455552352","25677532523@163.com","二楼",8000,"办公室主任");


        System.out.println(person.toString());
        System.out.println(student.toString());
        System.out.println(employee.toString());
        System.out.println(faculty.toString());
        System.out.println(staff.toString());
    }
}
//人类
class Person{
    private String name;
    private String address;
    private String phoneNumber;
    String email;

    public Person(){

    }

    public Person(String name,String address, String phoneNumber, String email){
        this.name = name;
        this.phoneNumber=phoneNumber;
        this.address=address;
        this.email=email;
    }
    public String toString(){
        return "Person "+getName();
    }

    public String getName() {
        return name;
    }

    public void setName(String name){
        this.name=name;
    }

    public void setAddress(String address){
        this.address=address;
    }

    public void setPhoneNumber(String phoneNumber){
        this.phoneNumber=phoneNumber;
    }

    public void setEmail(String email){
        this.email=email;
    }


}
//学生类
class Student extends Person{
    private String banJi;

    public Student() {

    }
    public Student(String name,String address,String phoneNumber, String email, String banJi){
        super(name,address,phoneNumber,email);
        this.banJi=banJi;
    }

    public void setBanJi(String banJi){
        this.banJi=banJi;
    }

    public String toString(){
        return "Student "+ getName();
    }
}

class Employee extends Person{
    private String bangGongShi;
    private double gongZi;
    //受聘日期

    public Employee(){

    }

    public Employee(String name,String address,String phoneNumber, String email,String bangGongShi,double gongZi){
        super(name,address,phoneNumber,email);
        this.bangGongShi=bangGongShi;
        this.gongZi=gongZi;
    }

    public String toString(){
        return "Employee " + getName();
    }

}

class Faculty extends Employee{
    private double timeOfWork;
    private String rank;

    public Faculty(){

    }

    public Faculty(String name,String address,String phoneNumber, String email,String bangGongShi,double gongZi,double timeOfWork,String rank){
        super(name,address,phoneNumber,email,bangGongShi,gongZi);
        this.timeOfWork=timeOfWork;
        this.rank=rank;
    }
    public String toString(){
        return "Faculty "+ getName();
    }
}

class Staff extends Employee{
    private  String rank;
    public Staff(){

    }

    public Staff(String name,String address,String phoneNumber, String email,String bangGongShi,double gongZi,String rank){

        super(name,address,phoneNumber,email,bangGongShi,gongZi);
        this.rank=rank;
    }
    public String toString(){
        return "Staff " + getName();
    }
}

class MyDate{
    private int year,month,day;
    private long elapsedTime;
    public MyDate(){

    }
    public MyDate(long elapsedTime){

    }

    public MyDate(int year, int month, int day){
        this.year=year;
        this.month=month;
        this.day=day;
    }

    public int getYear(int year){
        return year;
    }

    public int getMonth(int month){
        return month;
    }

    public int getDay(int day){
            return day;
    }

    public void setDate(long elapsedTime){

    }
}
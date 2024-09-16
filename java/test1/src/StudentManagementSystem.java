import java.lang.annotation.Native;
import java.util.*;
import java.io.*;

public class StudentManagementSystem {

    List<Student> students;
    StudentManagementSystem(){
        students=new ArrayList<>();
    }
    //菜单方法
    public static void displayMenu(){
        System.out.println("*************************************");
        System.out.println("*********学生信息管理系统***************");
        System.out.println("********1.学生信息录入*****************");
        System.out.println("********2.学生信息浏览功能**************");
        System.out.println("********3.学生信息排序、查询功能*********");
        System.out.println("********4.信息统计********************");
        System.out.println("********5.学生信息的删除和修改**********");
        System.out.println("********6.退出系统********************");
        System.out.print("请选择：");
    }
    //录入学生信息
    public void addStudent(){
        Scanner input=new Scanner(System.in);
        System.out.println("请输入姓名：");
        String name=input.nextLine();
        System.out.println("请输入学号：");
        String id=input.nextLine();
        System.out.println("请输入年龄：");
        int age=input.nextInt();
        if(age<0||age>100){
            System.out.println("年龄输入不合法，请重新输入。");
            return;
        }
        input.nextLine();
        System.out.println("请输入性别：");
        String gender=input.nextLine();
        if(gender.equals("男")||gender.equals("女")){

        }
        else{
            System.out.println("性别输入不合法，请重新输入。");
            return;
        }
        System.out.println("请输入出生年月日(yyyy-MM-dd)：");
        String bornDate=input.nextLine();
        System.out.println("请输入政治面貌：");
        String politicalOutlook=input.nextLine();
        System.out.println("请输入籍贯：");
        String nativePlace=input.nextLine();
        System.out.println("请输入居住地址：");
        String residentialAddress=input.nextLine();
        System.out.println("请输入电话号码：");
        String phoneNumber=input.nextLine();
        System.out.println("请输入邮箱地址：");
        String email=input.nextLine();

        //创建新的学生对象并添加到列表中
        Student newStudent=new Student(id,name,age,gender,bornDate,politicalOutlook,nativePlace,residentialAddress,phoneNumber,email);
        students.add(newStudent);

        System.out.println("学生信息录入成功！");
    }
    //浏览学生信息
    public void viewStudents(){
        if(students.isEmpty()){
            System.out.println("没有学生信息记录");
        }else{
            for(Student student:students){
                System.out.println(student);
            }
        }
    }

    public void sortAndSearchStudents(){
        //排序和查询
        System.out.println("\n排序和查询功能");
        System.out.println("1.按学号查询");
        System.out.println("2.按姓名查询");
        System.out.println("3.按年龄查询");
        System.out.println("4.按性别查询");
        System.out.println("5.按出生年月日查询");
        System.out.println("6.按籍贯查询");
        System.out.print("请选择操作编号：");
        Scanner input=new Scanner(System.in);
        int choice=input.nextInt();
        input.nextLine();

        switch(choice){
            case 1:sortById();searchById();break;
            case 2:sortByName();searchByName();break;
            case 3:sortByAge();searchByAge();break;
            case 4:sortByGender();searchByGender();break;
            case 5:sortByBornDate();searchByBornDate();break;
            case 6:sortByNativePlace();searchByNativePlace();break;
            default:System.out.println("无效选择，请重新输入。");break;
        }
    }
    //按学号排序
    public void sortById(){
        Collections.sort(students,Comparator.comparing(Student::getId));
        viewStudents();
    }
    //按姓名排序
    public void sortByName(){
        Collections.sort(students,Comparator.comparing(Student::getName));
        viewStudents();
    }
    //按年龄排序
    public void sortByAge(){
        Collections.sort(students,Comparator.comparing(Student::getAge));
        viewStudents();
    }
    //按性别排序
    public void sortByGender(){
        Collections.sort(students,Comparator.comparing(Student::getGender));
        viewStudents();
    }
    //按出生年月排序
    public void sortByBornDate(){
        Collections.sort(students,Comparator.comparing(Student::getBornDate));
        viewStudents();
    }
    //按籍贯排序
    public void sortByNativePlace(){
        Collections.sort(students,Comparator.comparing(Student::getNativePlace));
        viewStudents();
    }
    //通过学号查询
    public void searchById(){
        System.out.println("请输入学号：");
        Scanner input=new Scanner(System.in);
        String id=input.nextLine();
        ArrayList<Student>results=new ArrayList<>();
        for(Student student:students){
            if (student.getId().equals(id)){
                results.add(student);
            }
        }
        if(!results.isEmpty()){
            for(Student student:results){
                System.out.println(student);
            }
        }
        else{
            System.out.println("没有相匹配的学生信息");
        }
    }
    //通过名字查询
    public void searchByName(){
        System.out.println("请输入姓名：");
        Scanner input=new Scanner(System.in);
        String name=input.nextLine();
        ArrayList<Student>results=new ArrayList<>();
        for(Student student:students){
            if(student.getName().equals(name)){
                results.add(student);
            }
        }
            if(!results.isEmpty()){
                for (Student student1:results)
                System.out.println(student1);
            }else{
                System.out.println("没有匹配的学生信息");
            }
        }
    //通过年龄查询
    public void searchByAge(){
        System.out.println("请输入年龄：");
        Scanner input=new Scanner(System.in);
        int age=input.nextInt();
        ArrayList<Student>results=new ArrayList<>();
        for(Student student:students){
            if(student.getAge()==age){
                results.add(student);
            }
        }
            if(!results.isEmpty()){
                for (Student student1:results)
                    System.out.println(student1);
            }else{
                System.out.println("没有匹配的学生信息");
            }

    }
    //通过性别查询
    public void searchByGender(){
        System.out.println("请输入性别：");
        Scanner input=new Scanner(System.in);
        String gender=input.nextLine();
        ArrayList<Student>results=new ArrayList<>();
        for(Student student:students){
            if(student.getGender().equals(gender)){
                results.add(student);
            }
        }
            if(!results.isEmpty()){
                for (Student student1:results)
                    System.out.println(student1);
            }else{
                System.out.println("没有匹配的学生信息");
            }
        }
    //通过出生年月日查询
    public void searchByBornDate(){
        System.out.println("请输入出生年月日：");
        Scanner input=new Scanner(System.in);
        String bornDate=input.nextLine();
        ArrayList<Student>results=new ArrayList<>();
        for(Student student:students){
            if(student.getBornDate().equals(bornDate)){
                results.add(student);
            }
        }
            if(!results.isEmpty()){
                for (Student student1:results)
                    System.out.println(student1);
            }else{
                System.out.println("没有匹配的学生信息");
            }
        }
    //通过籍贯查询
    public void searchByNativePlace(){
        System.out.println("请输入籍贯：");
        Scanner input=new Scanner(System.in);
        String nativePlace=input.nextLine();
        ArrayList<Student>results=new ArrayList<>();
        for(Student student:students){
            if(student.getNativePlace().equals(nativePlace)){
                results.add(student);
            }
        }
            if(!results.isEmpty()){
                for (Student student1:results)
                    System.out.println(student1);
            }else{
                System.out.println("没有匹配的学生信息");
            }
        }

    //保存学生信息
    public void saveStudentsToFile(String filePath){
        Student.writetoFile(students,filePath);
    }

    //加载学生信息
    public void loadStudentsFromFile(String filePath){
        students=Student.readFromFile(filePath);
    }

    //学生信息统计
    public void statistcs(){
        System.out.println("\n统计功能");
        System.out.println("1.统计学生总数");
        System.out.println("2.按性别统计学生");
        System.out.println("3.按出生年统计学生");
        System.out.println("4.按籍贯统计学生");
        System.out.println("5.按政治面貌统计学生");

        Scanner input=new Scanner(System.in);
        int choice=input.nextInt();
        input.nextLine();//消除新的行

        switch (choice){
            case 1:
                countTotalStudents();
                break;
            case 2:
                countStudentsByGender();
                break;
            case 3:
                countStudentByBornYear();
                break;
            case 4:countStudentByNativePalce();
                break;
            case 5:countStudentByPoliticalOutlook();
                break;
            default:System.out.println("输入错误");
        }
    }
    //统计学生总人数
    public void countTotalStudents(){
        System.out.println("学生总数："+students.size());
    }
    //根据性别统计学生数量方法
    public void countStudentsByGender(){
        Map<String,Integer>genderCounter=new HashMap<>();
        for(Student student:students){
            String gender=student.getGender();
            genderCounter.put(gender,genderCounter.getOrDefault(gender,0)+1);
        }
        for(Map.Entry<String,Integer>entry:genderCounter.entrySet()){
            System.out.println("性别"+entry.getKey()+":"+entry.getValue());
        }
    }
    //按出生年统计学生人数
    public void countStudentByBornYear(){
        Map<String,Integer>bornYearCounter=new HashMap<>();
        for(Student student:students){
            String bornDate=student.getBornDate();
            String bornYear=student.getYear();
            bornYearCounter.put(bornYear,bornYearCounter.getOrDefault(bornYear,0)+1);
        }
        for (Map.Entry<String,Integer>entry:bornYearCounter.entrySet()){
            System.out.println("出生年份"+entry.getKey()+":"+entry.getValue());
        }
    }
    //按照籍贯统计学生人数
    public void countStudentByNativePalce(){
        Map<String,Integer>nativePalceCounter=new HashMap<>();
        for (Student student:students){
            String nativePlace=student.getNativePlace();
            nativePalceCounter.put(nativePlace,nativePalceCounter.getOrDefault(nativePlace,0)+1);
        }
        for(Map.Entry<String,Integer>entry:nativePalceCounter.entrySet()){
            System.out.println("户籍"+entry.getKey()+":"+entry.getValue());
        }
    }
    //按照政治面貌统计学生人数并
    public void countStudentByPoliticalOutlook(){
        Map<String,Integer>politicalOutlookCounter=new HashMap<>();
        for(Student student:students){
            String politicalOutlook=student.getPoliticalOutlook();
            politicalOutlookCounter.put(politicalOutlook,politicalOutlookCounter.getOrDefault(politicalOutlook,0)+1);
        }
        System.out.println("----------------------统计报表-------------------------");
        for (Map.Entry<String,Integer>entry:politicalOutlookCounter.entrySet()){
            System.out.println("政治面貌："+entry.getKey()+":"+entry.getValue()+"   占总人数的百分比为："+(int)((entry.getValue()*1.0/students.size())*100)+"%");
        }
        System.out.println("----------------------统计报表-------------------------");
    }
    //学生信息删除和修改方法
    public void deleteAndModifyStudent(){
        System.out.println("1.删除学生信息");
        System.out.println("2.修改学生信息");
        Scanner input=new Scanner(System.in);
        int choice1=input.nextInt();
        input.nextLine();

        switch (choice1){
            case 1:
                System.out.println("\n请输入你需要删除学生的学号");
                String id=input.nextLine();

                //查找并删除学生信息
                for(Student student:students){
                   if(student.getId().equals(id)) students.remove(student);
                }
                break;
            case 2:
                System.out.println("\n请输入你需要修改的学生信息的名字");
                Scanner input2=new Scanner(System.in);
                String name =input2.nextLine();
                for(Student student:students) {
                    if (student.getName().equals(name)) {
                        System.out.println(student);
                        System.out.println("选择需要修改的学生信息");
                        System.out.println("1.姓名");
                        System.out.println("2.学号");
                        System.out.println("3.性别");
                        System.out.println("4.籍贯");
                        System.out.println("5.居住住址");
                        System.out.println("6.政治面貌");
                        System.out.println("7.手机号码");
                        System.out.println("8.邮箱地址");
                        System.out.println("9.年龄");
                        System.out.println("10.出生年月日");

                        int choice2 = input2.nextInt();
                        input2.nextLine();
                        switch (choice2) {
                            case 1:
                                System.out.print("修改姓名为：");
                                String newName = input2.nextLine();
                                student.setName(newName);
                                break;
                            case 2:
                                System.out.print("修改学号为：");
                                String newId = input2.nextLine();
                                student.setId(newId);
                                break;
                            case 3:
                                System.out.print("修改性别为：");
                                String newGender = input2.nextLine();
                                student.setGender(newGender);
                                break;
                            case 4:
                                System.out.print("修改籍贯为：");
                                String newNativePlace = input2.nextLine();
                                student.setNativePlace(newNativePlace);
                                break;
                            case 5:
                                System.out.print("修改居住地址为：");
                                String newResidentialAddress = input2.nextLine();
                                student.setResidentialAddress(newResidentialAddress);
                                break;
                            case 6:
                                System.out.print("修改政治面貌为：");
                                String newPoliticalOutlook = input2.nextLine();
                                student.setPoliticalOutlook(newPoliticalOutlook);
                                break;
                            case 7:
                                System.out.print("修改手机号码为：");
                                String newPhoneNumber = input2.nextLine();
                                student.setPhoneNumber(newPhoneNumber);
                                break;
                            case 8:
                                System.out.print("修改邮箱地址为：");
                                String newEmail = input2.nextLine();
                                student.setEmail(newEmail);
                                break;
                            case 9:
                                System.out.print("修改年龄为");
                                int newAge = input2.nextInt();
                                input2.nextLine();
                                student.setAge(newAge);
                            case 10:
                                System.out.print("修改出生年月为：");
                                String newBornDate = input2.nextLine();
                                student.setBornDate(newBornDate);
                                break;
                            default:
                                System.out.println("输入错误，请重新输入:");
                        }
                    }
                }

                break;
            default:System.out.println("输入错误，请重新输入。");
        }
        }
    }

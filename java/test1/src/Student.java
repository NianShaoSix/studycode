import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Student {
    String id;
    String name;
    int age;
    String gender;
    String bornDate;//yyyy-mm-dd
    String politicalOutlook;
    String nativePlace;
    String residentialAddress;
    String phoneNumber;
    String email;
    String year;
    public Student(){

    }

    public Student(String id,String name,int age,String gender,String bornDate,String politicalOutlook,String nativePlace,String residentialAddress,String phoneNumber,String email){
        this.id=id;
        this.age=age;
        this.name=name;
        this.gender=gender;
        this.bornDate=bornDate;
        this.politicalOutlook=politicalOutlook;
        this.nativePlace=nativePlace;
        this.residentialAddress=residentialAddress;
        this.phoneNumber=phoneNumber;
        this.email=email;
        String[] years=bornDate.split("-");
        year=years[0];
    }
    //getter
    String getId(){
        return id;
    }
    String getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    String getGender(){
        return gender;
    }
    String getBornDate(){
        return bornDate;
    }
    String getPoliticalOutlook(){
        return politicalOutlook;
    }
    String getNativePlace(){
        return nativePlace;
    }
    String getPhoneNumber(){
        return phoneNumber;
    }
    String getEmail(){
        return email;
    }
    String getYear(){
        String[] years=bornDate.split("-");
        return year=years[0];
    }

    //setter
    void setId(String id){
        this.id=id;
    }
    void setName(String name){
        this.name=name;
    }
    void setAge(int age){
        this.age=age;
    }
    void setGender(String gender){
        this.gender=gender;
    }
    void setBornDate(String bornDate){
        this.bornDate=bornDate;
    }
    void setPoliticalOutlook(String politicalOutlook){
        this.politicalOutlook=politicalOutlook;
    }
    void setNativePlace(String nativePlace){
        this.nativePlace=nativePlace;
    }
    void setPhoneNumber(String phoneNumber){
        this.phoneNumber=phoneNumber;
    }
    void setEmail(String email){
        this.email=email;
    }
    void setResidentialAddress(String residentialAddress){
        this.residentialAddress=residentialAddress;
    }
    void setYear(String bornDate){
        String[] years=bornDate.split("-");
        this.year=years[0];
    }
    //重写toString方法
    @Override
    public String toString(){
        return "姓名:"+name+",学号:"+id+",性别:"+gender+",年龄:"+age+",出生年月:"+bornDate+",政治面貌:"+politicalOutlook+
                ",籍贯:"+nativePlace+",居住地址:"+residentialAddress+",手机号码:"+phoneNumber+",邮箱地址:"+email;
    }

    //将学生信息写入到文件
    public static void writetoFile(List<Student>students,String filePath){
        try(BufferedWriter writer=new BufferedWriter(new FileWriter(filePath))){
            for(Student student:students){
                writer.write(student.toString());
                writer.newLine();
            }
            System.out.println("学生信息已保存到文件："+filePath);
        } catch (IOException e) {
            System.out.println("写入文件时发生错误"+e.getMessage());
        }
    }

    //从文件中读取学生的信息
    public static List<Student>readFromFile(String filePath){
        List<Student>students=new ArrayList<>();
        try (BufferedReader reader=new BufferedReader(new FileReader(filePath))){
            String line;
            while((line=reader.readLine())!=null){
                //假设每一行包含一个学生的信息
                //在这里解析每一行并创建Student对象
                String[] parts=line.split(",");
                String name=parts[0].substring(parts[0].indexOf(":")+1);
                String id=parts[1].substring(parts[1].indexOf(":")+1);
                String gender=parts[2].substring(parts[2].indexOf(":")+1);
                int age= Integer.parseInt(parts[3].substring(parts[3].indexOf(":")+1));
                String bornDate=parts[4].substring(parts[4].indexOf(":")+1);
                String politicalOutlook=parts[5].substring(parts[5].indexOf(":")+1);
                String nativePlace=parts[6].substring(parts[6].indexOf(":")+1);
                String residentialAddress=parts[7].substring(parts[7].indexOf(":")+1);
                String phoneNumber=parts[8].substring(parts[8].indexOf(":")+1);
                String email=parts[9].substring(parts[9].indexOf(":")+1);

                Student student=new Student(id,name,age,gender,bornDate,politicalOutlook,nativePlace,residentialAddress,phoneNumber,email);
                students.add(student);
            }System.out.println("学生信息已从文件："+filePath+"读取成功");
        }catch (IOException e){
            System.err.println("读取文件时发生错误："+e.getMessage());
        }
        return students;
    }
}

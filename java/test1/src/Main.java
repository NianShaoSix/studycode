import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
    StudentManagementSystem system=new StudentManagementSystem();
        List<Student>students=new ArrayList<>();
        String filePath="D:\\code\\studycode\\java\\test1\\学生信息库.txt";//使用绝对路径创建文本文件用于存储
        //启动时加载学生信息
        system.loadStudentsFromFile(filePath);
    while(true){
        //dispaly menu
        StudentManagementSystem.displayMenu();
        //choice
        Scanner input = new Scanner(System.in);
        int choice =input.nextInt();
        input.nextLine();
        switch (choice){

            case 1:
                //录入学生信息
                system.addStudent();
                system.saveStudentsToFile(filePath);
                break;


            case 2:
                //浏览学生信息
                system.viewStudents();
                break;

            case 3:
                //排序和查询学生信息
                system.sortAndSearchStudents();
                break;

            case 4:
                //信息统计
                system.statistcs();
                break;

            case 5:
                //学生信息的修改和删除
                system.viewStudents();
                system.deleteAndModifyStudent();
                system.saveStudentsToFile(filePath);
                break;

            case 6: System.exit(0);
            default:System.out.println("输入错误，请重新输入");
        }
      }
    }
}

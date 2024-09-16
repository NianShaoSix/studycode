import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;
public class Text {

    public static void main(String[] args) throws FileNotFoundException {

        System.out.println("1.登录 2.注册");
        Scanner input = new Scanner(System.in);
        int choice = input.nextInt();
        int count=0,count2=0;

        switch (choice){
            case 1:
                do{System.out.println("请输入用户名");

                Login login=new Login();
                try{
                    login.setName(login.getName(input.next()));
                    count++;


                } catch (LoginException e){
                    System.out.println(e.getMessage());
                    count2++;

                } catch (FileNotFoundException e) {
                    throw new RuntimeException(e);
                }

                    if(count==1){
                System.out.println("请输入密码");
                try {
                    login.getCode(input.next());
                    count++;
                } catch (LoginException  e){
                    System.out.println(e.getMessage());
                    count2++;
                } catch (FileNotFoundException e) {
                    throw new RuntimeException(e);
                }

                        if(count==2) System.out.println("欢迎" + login.name);
                }
                }while (count<2&&count2<3);
                if(count2>=3) System.out.println("输入错误三次退出");
                break;
            case 2:
                Login login = new Login();
                System.out.println("请输入你的用户名");


                System.out.println("请输入你的密码");

                System.out.println("注册成功");

                break;
        }




    }
}
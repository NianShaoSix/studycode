import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class Login {
    protected String fileName="D:\\code\\studycode\\java\\2024_5_29\\login.txt";
    String name;
    private String code;
    public Login(){

    }

    public void setName(String name){
        this.name=name;
    }

    public void  setCode(String code){
        this.code=code;
    }

    public String getName(String name) throws LoginException, FileNotFoundException {
        Scanner sc= new Scanner(new FileReader(fileName)); int count=0;
        while(sc.hasNext()){
            String s=sc.next();

        if (name.equals(s)) {
           count++;
        }
        }
        if(count==0)  throw new LoginException("用户名异常");
        else return name;

    }
    public String getCode(String code) throws LoginException, FileNotFoundException {
        Scanner sc = new Scanner(new FileReader(fileName)); int count=0;
        while (sc.hasNext()) {
            String s = sc.next();
            if (code.equals(s)) count++;
        }
            if(count==0)   throw new LoginException("密码错误");
            else return code;
        }

    }


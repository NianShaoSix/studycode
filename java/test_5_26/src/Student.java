public class Student {
    private String name,sex,age;

   public Student(){

   }
    public Student(String name ,String sex,String age){
        this.name=name ;
        this.sex=sex;
        this.age=age;
    }
    public void setName(String name){
        this.name=name;
    }

    public void setSex(String sex) throws SexException {
        if (sex.equals("男")||sex.equals("女")){
            this.sex=sex;
        }
        else throw new SexException("sex is exception");
    }

    public void setAge(String age) throws AgeException{
        if(Integer.parseInt(age)<15||Integer.parseInt(age)>50){
            throw new AgeException("age is exception");
        }
        else this.age=age;
    }
}

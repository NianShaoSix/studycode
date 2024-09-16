//import javafx.application.Application;
//import javafx.scene.Scene;
//import javafx.scene.layout.Pane;
//import javafx.scene.paint.Color;
//import javafx.scene.paint.Paint;
//import javafx.scene.shape.Circle;
//import javafx.stage.Stage;
//
//import java.util.Random;
//import java.util.Scanner;
//
//public class CircleDrawer extends Application {
//    private CustomCircle[] circles;
//    private int circleCount;
//
//    @Override
//    public void start(Stage primaryStage) {
//        Scanner scanner = new Scanner(System.in);
//        System.out.print("Enter the number of circles: ");
//        circleCount = scanner.nextInt();
//        scanner.close();
//
//        circles = new CustomCircle[circleCount];
//
//        Random random = new Random();
//        for (int i = 0; i < circleCount; i++) {
//            double x, y, radius;
//            do {
//                x = random.nextDouble() * 400;
//                y = random.nextDouble() * 400;
//                radius = 10 + random.nextDouble() * 10;
//            } while (!isValidLocation(x, y, radius));
//
//            Color color = new Color(random.nextDouble(), random.nextDouble(), random.nextDouble(), 1);
//            circles[i] = new CustomCircle(x, y, radius, color);
//        }
//
//        Pane pane = new Pane();
//        for (CustomCircle circle : circles) {
//            Circle fxCircle = new Circle(circle.getX(), circle.getY(), circle.getRadius());
//            fxCircle.setFill(circle.getColor());
//            pane.getChildren().add(fxCircle);
//        }
//
//        Scene scene = new Scene(pane, 800, 800);
//        primaryStage.setScene(scene);
//        primaryStage.show();
//    }
//
//    private boolean isValidLocation(double x, double y, double radius) {
//        for (CustomCircle circle : circles) {
//            if (circle != null && circle.intersects(new CustomCircle(x, y, radius, Color.TRANSPARENT))) {
//                return false;
//            }
//        }
//        return true;
//    }
//
//
//
//    public static void main(String[] args) {
//        launch(args);
//    }
//}
//
//class CustomCircle extends Circle{
//    private double x,y,radius;
//    private Color color;
//
//    public CustomCircle(double x,double y,double radius,Color color){
//        this.x=x;
//        this.y=y;
//        this.radius=radius;
//        this.color=color;
//    }
//
//    //判断两个圆是否相交
//    public boolean intersects(CustomCircle other){
//        double distance = Math.sqrt(Math.pow(this.x-other.getX(),2) +Math.pow(this.y - other.getY(), 2));
//        return distance < this.radius + other.getRadius();
//    }
//
//    public double getX() { return x;
//    }
//
//    public double getY() { return y;
//    }
//
//
//    public Paint getColor() { return color;
//    }
//}



//    /** Return true if the number d is a prefix for number */
//    public static boolean pretlixMatched (long number,int d){
//        String s = number+"";
//        if(s.charAt(0)==d) return true;
//        else return false;
//    }

//boolean[] cupBoard = new boolean[100];
////初始化柜子状态
//      for(int i=0;i<100;i++){
//cupBoard[i]=false;
//        }
//        for(int j=1;j<=100;j++){
//        for(int k=j;k<=100;k=k+j){
//cupBoard[k-1]=!cupBoard[k-1];
//        }
//        }
//
//        for(int l=0;l<100;l++){
//        if(cupBoard[l]) System.out.print( (l+1) +" ");
//        }




//        char[] zhiXiaShi = {'京','津','沪','瑜','冀','晋','辽','吉','黑','苏','浙','皖','闽',
//                '赣','鲁','豫','鄂','湘','粤','琼','川','贵','云','陕','甘','青','台','蒙','桂',
//        '藏','宁','新','港','澳'};
//        char[] diQuDaiMa = {'A','B','C','D','E','F','G','H','J','K','L','M'};
//
//        String string="3456789ABCDEFGHJKLMNPQRSTUVWXYZ";
//        char[] hunHe=new char[5];
//        for(int i=0;i<5;i++){
//
//            hunHe[i]=string.charAt((int)(string.length()*Math.random()));
//
//        }
//        int index1=(int)(zhiXiaShi.length*Math.random());
//        int index2=(int)(diQuDaiMa.length*Math.random());
//
//        char[] carNumber=new char[8];
//        carNumber[0]=zhiXiaShi[index1];
//        carNumber[1]=diQuDaiMa[index2];
//        carNumber[3]='·';
//        for(int j=3;j<8;j++){
//            carNumber[j]=hunHe[j-3];
//        }
//
//        System.out.println(carNumber);
//    }
//   String filename="D:\\code\\studycode\\java\\allhomework\\实验二.txt";
//   Scanner input =new Scanner(new File(filename));
//   double[] doubleValue = new double[12];
//   int i= 0;
//    while(input.hasNext()){
//    doubleValue[i]=Double.parseDouble(input.next());
//
//    i++;
//    }
//
//    double[] sum=new double[4];
//    double[] avarage=new double[3];
//
//    for(int  j=0;j<12;j+=3){
//        sum[j/3]=doubleValue[j]+doubleValue[j+1]+doubleValue[j+2];
//    }
//   for(int j=0;j<3;j++){
//       avarage[j]=(doubleValue[j]+doubleValue[j+3]+doubleValue[j+6]+doubleValue[j+9])/4;
//   }
//
//        System.out.print("从序号1到序号4的总分分别为");
//        for(int l=0;l<sum.length;l++){
//            System.out.print(sum[l]+" ");
//        }
//        System.out.printf("\n数学，语文，英语的平均分别为");
//        for(int l=0;l<avarage.length;l++){
//         System.out.print(avarage[l]+" ");
//        }
//    }
//}

//    Scanner input = new Scanner(System.in);
//    long longNumber = input.nextLong();
//    String s= longNumber+"";
//    if(s.length()>16||s.length()<13){
//        System.out.println("The card number is invalid");
//    }
//    else if(s.charAt(0)=='4'||s.charAt(0)=='5'||s.charAt(0)=='3'||s.charAt(0)=='6'||(s.charAt(0)=='2')){
//       if(s.charAt(0)=='3'&&s.charAt(1)=='7') {
//           if(isValid(longNumber)){
//           System.out.println("The card number is valid");
//       }
//           else System.out.println("The card number is invalid");
//    }
//
//     else if(isValid(longNumber)){
//        System.out.println("The card number is valid");
//     }
//    else System.out.println("The card number is invalid");
//    }
//    else System.out.println("The card number is invalid");
//
//  }
//
//  /** Return true if the card number is valid*/
//  public static boolean isValid(long number) {
//      if((sumOfDoubleEvenPlace(number)+sumOfOddPlace(number))%10==0)
//      return true;
//      else return false;
//  }
//
//    /** Get the result from Step 2*/
//  public static int sumOfDoubleEvenPlace(long number){
//      String s = number +"";int sum = 0;
//      for(int i=0;i<s.length();i=i+2){
//          sum+=getDogit(s.charAt(i)-'0');
//      }
//      return sum;
//  }
//
//  /** Return this number if it is a single digit，otherwise，
// *return the sum of the two digits */
//  public static int getDogit(int number){
//      return  number*2<10?number*2:(1+number*2%10);
//  }
//    /** Return sum of odd-place digits in number */
//    public static int sumOfOddPlace (long number){
//        String s=number+"";int sum=0;
//        for(int i=1;i<s.length();i+=2){
//            sum+=(s.charAt(i)-'0');
//        }
//        return sum;
//    }
//
//    /** Return the number of digits in d*/
//    public static int getSize(long d){
//        String s=d+"";
//        return s.length();

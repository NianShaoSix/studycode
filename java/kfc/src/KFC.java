import java.util.Scanner;
public class KFC {

    private static int numberOfHamburgers;

    public static void main(String[] args) {
        System.out.println("**************************");
        System.out.println("*****欢迎来到KFC自助点餐*****");
        System.out.println("**************************");
        System.out.println("*****请选择你要的套餐********");
        System.out.println("********1.汉堡*************");
        System.out.println("********2.炸鸡*************");
        System.out.println("********3.薯条*************");
        System.out.println("********4.饮料*************");
        Scanner input=new Scanner(System.in);

        //menu
        Hamburgers newSpicyChickenThighClayPot=new Hamburgers("新辣鸡腿堡",13.5) ;
        Hamburgers newOrleansGrilledChickenLegBurger=new Hamburgers("新奥尔良烤鸡腿堡",14.5) ;
        FriedChicken friedChicken=new FriedChicken("蜜汁手扒鸡",29.9);
        Chip huaFu1=new Chip("华夫薯条",9.9,"小");
        Chip huaFu2=new Chip("华夫薯条",15.9,"中");
        Chip huaFu3=new Chip("华夫薯条",20.9,"大");
        Drinks coCo1=new Drinks("可口可乐",10.0,"小");
        Drinks coCo2=new Drinks("可口可乐",15.0,"中");
        Drinks coCo3=new Drinks("可口可乐",20.0,"大");
        Drinks cafe1=new Drinks("圣耶拿铁",9.9,"小");
        Drinks cafe2=new Drinks("圣耶拿铁",15.9,"中");
        Drinks cafe3=new Drinks("圣耶拿铁",20.9,"大");
        //优惠前总费用
         double expense=0;

        //选择套餐
        int choice=input.nextInt();
        switch(choice){
            case 1:
                System.out.println(newSpicyChickenThighClayPot.name + "￥" +newSpicyChickenThighClayPot.price+"/份");
                System.out.println(newOrleansGrilledChickenLegBurger.name + "￥" +newOrleansGrilledChickenLegBurger.price+"/份");
                System.out.println("请输入你需要选择的汉堡名字和份数");
                String nameOfHamburgers=input.nextLine();
                numberOfHamburgers = Hamburgers.getNumber();

            case 2:
                System.out.println(friedChicken.name + "￥" + friedChicken.price + "/份");
                System.out.println("请输入你需要选择的炸鸡名字和份数");
                String nameOfFriedChicken=input.nextLine();
                int numberOfFriedChicken=Hamburgers.getNumber();
                break;

            case 3:
                System.out.println(huaFu1.name + "￥" + huaFu1.price + "/份"+ huaFu1.size + "份");
                System.out.println(huaFu2.name + "￥" + huaFu2.price + "/份"+ huaFu2.size + "份");
                System.out.println(huaFu3.name + "￥" + huaFu3.price + "/份"+ huaFu3.size + "份");
                System.out.println("请输入你需要选择的薯条名字和份数");
                String nameOfChip=input.nextLine();
                int numberOfChip=Hamburgers.getNumber();
                break;

            case 4:
                System.out.println(coCo1.name + "￥" + coCo1.price + "/杯" + coCo1.size + "杯" );
                System.out.println(coCo2.name + "￥" + coCo2.price + "/杯" + coCo2.size + "杯" );
                System.out.println(coCo3.name + "￥" + coCo3.price + "/杯" + coCo3.size + "杯" );
                System.out.println("请输入你需要选择的饮品名字和大小和数量");
                String nameOfDrinks=input.next();
                String sizeOfDrinks=input.next();
                int numberOfDrinks=Hamburgers.getNumber();
                break;
            default:System.out.println("选择错误无相关商品");

            //选择堂食还是打包
                System.out.println("堂食还是打包 （打包的话需要额外收取三元打包费）");
                String wayOfEating= input.next();
                if(wayOfEating.equals("打包")) expense+=5;
            //计算费用

            //是否使用会员优惠 打7.9折 使用会员优惠就不能再使用单独优惠券
        System.out.println("选择使用会员vip还是使用优惠券（只能使用其中一种）会员优惠为7.9折");
        System.out.println("******1.会员***2.优惠券");
        int a=input.nextInt();
        switch (a){
            case 1:
                    System.out.println("请输入您的姓名和会员ID(手机号码)");
                    String customersName= input.next();
                    long ID= input.nextLong();
                    if( VipCustomers.isVipCustomers(customersName,ID) )
                        expense*=0.79;
                    break;
            //是否使用优惠券
            case 2:
                int choice2=input.nextInt();
                System.out.println("请选择使用哪种优惠券1.每周五元代金券2. 88折券 ");
                switch (choice2){
                    case 1:expense=expense-5; break;
                    case 2:expense*=0.88;
                }
                break;
            }
        }
    }
}

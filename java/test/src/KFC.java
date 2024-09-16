import java.util.Scanner;
public class KFC {
    public static void main(String[] args){
        //会员 //使用对象数组可能更好
        VIP vip1 = new VIP(12345678, "87654321");
        VIP vip2 = new VIP(123456789,"987654321");
        //菜单 打印
             //套餐
        Package package1=new Package("单人套餐(包含一个汉堡，一杯可乐，一个鸡腿)",35.9);
        Package package2=new Package("双人套餐（包含一个汉堡，一个鸡肉卷，两杯可乐，一份薯条）",59.9);
        Package package3=new Package("多人套擦（超值全鸡桶）",101);

            //单品
        Food quanJi1=new Food("蜜汁全鸡",39.8);
        Food quanJi2=new Food("脆皮全鸡",39.8);

        Food friedChicken1=new Food("脆皮鸡块",12.5);
        Food friedChicken2=new Food("黄金脆皮鸡腿",13.5);
        Food friedChicken3=new Food("劲爆鸡米花",12);
        Food friedChicken4=new Food("新奥尔良鸡翅",13.5);

        Drinks drinks1=new Drinks("coco可乐",8.5);
        Drinks drinks2=new Drinks("九龙金玉轻乳茶系列",13);
        Drinks drinks3=new Drinks("暴汁三柠茶",13);
        Drinks drinks4=new Drinks("九珍果汁饮料",13);

        //点餐
        System.out.println("*******************************");
        System.out.println("******欢迎来到KFC自助点餐*********");
        System.out.println("******请选择需要点套餐商品*********");
        System.out.println("*******************************");
        System.out.println("*******************************");

        Scanner input=new Scanner(System.in);
        //选择套餐或者单品
        switch (1){
           case 1:

               System.out.println("**********套餐************");
               System.out.println("套餐1:" + package1.name + "  ￥"+ package1.price);
               System.out.println("套餐2:" + package2.name + "  ￥"+ package2.price);
               System.out.println("套餐3:" + package3.name + "  ￥"+ package3.price);
               System.out.println("********请选择需要的套餐及数量************");

               System.out.println("请选择购买套餐1的数量");
               int numberOfPackage1=input.nextInt();
               package1.number=package1.getNumber(numberOfPackage1);

               System.out.println("请选择购买套餐2的数量");
               int numberOfPackage2=input.nextInt();
               package2.number=package2.getNumber(numberOfPackage2);

               System.out.println("请选择购买套餐3的数量");
               int numberOfPackage3=input.nextInt();
               package3.number=package3.getNumber(numberOfPackage3);

           case 2:

               System.out.println("**********单品************");
               System.out.println(quanJi1.name + "  ￥"+ quanJi1.price);
               System.out.println(quanJi2.name + "  ￥"+ quanJi2.price);

               System.out.println(friedChicken1.name + "  ￥"+ friedChicken1.price);
               System.out.println(friedChicken2.name + "  ￥"+ friedChicken2.price);
               System.out.println(friedChicken3.name + "  ￥"+ friedChicken3.price);
               System.out.println(friedChicken4.name + "  ￥"+ friedChicken4.price);

               System.out.println(drinks1.name + "  ￥"+ drinks1.price);
               System.out.println(drinks2.name + "  ￥"+ drinks2.price);
               System.out.println(drinks3.name + "  ￥"+ drinks3.price);
               System.out.println(drinks4.name + "  ￥"+ drinks4.price);

               System.out.println("********请选择需要的单品及数量************");

                   //全鸡

               System.out.println("请输入你要购买蜜汁全鸡的数量");
               int numberOfQuanJi1=input.nextInt();
               quanJi1.number=quanJi1.getNumber(numberOfQuanJi1);

               System.out.println("请输入你要购买脆皮全鸡的数量");
               int numberOfQuanJi2=input.nextInt();
               quanJi2.number=quanJi2.getNumber(numberOfQuanJi2);

                   //炸鸡

               System.out.println("请输入你要购买脆皮鸡块的数量");
               int numberOfFriedChicken1=input.nextInt();
               friedChicken1.number=friedChicken1.getNumber(numberOfFriedChicken1);

               System.out.println("请输入你要购买黄金脆皮鸡腿的数量");
               int numberOfFriedChicken2=input.nextInt();
               friedChicken2.number=friedChicken2.getNumber(numberOfFriedChicken2);

               System.out.println("请输入你要购买劲爆鸡米花的数量");
               int numberOfFriedChicken3=input.nextInt();
               friedChicken3.number=friedChicken3.getNumber(numberOfFriedChicken3);

               System.out.println("请输入你要购买新奥尔良鸡翅的数量");
               int numberOfFriedChicken4=input.nextInt();
               friedChicken4.number=friedChicken4.getNumber(numberOfFriedChicken4);

                   //饮料

               System.out.println("请输入你要购买coco可乐的数量");
               int numberOfDrinks1=input.nextInt();
               drinks1.number=drinks1.getNumber(numberOfDrinks1);

               System.out.println("请输入你要购买九龙金玉轻乳茶系列的数量");
               int numberOfDrinks2=input.nextInt();
               drinks2.number=drinks2.getNumber(numberOfDrinks2);

               System.out.println("请输入你要购买暴汁三柠茶的数量");
               int numberOfDrinks3=input.nextInt();
               drinks3.number=drinks3.getNumber(numberOfDrinks3);

               System.out.println("请输入你要购买九珍果汁饮料的数量");
               int numberOfDrinks4=input.nextInt();
               drinks4.number=drinks4.getNumber(numberOfDrinks4);


       //计算总消费
       double totalMoney=0;
       totalMoney = totalMoney(package1.price,package1.number) + totalMoney(package2.price,package2.number) + totalMoney(package3.price,package3.number) +
                    totalMoney(quanJi1.price,numberOfQuanJi2) + totalMoney(quanJi2.price, numberOfQuanJi2) + totalMoney(friedChicken1.price,numberOfFriedChicken1) +
                    totalMoney(friedChicken2.price,numberOfFriedChicken2) + totalMoney(friedChicken3.price,numberOfFriedChicken3) + totalMoney(friedChicken4.price,numberOfFriedChicken4) +
                    totalMoney(drinks1.price,numberOfDrinks1) + totalMoney(drinks2.price,numberOfDrinks2) + totalMoney(drinks3.price,numberOfDrinks3) + totalMoney(drinks4.price,numberOfDrinks4);

       //是否是会员 若不是是否要加入会员
        System.out.println("请问你是会员吗？（使用会员打八八折）");
        System.out.println("1.是的  2.不是");
        int choice2 = input.nextInt();
        if(choice2==1){

            System.out.println("请输入你的会员账号及密码");
            //判断输入的账号和密码是否正确
            System.out.print("请输入你的会员账号：");
            long id = input.nextInt();
            System.out.print("请输入你的账号密码：");
            String passwords = input.next();
            if(id==vip1.id && passwords.equals(vip1.code) || id==vip2.id && passwords.equals(vip2.code))
            totalMoney *=0.88;
            else System.out.println("账号或密码输入错误");
        }
        else {
             System.out.println("是否要加入会员（免费加入会员）");
             System.out.println("1.加入  2.不加入");
            int choice3 = input.nextInt();
            if(choice3==1){
             //随机生成一个账号并让顾客设置密码
                VIP vip3 = new VIP();
                vip3.id = (long)(Math.random()*100000000);
                System.out.println("你的会员账号为： " + vip3.id);
                System.out.println("请输入设置你的密码");
                vip3.code = input.next();
                totalMoney*=0.88;
            }

        }
       //选择打包或者堂食
       System.out.println("打包还是堂食");
       System.out.println("1.打包 2.堂食");
       int way=input.nextInt();
       if(way==1) totalMoney+=5;

       //打印发票
        System.out.println("总消费为：" + totalMoney);
       }


    }
    public static double totalMoney(double p,int n){
        return p * n;
    }
}
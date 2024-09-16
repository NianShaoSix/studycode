public class VipCustomers {
    static String name;
    static long vipID;
    VipCustomers(String newName,long  newVipID){
        name = newName;
        vipID=newVipID;
    }
    public static boolean isVipCustomers(String name,long vipID){
       return (name.equals(VipCustomers.name)&& vipID==VipCustomers.vipID);

    }
}

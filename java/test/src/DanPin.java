public class DanPin {
    double price;
    String name;
    int number;

    public DanPin(){

    }
    public DanPin(String name, double price){
        this.name=name;
        this.price=price;
    }

    public String getName(String name) {
       return name;
    }

    public void setName(String name){
        this.name=name;
    }

    public double getPrice(double price){
        return price;
    }

    public void setPrice(double price){
        this.price=price;
    }

    public int getNumber(int number){
        return number;
    }

    public void setNumber(int number){
        this.number=number;
    }

}

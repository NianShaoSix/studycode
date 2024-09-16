public class Package {
    String name;
    double price;
    int number;

    public Package(String name, double price){
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
}


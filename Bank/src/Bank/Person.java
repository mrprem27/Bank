package Bank;

public class Person {
    protected
    String name;
    char sex;
    String address;
    String dob;

    public
    Person(String name, String address, char sex, String dob)
    {
        this.name = name;
        this.sex = sex;
        this.address = address;
        this.dob = dob;
    }
    void getDetailsPerson()
    {
        System.out.println("Name    : " + name);
        System.out.println("Sex     : " + sex);
        System.out.println("Address : " + address);
        System.out.println("dob     : " + dob);
    }
}
/*    Person(String name, String address, char sex)
    {
        this.name = name;
        this.sex = sex;
        this.address = address;
        this.dob = "null";
    }*/


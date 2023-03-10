interface I1{
    void show();
    //default void display(){  //or static method
    //}
}
public class Test implements I1{
    public void show(){
        System.out.println("Hi");
    }
    public static void main(String[] args){
        Test t = new Test();
        t.show();
    }
}
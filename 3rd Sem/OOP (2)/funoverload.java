class student{
    void accept(int r){
        System.out.println("Roll.no. is " + r);
    }
    void accept(double p){
        System.out.println("Percentage is " + p);
    }
    public void information() {
    }
}                         //Himanshu Agarkar
class funoverload {       //A45 20010343
    public static void main(String[] args){
        student S1 = new student();
        S1.accept(45);
        S1.accept(96.2);
    }
}

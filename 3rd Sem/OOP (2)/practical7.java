class Employee{
    void work(){
        System.out.println("I work ");
    }
}
class Teacher extends Employee{
    void work(){
                        
        System.out.println("I teach");
    }
}                              //Himanshu Agarkar
class Stud extends Teacher{    //A45 20010343
    void work(){
        System.out.println("I study");
    }
}
class Developer extends Employee{
    void work(){
        System.out.println("I develop apps");
    }
}
public class practical7{
    public static void main(String[] args){
        Employee E1 = new Employee();
        Teacher E2 = new Teacher();
        Stud E3 = new Stud();
        Developer E4 = new Developer();
        E1.work();
        E2.work();
        E3.work();    
        E4.work();      
    }
}

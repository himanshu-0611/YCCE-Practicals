import java.util.*;
class college{
    int rollno, regno;
    double percentage;
    void information(){
        Scanner sc= new Scanner(System.in);
        System.out.print("Enter Roll.no. : ");
        int rollno = sc.nextInt(); 
        System.out.print("Enter Registration number : ");
        int regno = sc.nextInt();
        System.out.print("Enter Precentage : ");
        double percentage = sc.nextDouble();
        information(rollno, regno, percentage);
        sc.close();
    }
    void information(int rn, int reg, double per){
        System.out.println("Roll no is : " + rn);
        System.out.println("Registration number is : " + reg);
        System.out.println("Percentage is : " + per);
    }   
}
public class practical2 {
    public static void main(String[] args){
        college s1 = new college();
        s1.information();
    }
}

// import java.util.*;  
// class practical2   
// {  
// public static void main(String[] args)  
// {  
// Scanner sc= new Scanner(System.in);    //System.in is a standard input stream  
// System.out.print("Enter first number- ");  
// int a= sc.nextInt();  
// System.out.print("Enter second number- ");  
// int b= sc.nextInt();  
// System.out.print("Enter third number- ");  
// int c= sc.nextInt();  
// int d=a+b+c;  
// System.out.println("Total= " +d);  
// }  
// }  
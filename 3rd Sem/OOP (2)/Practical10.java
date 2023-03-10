import java.util.*;
public class Practical10 {
    public static int flag;
    public static void main(String args[]){  
   try{  
      Scanner s = new Scanner(System.in);
      System.out.println("Enter an Even number");
      int data= s.nextInt();  
      if(data%2 != 0){
          data = data/0;
      }                     //Himanshu Agarkar
      s.close();            //A45 20010343
   }
   catch(ArithmeticException e){
       System.out.println("Entered number is not even");
       flag = 0;
    }
    if(flag != 0){
        System.out.println("Program executed successfully");  
    }
  }  
}
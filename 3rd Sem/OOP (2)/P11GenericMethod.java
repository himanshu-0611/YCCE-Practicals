// public class P11GenericMethod {
//     public int printSum(int[] s) {
//         int sum = 0;
//         for(int i=0; i<s.length; i++) {
//             sum = sum + s[i];
//         }
//         return sum;
//     }
//     public static void main(String[] args) {
//         Practical11Generic e1=new Practical11Generic();
//         Integer numbers[]={32, 23};
//         System.out.println(e1.printSum(numbers)); 
//     }
//  }

// public class genMethod {
//     public t num1, num2;
//     genMethod(t n1, t n2) {
//         num1 = n1;
//         num2 = n2;
//     }
//     return num1 + num2;
// }

// public class P11GenericMethod {
//     public static void main(String[] args) {
//         genMethod e1=new genMethod(2, 3);
//         System.out.println(e1.genMethod());
//     }
// }

public class P11GenericMethod {
    // determines the largest of three Comparable objects
    
    public static T maximum(T x, T y) {
        int sum = x+y;
       return sum;   // returns the largest object   
    }
    
    public static void main(String args[]) {
        P11GenericMethod e1=new maximum(2, 3);
        System.out.println(e1.maximum());
    }
 }
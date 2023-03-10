import java.util.*;
public class Practical6{
   public static void main(String[] args) {
      List<String> a1 = new ArrayList<String>();
      a1.add("Kohli");
      a1.add("Dhoni");
      a1.add("Rohit");
      System.out.println(" ArrayList Elements");
      System.out.print("\t" + a1);

      List<String> l1 = new LinkedList<String>();
      l1.add("Kohli");
      l1.add("Dhoni");          //Himanshu Agarkar
      l1.add("Rohit");          //A45 20010343
      System.out.println();
      System.out.println(" LinkedList Elements");
      System.out.print("\t" + l1);

      Set<String> s1 = new HashSet<String>(); 
      s1.add("Kohli");
      s1.add("Dhoni");
      s1.add("Rohit");
      System.out.println();
      System.out.println(" Set Elements");
      System.out.print("\t" + s1);

      Map<String, String> m1 = new HashMap<String, String>(); 
      m1.put("Kohli", "8");
      m1.put("Dhoni", "31");
      m1.put("Rohit", "12");
      m1.put("Pandya", "14");
      System.out.println();
      System.out.println(" Map Elements");
      System.out.print("\t" + m1);
   }
}
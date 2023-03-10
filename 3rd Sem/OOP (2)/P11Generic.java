import java.util.*;
class generic<a extends Number,b extends Number>{
      a obj1;
      b obj2;
      generic(a obj1,b obj2)
      {
         this.obj1=obj1;          //Himanshu Agarkar
         this.obj2=obj2;          //A45 20010343
      }
      public void add()
      {
           System.out.println(obj1.intValue() +obj2.doubleValue());
      }
}
public class P11Generic
{
	public static void main(String[] args) {
	     generic<Integer,Double> ob=new  generic<>(40,9.893);
	     ob.add();
	}
}
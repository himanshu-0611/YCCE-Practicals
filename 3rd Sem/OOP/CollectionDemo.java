import java.util.ArrayList;
public class CollectionDemo {
    public static void main(String[] args) {
        ArrayList al = new ArrayList();
        al.add(100);
        al.add("String");
        al.add('c');
        System.out.println(al);
        System.out.println(al.add("aaa"));
        System.out.println(al.contains('c'));

        ArrayList al2 = new ArrayList();
        al2.add("aaa");
        al2.add("bbb");
        al2.add("ccc");
        System.out.println(al2);
        System.out.println(al.isEmpty());

        al.addAll(al2);
        System.out.println(al);
        System.out.println(al.size());
        al.remove(1);  //Index as patameter
        System.out.println(al);        
    }
}

class Container<T> {
    T value;
}

public class GenericsDemo {
    public static void main(String[] args) {
        Container<Integer> obj = new Container<>();
        obj.value = 9;
        System.out.println(obj.value);
        
    }
}

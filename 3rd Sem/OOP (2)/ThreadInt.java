class ThreadC implements Runnable{
    public void run(){
        System.out.println("ThreadC started");
        for(int i=0; i<4; i++){
            System.out.println("Thread A = " + i);
        }
    }
}
public class ThreadInt {
    public static void main(String args[]){
        ThreadC a = new ThreadC();
        Thread T1 = new Thread(a);
        T1.start();
    }
}

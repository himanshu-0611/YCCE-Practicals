
class ThreadA extends Thread{
    public void run(){
        System.out.println("ThreadA started");
        for(int i=0; i<4; i++){
            System.out.println("Thread A = " + i);
        }
    }
}
class ThreadB extends Thread{
    public void run(){
        System.out.println("ThreadB started");        
        for(int i=1; i<4; i++) {
            System.out.println("Thread B = " + i);
        }
    }
}
class ThreadC extends Thread{
    public void run(){
        System.out.println("ThreadC started");
        for(int i=0; i<4; i++){
            System.out.println("Thread C = " + i);
        }
    }
}
public class ThreadPriority {
    public static void main(String args[]){
        ThreadA a = new ThreadA();
        ThreadB b = new ThreadB();
        ThreadC c = new ThreadC();
        a.setPriority(9);
        b.setPriority(3);
        c.setPriority(5);
        a.start();
        b.start();
        c.start();
    }
}

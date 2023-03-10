class ThreadA extends Thread{
    public void run(){
        System.out.println("ThreadA started");
        for(int i=0; i<4; i++){
            if(i == 2){
                try{                                 //Himanshu Agarkar
                    Thread.sleep(10000);             //A45 20010343
                }
                catch(Exception e){
                    System.out.println("InterruptedException is caught");
                }
            }
            System.out.println("Thread A = " + i);
        }
    }
}
class ThreadB extends Thread{
    public void run(){
        System.out.println("ThreadB started");
        synchronized(this) {
            for(int i=1; i<4; i++) {
                System.out.println("Thread B = " + i);
            }
            this.notify();
        }
    }                                  //Himanshu Agarkar
}                                      //A45 20010343
class ThreadC extends Thread{
    public void run(){
        System.out.println("ThreadC started");
        for(int i=0; i<4; i++){
            Thread.yield();
            System.out.println("Thread started");
            System.out.println("Thread C = " + i);
        }
    }
}
public class Practical9Thread {
    public static void main(String args[]) throws InterruptedException {
        ThreadA a = new ThreadA();
        ThreadB b = new ThreadB();
        ThreadC c = new ThreadC();
        a.start();
        b.start();
        synchronized(b) {
            b.wait();
            System.out.println("Thread B is notified");
        }
        c.start();
    }
}

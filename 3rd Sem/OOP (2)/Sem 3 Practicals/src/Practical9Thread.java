class ThreadA extends Thread{
    public void run(){
        System.out.println("ThreadA started");
        for(int i=0; i<4; i++){
            if(i == 2){
                try{
                    Thread.sleep(1000);
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
        for(int i=0; i<4; i++){
            System.out.println("Thread B = " + i);
            if(i == 3) {
                try{
                    wait();
                }
                catch(Exception e){
                    System.out.println("InterruptedException is caught");
                }
            }
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
public class Practical9Thread {
    public static void main(String args[]){
        ThreadA a = new ThreadA();
        ThreadB b = new ThreadB();
        ThreadC c = new ThreadC();
        a.start();
        b.start();
        c.start();
    }
}

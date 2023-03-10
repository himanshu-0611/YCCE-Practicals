// class ThreadA extends Thread{
//     public void run(){
//         System.out.println("ThreadA started");
//     }
// }
// class ThreadDemo{
//     public static void main(String args[]){
//         ThreadA a = new ThreadA();
//         a.start();
//     }
// }

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
        for(int i=0; i<4; i++){
            System.out.println("Thread B = " + i);
        }
    }
}
class ThreadExtension{
    public static void main(String args[]){
        ThreadA a = new ThreadA();
        ThreadB b = new ThreadB();
        a.start();
        b.start();
    }
}
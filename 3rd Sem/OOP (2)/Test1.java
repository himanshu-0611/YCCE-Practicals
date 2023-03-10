import java.io.*;
class Test1 {
    public static void main(String[] args){
        try{
            FileInputStream fis = new FileInputStream("C:/Users/HP/Desktop/Java/EH.txt");
            fis.close();
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}

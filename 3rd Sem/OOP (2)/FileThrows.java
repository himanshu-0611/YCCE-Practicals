import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;
class ReadandWrite {
    void readFile() throws FileNotFoundException{
        FileInputStream fis = new FileInputStream("C:/Users/HP/Desktop/Java/Test1.tzt");
        System.out.println(fis);
    }
    void writeFile() throws FileNotFoundException{
        String text = "this is demo";
        FileOutputStream fos = new FileOutputStream("C:/Users/HP/Desktop/Java/xyz.txt");
    }
}
class FileThrows {
    public static void main(String[] args) {
        ReadandWrite rw = new ReadandWrite();
        try{
            rw.readFile();
        }
        catch(FileNotFoundException e){
            e.printStackTrace();
        }
        System.out.println("Hello");
    }
}

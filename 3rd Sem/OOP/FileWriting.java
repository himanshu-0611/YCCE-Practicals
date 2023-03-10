import java.io.FileWriter;
import java.io.IOException;
public class FileWriting {
    public static void main(String[] args) {
        try {
            FileWriter myWrite = new FileWriter("C:\\Users\\HP\\Desktop\\Java1\\fileCreation.txt");
            myWrite.write("Himanshu");
            myWrite.close();
            System.out.println("Successfully wrote the file");
        }
        catch (IOException e) {
            System.out.println("An error occured");
            e.printStackTrace();
        }
    }
}

import java.io.*;
import java.util.*;
public class FileReading {
    public static void main(String[] args) {
        try {
            File myObj = new File("C:\\Users\\HP\\Desktop\\Java1\\fileCreation.txt");
            Scanner sc = new Scanner(myObj);
            while(myObj.hasNextLine()) {
                String data = myObj.nextLine();
                System.out.println(data);
            }
            ((Closeable) myObj).close();
        }
        catch (FileNotFoundException e) {
            System.out.println("An error occured");
            e.printStackTrace();
        }
    }
}

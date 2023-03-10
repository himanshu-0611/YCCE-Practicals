import java.io.File;
import java.io.IOException;
public class CreateFile {

	public static void main(String[] args) {
		try {
			File myObj = new File("C:\\Users\\HP\\Desktop\\Java1\\fileCreation.txt");
			if(myObj.createNewFile()) {
				System.out.println(myObj.createNewFile());
				System.out.println("File created: " + myObj.getName());
			}
			else {
				System.out.println("File already exists");
			}
		}
		catch(IOException e) {
			System.out.println("An error occured");
			e.printStackTrace();
		}
	}

}


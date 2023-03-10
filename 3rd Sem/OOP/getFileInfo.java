import java.io.File;
public class getFileInfo {

	public static void main(String[] args) {
		File myObj = new File("C:\\Users\\HP\\Desktop\\Java1\\fileCreation.txt");
		if(myObj.exists()) {
			System.out.println("File name: " + myObj.getName());
			System.out.println("File size in bytes " + myObj.length());
		}
		else {
			System.out.println("The file does not exists");
		}
	}

}

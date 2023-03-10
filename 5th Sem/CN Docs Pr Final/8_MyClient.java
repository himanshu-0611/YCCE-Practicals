import java.io.*;
import java.net.*;

public class MyClient {
    public static void main(String[] args) {
        try {
            Socket s = new Socket("localhost", 6665);
            DataOutputStream dout = new DataOutputStream(s.getOutputStream());
            dout.writeUTF("I use CPP for coding");
            dout.flush();
            dout.close();
            s.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
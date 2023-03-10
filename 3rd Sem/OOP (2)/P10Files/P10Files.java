import java.io.*;
import java.util.Scanner;

public class P10Files
{
    public static void main(String args[]) throws IOException
    {                         //Himanshu Agarkar
        if(args.length<3)     //A45 20010343
        {
            System.out.println("Please enter 3 parameters!!!");
            System.exit(0);
        }
        System.out.println("Source number file : "+args[0]);
        System.out.println("Even number file : "+args[1]);
        System.out.println("Odd number file : "+args[2]);
        
        File num = new File(args[0]);
        File even = new File(args[1]);
        File odd = new File(args[2]);
        try 
        {
            Scanner fin = new Scanner(num);
            while (fin.hasNextLine()) 
            {
                int num1 = fin.nextInt();
     
                if(num1%2==0)
                {
                    FileWriter fw = new FileWriter(even,true); 
                    fw.write(num1+"\n");
                    fw.close();
                }
                else    
                {
                    FileWriter fw = new FileWriter(odd,true); 
                    fw.write(num1+"\n");
                    fw.close();
                }
            }
            System.out.println("Copied Succussfully");
            fin.close();
        } 
        catch (FileNotFoundException e) 
        {
            System.out.println("numbers.txt no found");
            e.printStackTrace();
        }
    }
    
}
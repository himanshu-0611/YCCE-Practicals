import java.io.*;
class Practical10Files{  
 public static void main(String args[]) throws FileNotFoundException{  
  // String inf = new String(args[0]);
  // String outf1 = new String(args[0]);
  // String outf2 = new String(args[0]);
  // File inf = new File(args[0]);  
  // File outf1 = new File(args[0]);  
  // File outf2 = new File(args[0]);  
  File inf = new File("numbers.txt");  
  File outf1 = new File("even.txt");  
  File outf2 = new File("odd.txt");  
  FileReader ins = null;  
  FileWriter outs1 = null;  
  FileWriter outs2 = null;  
  try {  
   ins = new FileReader(inf);  
   outs1 = new FileWriter(outf1);  
   outs2 = new FileWriter(outf2);  
   int ch;  
   while ((ch = ins.read()) != -1) {
    if(ch != ' ' && Character.getNumericValue(ch)%2 == 0) {
        outs1.write(ch);
        outs1.write(" ");
    }
    if(ch != ' ' && Character.getNumericValue(ch)%2 != 0) {
        outs2.write(ch);
        outs2.write(" ");
    }  
   }  
  } catch (IOException e) {  
   System.out.println(e);  
   System.exit(-1);  
  } finally {  
   try {  
    ins.close();  
    outs1.close();  
    outs2.close();  
   } catch (IOException e) {}  
  }  
 }  
} 
import java.util.*;
class YoungerAgeException extends RuntimeException
{
    YoungerAgeException(String msg)
    {
        super(msg);
    }
}
class VoteThrow
{
    public static void main(String[] srgs)
    {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter you age: ");
        int age=s.nextInt();
        try{
            if(age<18){
                throw new YoungerAgeException("You are not eligible to vote");
                //Doesn't execute any code from this line to the end of the block
            }
            else{
                System.out.println("You can vote");
            }
            s.close();
        }
        catch(YoungerAgeException e){
            e.printStackTrace();
        }
        System.out.println("Hello");
    }
}

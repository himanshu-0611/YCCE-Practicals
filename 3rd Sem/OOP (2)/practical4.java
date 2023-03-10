abstract class Sports{
    int no_of_players;
    abstract void play();
}
class Cricket extends Sports{
    int no_of_players = 11;
    void play(){
        System.out.println("Played with bat, no of players: " + no_of_players);
    }
}                                 //Himanshu Agarkar
class Tennis extends Sports{      //A45 20010343
    int no_of_players = 2;
    void play(){
        System.out.println("Played with racket, no of players: " + no_of_players);
    }
}
public class practical4 {
    public static void main(String[] args){
        Cricket c1 = new Cricket();
        c1.play();
        Tennis t1 = new Tennis();
        t1.play();
    }
}

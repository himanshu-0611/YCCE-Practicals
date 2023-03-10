class bowler{
	int matches;   
	double average;
	bowler() {
		matches = 45;
		average = 96.2;           
	}              
    bowler(int r, double p){
        matches = r;
        average = p;
    }           
    bowler(bowler s){
        matches = s.matches;
        average = s.average;     //Himanshu Agarkar
    }                            //A45 20010343
	void put() {  
		System.out.println("Matches Played : " + matches);
		System.out.println("Bowling Average : " + average);
	}
}
class practical3{
	public static void main(String[] args) {
		bowler S1 = new bowler();
        bowler S2 = new bowler(45, 96.2);
        bowler S3 = new bowler(S2);
        System.out.println("\nDefault");
		S1.put();
        System.out.println("\nParametric");
        S2.put();
        System.out.println("\nCopy");
        S3.put();
	}
}


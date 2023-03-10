
class add{
	int rollno;
	double per;
	public void input(int r, double p) {
		rollno = r;
		per = p;             //Himanshu Agarkar
	}                        //A45 20010343
	public void output() {  
		System.out.println("Roll Number : " + rollno);
		System.out.println("Percentage : " + per);
	}
}
class practical1{
	public static void main(String[] args) {
		add S1 = new add();
		S1.input(45, 96.5);
		S1.output();
	}
}
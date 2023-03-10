public class StackTraceDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			getValue();
		}
		catch (Exception cause) {
			StackTraceElement stackTraceElements[] = cause.getStackTrace();
			int n = stackTraceElements.length;
			for(int i=0; i<n; i++) {
				System.err.println(stackTraceElements[i].getFileName() + ":" + 				stackTraceElements[i].getLineNumber() + ">>" + 				stackTraceElements[i].getMethodName() + "()");
			}
		}
	}
	public static int getValue() {
		int a = 10/0;
		return a;
	}
}

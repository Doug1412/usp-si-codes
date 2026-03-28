import java.util.*;

class TesteScanner {

	public static void main(String [] args){

		Scanner scanner = new Scanner(System.in);

		while(scanner.hasNext()){

			System.out.println("token: " + scanner.next());
		}
	}
}

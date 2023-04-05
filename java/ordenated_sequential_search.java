import java.util.Scanner;

public class sequential_search {

	public static void main(String[] args) {

		int[] array = new int[10];
		int i, n;
		boolean achou;

		Scanner s = new Scanner(System.in);
		for(i=0; i < 10; i++) {

			System.out.print("Type the "+(i+1)+"° number: ");
			array[i] = s.nextInt();
		}

		System.out.print("\nType the number to look for: ");
		n = s.nextInt();

		i=0;
		achou = false;
		while(!achou && i < 10) {

			if(array[i] == n) {
				achou = true;
			} else {
				i++;
			}
		}

		if(achou)
			System.out.println("Number found at position " + (i+1));
		else
			System.out.println("Number not found");
	}
}

import java.util.Scanner;

public class binary_search {

	public static void main(String[] args) {

		int[] array = new int[10];
		int i, n, inicio, meio, fim;
		boolean achou;

		for(i=0;i<10;i++) {

			array[i] = i+1;
		}

		Scanner s = new Scanner(System.in);
		System.out.print("Type the number to look for: ");
		n = s.nextInt();

		achou = false;
		inicio = 0;
		fim = 9;
		meio = (inicio+fim)/2;

		while(!achou && inicio <= fim) {

			if(array[meio] == n)
				achou = true;
			else {
				if(n < array[meio])
					fim = meio - 1;
				else
					inicio = meio + 1;
				meio = (inicio+fim)/2;
			}
		}

		if(achou)
			System.out.println("Number found at position " + (meio + 1));
		else
			System.out.println("Number not found");
	}
}

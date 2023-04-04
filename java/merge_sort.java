import java.util.*;

public class merge_sort {

	public static void main(String[] args){

		int[] array = new int[10];
		int i;

		Scanner s = new Scanner(System.in);
		for(i = 0; i < 10; i++)
		{
			System.out.print("Type the "+(i+1) + "° number: ");
			array[i] = s.nextInt();
		}

		merge(array, 0, 9);

		for(i = 0; i < 10; i++){

			System.out.println((1+i) + "° number: " + array[i]);
		}
	}

	public static void merge(int array[], int inicio, int fim) {

		int meio;
		if(inicio < fim) {
			meio = (inicio + fim) / 2;
			merge(array, inicio, meio);
			merge(array, meio+1, fim);
			intercala(array, inicio, fim, meio);
		}
	}

	public static void intercala(int array[], int inicio, int fim, int meio) {

		int poslivre, inicio_v1, inicio_v2, i;
		int[] aux = new int[10];

		inicio_v1 = inicio;
		inicio_v2 = meio + 1;
		poslivre = inicio;

		while(inicio_v1 <= meio && inicio_v2 <= fim) {

			if(array[inicio_v1] <= array[inicio_v2]) {
				aux[poslivre] = array[inicio_v1];
				inicio_v1++;
			} else {

				aux[poslivre] = array[inicio_v2];
				inicio_v2++;
			}
			poslivre++;
		}

		//checking if have no element merged
		for(i=inicio_v1; i <= meio; i++)
		{
			aux[poslivre] = array[i];
			poslivre++;
		}

		for(i=inicio_v2; i <= fim; i++)
		{
			aux[poslivre] = array[i];
			poslivre++;
		}

		//return for the original array
		for(i=inicio; i <= fim; i++)
		{
			array[i] = aux[i];
		}
	}
}

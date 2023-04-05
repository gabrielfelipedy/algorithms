import java.util.*;

public class quick_sort
{
	public static void main(String[] args)
	{
		int[] array = new int[10];
		int i;

		Scanner s = new Scanner(System.in);
		for(i = 0; i < 10; i++) {

			System.out.print("Type the " +(i+1)+"° element: ");
			array[i] = s.nextInt();
		}

		quicksort(array, 0, 9);

		for(i=0; i<10; i++) {

			System.out.println((i+1)+"° element: " + array[i]);
		}
	}

	public static void troca(int array[], int i, int j)
	{
		int aux = array[i];
		array[i] = array[j];
		array[j] = aux;
	}

	public static int particao(int array[], int p, int r)
	{
		int pivo, i, j;
		pivo = array[(p+r)/2];
		i = p - 1;
		j = r + 1;
		while(i < j) {

			do {

				j--;

			} while(array[j] > pivo);
			do {

				i++;

			} while(array[i] < pivo);
			if(i < j) troca(array, i, j);
		}
		return j;
	}

	public static void quicksort(int array[], int p, int r)
	{
		int q;
		if(p < r) {

			q = particao(array, p, r);
			quicksort(array, p, q);
			quicksort(array, q+1, r);
		}
	}
}

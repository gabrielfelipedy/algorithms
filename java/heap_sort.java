import java.util.*;

public class heap_sort
{
	static int[] array = new int[11];
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {

		int i, qtde;

		for(i = 1; i < 11; i++)
		{
			System.out.print("Type the "+i+"° element: ");
			array[i] = s.nextInt();
		}

		qtde=10;
		transforma_heap(qtde);
		ordena(qtde);

		for(i=1; i < 11; i++)
		{
			System.out.println(i+"° element: "+array[i]);
		}
	}

	public static void transforma_heap(int qtde)
	{
		int i, pai, aux;
		for(i=qtde/2; i >= 1; i--) {

			heap_fica(i, qtde);
		}
	}

	public static void heap_fica(int i, int qtde)
	{
		int f_esq, f_dir, maior, aux;
		maior = i;
		if(2*i + 1 <= qtde) {

			f_esq = 2*i+1;
			f_dir = 2*i;
			
			if(array[f_esq] >= array[f_dir] &&
					array[f_esq] > array[i])
			{
				maior = 2*i+1;

			} else if(array[f_dir] > array[f_esq] &&
					array[f_dir] > array[i])
			{
				maior = 2*i;
			}
		} else if(2*i <= qtde) {

			f_dir = 2*i;
			if(array[f_dir] > array[i]) {
				maior = 2*i;
			}
		}

		if(maior != i) {
			aux = array[i];
			array[i] = array[maior];
			array[maior] = aux;
			heap_fica(maior, qtde);
		}
	}

	public static void ordena(int qtde) {

		int i, aux, ultima_pos;
		for(i=qtde; i >=2; i--) {

			aux = array[1];
			array[1] = array[i];
			array[i] = aux;
			ultima_pos = i-1;
			heap_fica(1, ultima_pos);
		}
	}
}

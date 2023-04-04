import java.util.*;

public class insertion_sort
{
	public static void main(String[] args)
	{
		int[] array = new int[5];
		int i, j, eleito;

		Scanner s = new Scanner(System.in);

		for(i = 0; i < 5; i++)
		{
			System.out.print("Digite o "+(i+1)+" númeto: ");
			array[i] = s.nextInt();
		}

		//sorting
		for(i = 1; i < 5; i++)
		{
			eleito = array[i];
			j = i - 1;

			while(j >= 0 && array[j] > eleito)
			{
				array[j+1] = array[j];
				j--;
			}

			array[j+1] = eleito;
		}

		//printing
		for(i = 0; i < 5; i++)
		{
			System.out.println((i+1)+"° Elemento: "+array[i]);
		}
	}	
}

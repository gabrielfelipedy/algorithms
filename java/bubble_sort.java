import java.util.*;

public class bubble_sort
{
	public static void main(String[] args)
	{
		int[] array = new int[5];
		int n, i, aux;
		boolean troca;

		//Inserting data into the array
		//
		Scanner s = new Scanner(System.in);

		for(i = 0; i < 5; i++)
		{
			System.out.print("Digite o "+(i+1)+"° número: ");
			array[i] = s.nextInt();
		}

		//Sorting
		troca = true;
		n = 1;
		while(n <= 5 && troca)
		{
			troca = false;
			for(i = 0; i < 4; i++)
			{
				if(array[i] < array[i+1])
				{
					troca = true;
					aux = array[i];
					array[i] = array[i+1];
					array[i+1] = aux;
				}
			}
			n++;
		}

		//printing the array ordenated
		for(i = 0; i < 5; i++)
		{
			System.out.println((i+1)+"° Element: "+ array[i]);
		}
	}	
}

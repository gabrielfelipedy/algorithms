import java.util.*;

public class bubble_sort
{
	public static void main(String[] args)
	{
		int[] array = new int[5];
		int n, i, aux;

		//Inserting data into the array
		//
		Scanner s = new Scanner(System.in);

		for(i = 0; i < 5; i++)
		{
			System.out.print("Digite o "+(i+1)+"° número: ");
			array[i] = s.nextInt();
		}

		//Sorting
		
		for(n = 1; n < 5; n++)
		{
			for(i = 4; i >= n; i--)
			{
				if(array[i] < array[i-1])
				{
					aux = array[i];
					array[i] = array[i-1];
					array[i-1] = aux;
				}
			}
		}

		//printing the array ordenated
		for(i = 0; i < 5; i++)
		{
			System.out.println((i+1)+"° Element: "+ array[i]);
		}
	}	
}

import java.util.*;

public class selection_sort
{
	public static void main(String[] args)
	{
		int[] array = new int[5];

		int i, j, eleito, pos, menor;

		Scanner s = new Scanner(System.in);
		for(i = 0; i < 5; i++)
		{
			System.out.print("Type the "+(i+1)+"° Element: ");
			array[i] = s.nextInt();
		}
		
		//sort
		for(i = 0; i < 4; i++)
		{
			eleito = array[i];

			pos = i + 1;
			menor = array[pos];

			for(j = i+2; j < 5; j++)
			{
				if(array[j] < menor)
				{
					menor = array[j];
					pos = j;
				}
			}

			//trocar os dois
			if(menor < eleito)
			{
				array[i] = array[pos];
				array[pos] = eleito;
			}
		}

		//print
		for(i=0; i < 5; i++)
		{
			System.out.println((i+1)+"° Element: "+array[i]);
		}
	}
}

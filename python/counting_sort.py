#include <stdio.h>
#include <stdlib.h>

void counting_sort(int arr[], int size) {
    int max = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    
    int* contagem = (int*)calloc((max+1), sizeof(int));
    
    for(int i = 0; i < size; i++) 
        contagem[arr[i]]++;
    
    
    for(int i = 1; i <= size; i++) 
        contagem[i] += contagem[i-1];
    
    int* resultado = (int*)malloc(size * sizeof(int));
    
    for(int i = size - 1; i >= 0; i--) {
        resultado[contagem[arr[i] - 1]] = arr[i];
        contagem[arr[i]]--;
    }
    
    for(int i = 0; i < size; i++)
        arr[i] = resultado[i];
        
    free(resultado);
    free(contagem);
}

void print_array(int arr[], int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
        
    putchar('\n');
}

int main() {
    int array[5] = {0, 4, 2, 5, 6};
    counting_sort(array, 5);
    print_array(array, 5);
    
    return 0;
}

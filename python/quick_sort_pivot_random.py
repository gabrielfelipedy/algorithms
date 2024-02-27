import time
import random
import matplotlib.pyplot as plt

def partition(arr, begin, end):
	pivot = random.randrange(begin, end)

	maior_esquerda = begin
	menor_direita = end

	while(maior_esquerda < menor_direita):
		while(arr[maior_esquerda] < arr[pivot]):
			maior_esquerda += 1

		while(arr[menor_direita] > arr[pivot]):
			menor_direita -= 1

		if(maior_esquerda < menor_direita):
			temp = arr[maior_esquerda]
			arr[maior_esquerda] = arr[menor_direita]
			arr[menor_direita] = temp

			maior_esquerda += 1
			menor_direita -= 1
		
	return pivot

def quicksort(arr, left, right):
    if (left < right):
        pivotIndex = partition(arr, left, right)
        quicksort(arr, left, pivotIndex)
        quicksort(arr, pivotIndex + 1, right)


i = 1
times = []

while(i <= 1000):
	vet = []
	j = 0
	while(j < i):
		vet.append(random.randint(0, 1000))
		j += 1

	inicio = time.perf_counter()
	quicksort(vet, 0, len(vet) - 1)
	fim = time.perf_counter()

	total = fim - inicio
	times.append(total * 1000)

	i += 1

xs = [x for x in range(len(times))]
plt.plot(xs, times)
plt.show()

plt.close()
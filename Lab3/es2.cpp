#include <iostream>

void print_array_length(double array[]);

int main()
{
	const int n = 4;
	double a[n];
	
	std::cout << "La lunghezza dell'array: " << sizeof(a) / sizeof(double) << "\n";
	print_array_length(a);
	return 0;
}


// Qui la funzione non conosce la lunghezza dell'array, dato che passando come argomento l'array viene passato l'indirizzo della prima cella dell'array, quindi andando a perdere tutte le informazioni sulla lunghezza dell'array
void print_array_length(double *array){
	std::cout << "La lunghezza dell'array nella funzione: " << sizeof(array) / sizeof(double) << "\n";
}

#include <iostream>

void f();
void f_illegal();

int main()
{
	f();
	std::cout << "\n\n";
	f_illegal();
	return 0;
}

void f(){
	static const int n = 4;
	int a[n];
	static const int pos = 1;
	int *p = &a[pos];
	
	for (int i = -pos; i < n - pos; i++)
		p[i] = i + 1;
		
	for (int i = 0; i < n; i++)
		std::cout << a[i] << "\n";
}

// potrebbe creare problemi
void f_illegal(){ 
	static int n = 4;
	int a[n];
	static int pos = 2;
	int *p = &a[pos];
	
	for (int i = -pos; i < n; i++) //errore in esec
		p[i] = i;
}

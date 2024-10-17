#include <iostream>

void call_counter(void);

int main()
{
	call_counter();
	call_counter();
	call_counter();
	return 0;
}

void call_counter(void)
{
	static int count = 0;
	count++;
	
	std::cout << count << "\n";
}

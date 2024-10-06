#include <iostream>

int search(int nums[], int target, int length);

int main(){
    srand(time(NULL));
    
    const int n = 10;
    int nums[n];
    int x = 0;

    for (int i = 0; i < n; i++) {
        nums[i] = std::rand() % 100;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << nums[i];
        std::cout << " ";
    }

    std::cout << "\n";

    std::cout << "Cerca un numero: ";
    std::cin >> x;
    std::cout << search(nums, x, n);
    std::cout << "\n";

    
    
    return 0;
}

int search(int nums[], int target, int length){
    for (int i = 0; i < length; i++){
        if (nums[i] == target)
            return i;
    }

    return -1;
}
#include <stdio.h>

int get_size(void);
void print_grid(int n);
int main()
{
    // Get size of grid
    int n = get_size();
    // Print rows
    print_grid(n);
}















int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);
    return n;
}

void print_grid(int n)
{

}
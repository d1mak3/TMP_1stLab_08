#include <iostream>
#include <time.h>
#include "Stack.h"

/**
* max_in_stack for positive numbers and min_in_stack for negative numbers (obviously)
* This is for divided sort of positive and negative numbers(due to we can't use negative positions of array) 
*/

int max_in_stack(Stack stack_to_search)
{
    Stack temp_stack;
    int temp = 0;

    int max = stack_to_search.pop();
    temp_stack.push(max);

    int size = stack_to_search.size();

    for (int i = 0; i < size; ++i)
    {
        temp = stack_to_search.pop();
        temp_stack.push(temp);
        if (max < temp)
        {
            max = temp;
        }
    }

    size = temp_stack.size();

    for (int i = 0; i < size; ++i)
    {
        stack_to_search.push(temp_stack.pop());
    }

    return max;
}

int min_in_stack(Stack stack_to_search)
{
    Stack temp_stack;
    int temp = 0;

    int min = stack_to_search.pop();
    temp_stack.push(min);

    int size = stack_to_search.size();

    for (int i = 0; i < size; ++i)
    {
        temp = stack_to_search.pop();
        temp_stack.push(temp);
        if (min > temp)
        {
            min = temp;
        }
    }

    size = temp_stack.size();

    for (int i = 0; i < size; ++i)
    {
        stack_to_search.push(temp_stack.pop());
    }

    return min;
}

Stack sort(Stack stack_to_sort)
{
    int max = max_in_stack(stack_to_sort);
    int min = min_in_stack(stack_to_sort);

    int* positive_nums = new int[max + 1];
    int* negative_nums = new int[0];

    // fill arrays with zeros
    if (min < 0)
    {
        negative_nums = new int[min * -1 + 1];
        for (int i = 0; i < min * -1 + 1; ++i)
        {
            negative_nums[i] = 0;
        }
    }

    for (int i = 0; i < max + 1; ++i)
    {
        positive_nums[i] = 0;
    }    

    int size = stack_to_sort.size();
    for (int i = 0; i < size; ++i)
    {
        int pop = stack_to_sort.pop();
        if (pop < 0)
        {
            negative_nums[pop * -1] += 1;
        }
        else
        {
            positive_nums[pop] += 1;
        }
    }

    for (int i = min * -1; i >= 0; --i)
    {
        for (int j = 0; j < negative_nums[i]; ++j)
        {
            stack_to_sort.push(i * -1);
        }
    }

    for (int i = 0; i < max + 1; ++i)
    {
        for (int j = 0; j < positive_nums[i]; ++j)
        {
            stack_to_sort.push(i);
        }
    }

    return stack_to_sort;
}

Stack turn_over(Stack stack_to_turn_over)
{
    Stack inverted_stack;
    while (stack_to_turn_over.size() > 0)
        inverted_stack.push(stack_to_turn_over.pop());
    return inverted_stack;
}

int main()
{
    srand(time(0)); // for random
    std::cout << "Enter the count of numbers: \n";
    int size = 0;
    std::cin >> size;

    Stack stack_to_sort;
    for (int i = 0; i < size; ++i)
        stack_to_sort.push(-10 + rand() % 100); // we use limited numbers due to "beautiful" output

    Stack stack_to_output = stack_to_sort;

    std::cout << "\nOriginal stack: \n";
    while (stack_to_output.size() > 0)
        std::cout << stack_to_output.pop() << ' ';

    stack_to_sort = sort(stack_to_sort);
    stack_to_sort = turn_over(stack_to_sort);

    std::cout << "\nSorted stack: \n";
    while (stack_to_sort.size() > 0)
        std::cout << stack_to_sort.pop() << ' ';

	return 0;
}
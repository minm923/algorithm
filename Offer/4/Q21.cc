#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
    void pop()
    {
        if (!StoreStack.empty())
        {
            int StoreStackTop = StoreStack.top();
            int MinStackTop   = MinStack.top();

            if (StoreStackTop == MinStackTop)
            {
                MinStack.pop();                                
            }

            StoreStack.pop();
        }
    }

    void push(int n)
    {
        if (StoreStack.empty()) 
        {
            StoreStack.push(n);
            MinStack.push(n);
        }
        else
        {
            int MinStackTop   = MinStack.top();
            if (n <= MinStackTop)
            {
                MinStack.push(n);
            }

            StoreStack.push(n);
        }
    }

    int min()
    {
        return (!MinStack.empty()) ? MinStack.top() : 0;
    }


private:
    stack<int> StoreStack;
    stack<int> MinStack;
};

int main(int argc, char* argv[])
{
    MinStack ms;
    ms.push(5);
    ms.push(3);
    ms.push(2);
    ms.push(8);

    return 0;
}

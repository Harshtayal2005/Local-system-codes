#include <iostream>
#include <stack>
using namespace std;

class queue
{
public:
    stack<int> input;
    stack<int> output;
    int peekEle = -1;

    void push(int x)
    {
        if (input.empty())
        {
            peekEle = x;
        }

        input.push(x);
    }

    int pop()
    {

        if (output.empty())
        {

            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        int val = output.top();
        output.pop();
        return val;
    }

    int peek()
    {
        if (output.empty())
        {
            return peekEle;
        }

        return output.top();
    }

    bool isEmpty()
    {
        if (input.empty() && output.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    queue *q = new queue();
    q->push(1);
    q->push(2);
    cout << q->peek() << endl;
    cout << q->pop() << endl;
    cout << q->peek() << endl;
    return 0;
}
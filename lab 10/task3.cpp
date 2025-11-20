#include <iostream>
using namespace std;

struct Task
{
    string task;
    int priority;
};

class maxHeap
{
    Task *heap;
    int max;
    int size;

    int parent(int i) {return (i - 1) / 2;}
    int left(int i) {return 2 * i + 1;}
    int right(int i) {return 2 * i + 2;}

    public:
        maxHeap(int m) 
        {
            size = 0;
            max = m;
            heap = new Task[max];
        }

        void heapify(int i) 
        {
            int l = left(i), r = right(i);
            int largest = i;

            if (l < size && heap[l].priority > heap[largest].priority) 
            {
                largest = l;
            }

            if (r < size && heap[r].priority > heap[largest].priority)
            { 
                largest = r;
            }

            if (largest != i) 
            {
                swap(heap[i], heap[largest]);
                heapify(largest);
            }
        }

        Task removeMax() 
        {
            if (size <= 0) 
            {
                cout << "Heap empty!\n";
                return {"", -1};
            } 

            Task root = heap[0];
            heap[0] = heap[size-1];
            size--;
            heapify(0);
            return root;
        }

        void insert(Task t)
        {
            if (size >= max)
            {
                cout << "Heap full!\n";
                return;
            }     
            
            int i = size;    
            heap[i] = t;
            size++;

             while (i != 0 && heap[parent(i)].priority < heap[i].priority) 
             {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

        void display() 
        {
            cout << "Current Max-Heap (Priority): ";
            for (int i = 0; i < size; i++) 
            {
                cout << heap[i].task << "(" << heap[i].priority << ") "; 
            }
            cout << endl;
        }
};

int main()
{
    maxHeap heap(10);
    heap.insert({"A", 5});
    heap.insert({"B", 3});
    heap.insert({"C", 8});
    heap.display();

    heap.removeMax();
    heap.display();

    heap.insert({"D", 6});
    heap.display();
    
    return 0;
}

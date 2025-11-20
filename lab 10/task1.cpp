#include <iostream>
using namespace std;

class minHeap
{
    int *heap;
    int max;
    int size;

    int parent(int i) {return (i - 1) / 2;}
    int left(int i) {return 2 * i + 1;}
    int right(int i) {return 2 * i + 2;}

    public:
        minHeap(int m) 
        {
            size = 0;
            max = m;
            heap = new int[max];
        }

        void insert(int p)
        {
            if (size >= max)
            {
                cout << "Heap full!\n";
                return;
            }     
            
            int i = size;    
            heap[i] = p;
            size++;

             while (i != 0 && heap[parent(i)] > heap[i]) 
             {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

        void display() 
        {
            cout << "Current Min-Heap (package priorities): ";
            for (int i = 0; i < size; i++) 
            {
                cout << heap[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    minHeap heap(5);
    heap.insert(1);
    heap.insert(3);
    heap.insert(4);
    heap.insert(5);
    heap.display();

    heap.insert(2);

    heap.display();

    return 0;
}

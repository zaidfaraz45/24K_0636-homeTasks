#include <iostream>
using namespace std;

class maxHeap
{
    int *heap;
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
            heap = new int[max];
        }

        void heapify(int i) 
        {
            int l = left(i), r = right(i);
            int largest = i;

            if (l < size && heap[l] > heap[largest]) 
            {
                largest = l;
            }

            if (r < size && heap[r] > heap[largest])
            { 
                largest = r;
            }

            if (largest != i) 
            {
                swap(heap[i], heap[largest]);
                heapify(largest);
            }
        }

        int removeMax() 
        {
            if (size <= 0) 
            {
                cout << "Heap empty!\n";
                return -1;
            } 

            int root = heap[0];
            heap[0] = heap[size-1];
            size--;
            heapify(0);
            return root;
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

             while (i != 0 && heap[parent(i)] < heap[i]) 
             {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

        void display() 
        {
            cout << "Current Max-Heap (Severity): ";
            for (int i = 0; i < size; i++) 
            {
                cout << heap[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    maxHeap heap(10);
    heap.insert(2);
    heap.insert(4);
    heap.insert(7);
    heap.insert(3);
    heap.display();
    heap.removeMax();
    heap.display();

    heap.insert(10);
    heap.display();

    heap.removeMax();
    heap.display();

    return 0;
}

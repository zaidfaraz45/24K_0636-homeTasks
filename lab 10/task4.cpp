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

        void heapify(int i) 
        {
            int l = left(i), r = right(i);
            int smallest = i;

            if (l < size && heap[l] < heap[smallest]) 
            {
                smallest = l;
            }

            if (r < size && heap[r] < heap[smallest])
            { 
                smallest = r;
            }

            if (smallest != i) 
            {
                swap(heap[i], heap[smallest]);
                heapify(smallest);
            }
        }

        int removeMin() 
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

             while (i != 0 && heap[parent(i)] > heap[i]) 
             {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

        void display() 
        {
            cout << "Current Min-Heap (Price): ";
            for (int i = 0; i < size; i++) 
            {
                cout << heap[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    minHeap heap(10);
    heap.insert(100);
    heap.insert(50);
    heap.insert(75);
    heap.insert(60);
    heap.display();
    
    heap.insert(55);
    heap.display();

    heap.removeMin();
    heap.display();

    return 0;
}

typedef struct Node {
    int cnt;
    char ch;
} Node;

void heapify(Node* heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size && heap[left]->cnt > heap[largest]->cnt)
            largest = left;
        if (right < size && heap[right]->cnt > heap[largest]->cnt)
            largest = right;
        if (largest != i) {
            Node* temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
        }
    }
}

char* longestDiverseString(int a, int b, int c) {
    int total = a + b + c;
    char* res = (char*)malloc(total + 1);
    int resPos = 0;

    Node nodes[3];
    Node* heap[3];
    int heapSize = 0;

    if (a > 0) {
        nodes[heapSize].cnt = a;
        nodes[heapSize].ch = 'a';
        heap[heapSize] = &nodes[heapSize];
        heapSize++;
    }
    if (b > 0) {
        nodes[heapSize].cnt = b;
        nodes[heapSize].ch = 'b';
        heap[heapSize] = &nodes[heapSize];
        heapSize++;
    }
    if (c > 0) {
        nodes[heapSize].cnt = c;
        nodes[heapSize].ch = 'c';
        heap[heapSize] = &nodes[heapSize];
        heapSize++;
    }
    heapify(heap, heapSize);

    while (heapSize > 0) {
        heapify(heap, heapSize);
        Node* x = heap[0];
        if (resPos >= 2 && res[resPos - 1] == x->ch &&
            res[resPos - 2] == x->ch) {
            if (heapSize < 2)
                break;
            Node* y = heap[1];
            res[resPos++] = y->ch;
            y->cnt--;
            if (y->cnt == 0) {
                heap[1] = heap[--heapSize];
            }
        } else {
            int use = 1;
            if (heapSize > 1 && x->cnt > heap[1]->cnt)
                use = 2;
            if (use > x->cnt)
                use = 1;
            for (int i = 0; i < use; ++i) {
                res[resPos++] = x->ch;
            }
            x->cnt -= use;
            if (x->cnt == 0) {
                heap[0] = heap[--heapSize];
            }
        }
    }
    res[resPos] = '\0';
    return res;
}

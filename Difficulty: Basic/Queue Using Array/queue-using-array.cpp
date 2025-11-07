class myQueue {
    int front,rear,capacity;
    vector<int> arr;
  public:
    myQueue(int n) {
        front=-1;
        rear=-1;
        capacity=n;
        arr.resize(n);
    }

    bool isEmpty() {
        return front==-1;
    }

    bool isFull() {
        return (rear+1)%capacity==front;
    }

    void enqueue(int x) {
        if(front==-1){
            front=0;
            rear=0;
            arr[0]=x;
        }
        else{
            if(isFull())return;
            rear=(rear+1)%capacity;
            arr[rear]=x;
        }
    }

    void dequeue() {
        if(isEmpty())return;
        if(front==rear){
            front=-1;
            rear=-1;
            return;
        }
        front=(front+1)%capacity;
    }

    int getFront() {
        return front==-1?front:arr[front];
    }

    int getRear() {
        return rear==-1?rear:arr[rear];
    }
};
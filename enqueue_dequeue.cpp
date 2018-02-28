#include <iostream>
#define MAXSIZE 100
using namespace std;

class queue{
	public:
	int myArr[MAXSIZE] = {0};
	int front = -1, rear = -1;
	void enqueue(int element){
		if ((front == 0 && rear == MAXSIZE - 1)||(rear == front - 1)){
			cout << "Overflow";
			return;
		}
		if (front == -1){
			front = 0;
		}
		rear = (rear +1)%MAXSIZE;
		myArr[rear] = element;
	}
	void dequeue(){
		if (front == -1){
			cout << "Empty queue";//underflow
			return;
		}
		if (front == rear){
			front = -1;
			rear = -1;
		}
		if (front == MAXSIZE-1){
			front = 0;
		}
		else{
			front++;
		}

	}
	void p(){
		cout << myArr[1];
	}
	void print_queue(){
		if (front == -1){
			cout << "Empty queue\n";
			return;
		}
		if (rear >= front){
			for (int i = front; i <= rear; i++){
				cout << myArr[i] << " ";
			}
		}
		else{
			for (int i = front; i <= MAXSIZE; i++){
				cout << myArr[i] << " ";
			}
			for (int i = 0; i <= rear; i++){
				cout << myArr[i] << " ";
			}

		}
		cout << "\n";
	}
};
int main(){
	queue myQueue; //takes input from user to enqueue, dequeue, or print the queue
	char choice;
	while (1){
		cout << "Press 'q' for exiting, 'p' for printing the queue, 'e' for enqueue operation and 'd' for dequeue opereation\n";
		cin >> choice;
		if (choice == 'q'){
			break;
		}
		if (choice == 'p'){
			myQueue.print_queue();
		}
		if (choice == 'e'){
			int element;
			cout << "Enter the element to be inserted\n";
			cin >> element;
			myQueue.enqueue(element);
		}
		if (choice == 'd'){
			myQueue.dequeue();
		}
	}
	//myQueue.p();
	/*queue A;
	A.enqueue(1);
	A.enqueue(2);
	A.enqueue(3);
	A.print_queue();*/
	return 0;

}

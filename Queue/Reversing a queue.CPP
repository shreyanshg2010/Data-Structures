Input : Q = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
Output :Q = [100, 90, 80, 70, 60, 50, 40, 30, 20, 10]

Input :[1, 2, 3, 4, 5]
Output :[5, 4, 3, 2, 1]




// CPP program to reverse a Queue 
#include <bits/stdc++.h> 
using namespace std; 

// Utility function to print the queue 
void Print(queue<int> Queue) 
{ 
	while (!Queue.empty()) { 
		cout << Queue.front() << " "; 
		Queue.pop(); 
	} 
} 

// Function to reverse the queue 
void reverseQueue(queue<int> Queue) 
{ 
	stack<int> Stack; 
	while (!Queue.empty()) { 
		Stack.push(Queue.front()); 
		Queue.pop(); 
	} 
	while (!Stack.empty()) { 
		Queue.push(Stack.top()); 
		Stack.pop(); 
	} 
} 

// Driver code 
int main() 
{ 
	queue<int> Queue; 
	Queue.push(10); 
	Queue.push(20); 
	Queue.push(30); 
	Queue.push(40); 
	Queue.push(50); 
	Queue.push(60); 
	Queue.push(70); 
	Queue.push(80); 
	Queue.push(90); 
	Queue.push(100); 

	reverseQueue(Queue); 
	Print(Queue); 
} 

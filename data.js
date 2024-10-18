class Queue {
    constructor() {
        this.items = [];
    }

    // Enqueues an element at the back of the queue
    enqueue(element) {
        this.items.push(element);
    }

    // Dequeues an element from the front of the queue
    dequeue() {
        if (this.isEmpty()) {
            return 'Queue is empty';
        }
        return this.items.shift(); // Removes the first element from the array
    }

    // Returns the front element of the queue
    front() {
        if (this.isEmpty()) {
            return 'Queue is empty';
        }
        return this.items[0];
    }

    // Checks if the queue is empty
    isEmpty() {
        return this.items.length === 0;
    }

    // Returns the size of the queue
    size() {
        return this.items.length;
    }

    // Clears the queue
    clear() {
        this.items = [];
    }

    // Prints the queue elements
    print() {
        console.log(this.items.join(' '));
    }
}

// Example usage:
const queue = new Queue();
queue.enqueue(1);
queue.enqueue(2);
queue.enqueue(3);
console.log('Queue after enqueuing 1, 2, 3:');
queue.print(); // Outputs: 1 2 3

console.log('Front element is:', queue.front()); // Outputs: 1
console.log('Dequeued element:', queue.dequeue()); // Outputs: 1
console.log('Queue after dequeuing:');
queue.print(); // Outputs: 2 3
console.log('Is queue empty?', queue.isEmpty()); // Outputs: false
console.log('Queue size:', queue.size()); // Outputs: 2

queue.clear();
console.log('Queue after clearing:');
queue.print(); // Outputs: (empty)

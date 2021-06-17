#queue demo

class Queue:

    def __init__(self,size):
        self.size = size
        self.queue = [0 for _ in range(size)]
        self.rear = 0
        self.front = 0

    def push(self,element):
        if not self.is_filled():
            self.rear = (self.rear + 1)% self.size
            self.queue[self.rear] = element
        else:
            return IndexError('Queue is filled')

    def pop(self):
        if not self.is_empty():
            self.front = (self.front + 1)% self.size
            return self.queue[self.front]
        else:
            return IndexError('Queue is empty.')

    def is_empty(self):
        return self.rear == self.front

    def is_filled(self):
        return (self.rear + 1) % self.size == self.front


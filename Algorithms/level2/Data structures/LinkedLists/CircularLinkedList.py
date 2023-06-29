class Node:
    def __init__(self, d, n=None):
        self.data = d
        self.next = n

    def set_next(self, d):
        self.next = d

    def get_next(self):
        return self.next

    def set_data(self, d):
        self.data = d

    def get_data(self):
        return self.data

    def to_string(self):
        return f"Node value {str(self.data)}"

class CircularLinkedList:
    def __init__(self, r=None):
        self.root = r
        self.size = 0

    def get_size(self):
        return self.size

    def add(self, d):
        if self.get_size() == 0:
            self.root = Node(d)
            self.root.set_next(self.root)
        else:
            new_node = Node(d, self.root.get_next())
            self.root.set_next(new_node)
        self.size += 1

    def remove(self, d):
        this_node = self.root
        prev_node = None

        while True:
            if this_node.get_data() == d:
                if prev_node:
                    prev_node.set_next(this_node.get_next())
                else :
                    while this_node.get_next() != self.root:
                        this_node = this_node.get_next()
                    this_node.set_next(self.root.get_next())
                    self.root = self.root.get_next()
                self.size -= 1
                return True # data removed
            elif this_node.get_next() == self.root:
                return False # data not found
            prev_node = this_node
            this_node = this_node.get_next()
    
    def find(self, d):
        this_node = self.root
        while True:
            if this_node.get_data() == d:
                return d
            elif this_node.get_next() == self.root:
                return False
            this_node = this_node.get_next()
    
    def print_list(self):
        print("Print List...")
        if self.root is None:
            return 
        this_node = self.root
        print(this_node.to_string())
        while this_node.get_next() != self.root:
            this_node = this_node.get_next()
            print(this_node.to_string())

def main():
    mylist = CircularLinkedList()
    mylist.add(5)
    mylist.add(8)
    mylist.add(12)
    print(mylist.remove(12))
    print(mylist.find(5))
    print(mylist.find(13))
    print(mylist.get_size())
    mylist.print_list()

if __name__ == "__main__":
    main()

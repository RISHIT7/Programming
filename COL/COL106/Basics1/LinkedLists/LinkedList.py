class Node:
    def __init__(self, d, n=None):
        self.data = d
        self.next = n

    def set_data(self, d):
        self.data = d

    def get_data(self):
        return self.data

    def set_next(self, d):
        self.next = d

    def get_next(self):
        return self.next

    def to_string(self):
        return f"The node is {self.data}"


class LinkedList:
    def __init__(self, r=None):
        self.root = r
        self.size = 0

    def get_size(self):
        return self.size

    def add(self, d):
        new_node = Node(d, self.root)
        self.root = new_node
        self.size += 1

    def remove(self, d):
        this_node = self.root
        prev_node = None

        while this_node:
            if this_node.get_data() == d:
                if prev_node:
                    prev_node.set_next(this_node.get_next())
                else :
                    self.root = this_node.get_next()
                self.size -= 1
                return True # data removed
            else :
                prev_node = this_node
                this_node = this_node.get_next()
        return False # data not found

    def find(self, d):
        this_node = self.root
        while this_node:
            if this_node.get_data() == d:
                return d
            elif this_node.get_next() == None:
                return None
            else :
                this_node = this_node.get_next()

    def print(self):
        if self.root is None:
            return 
        this_node = self.root
        print(this_node.to_string())
        while this_node.get_next():
            this_node = this_node.get_next()
            print(this_node.to_string())

def main():
    mylist = LinkedList()
    mylist.add(5)
    mylist.add(8)
    mylist.add(12)
    print(mylist.remove(12))
    print(mylist.find(5))
    print(mylist.find(13))
    print(mylist.get_size())
    mylist.print()

if __name__ == "__main__":
    main()

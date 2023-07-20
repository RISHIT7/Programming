# faster but requiers more memory
class Node:
    def __init__(self, d, n=None, p=None):
        self.data = d
        self.next = n
        self.previous = p

    def set_next(self, d):
        self.next = d

    def set_prev(self, d):
        self.previous = d

    def get_prev(self):
        return self.previous

    def get_next(self):
        return self.next

    def set_data(self, d):
        self.data = d

    def get_data(self):
        return self.data


class LinkedLists:
    def __init__(self, r=None):
        self.root = r
        self.size = 0

    def get_size(self):
        return self.size

    def add(self, d):
        new_node = Node(d, self.root)
        if self.root:
            self.root.set_prev(new_node)
        self.root = new_node
        self.size += 1

    def remove(self, d):
        this_node = self.root

        while this_node:
            if this_node.get_data() == d:
                next = this_node.get_next()
                prev = this_node.get_prev()

                if next:
                    next.set_prev(next)
                if prev:
                    prev.set_next(prev)
                else :
                    self.root = this_node
                self.size -= 1
                return True # data removed
            else :
                this_node = this_node.get_next()
        return False # data not found

    def find(self, d):
        this_node = self.root
        while this_node:
            if this_node.get_data() == d:
                return d
            elif this_node.get_next() == None:
                return None
            else:
                this_node = this_node.get_next()


mylist = LinkedLists()
mylist.add(5)
mylist.add(8)
mylist.add(12)
print(mylist.remove(12))
print(mylist.find(5))
print(mylist.find(13))
print(mylist.get_size())

class Stack:
	def __init__(self):
		self.len = 0
		self.stack = []
	
	def push(self, item):
		self.stack.append(item)
		self.len += 1

	def peek(self):
		if self.len != 0:
			return self.stack[-1]
		else:
			return "Error"

	def pop(self):
		if self.len != 0:
			self.len -= 1
			return self.stack.pop()
		else:
			return "Error"

	def is_empty(self):
		if self.len != 0:
			return False
		else:
			return True

	def __str__(self):
		string = ""
		for i in range(len(self.stack)-1, 0, -1):
			string += str(self.stack[i]) + " "
		string += str(self.stack[0])
		return string

	def __len__(self):
		return self.len
	
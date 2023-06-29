from stack import Stack

class SimpleCalculator:
	def __init__(self):
		# for storing the history we create a cache memory using the stack datatype
		cache = Stack()
		self.cache = cache
		self.history = []

	def evaluate_expression(self, input_expression):
		# creating a temporary stack for saving the expression
		temporary_storage = Stack()

		operators = ["+", "-", "/", "*"]

# ---------------- Storing the expression -------------------------

		index = 0
		while input_expression[index] not in operators: # checking for operators in the expression
			index += 1

		temporary_storage.push(input_expression[:index]) # pushing the first number in the stack
		try:
			temporary_storage.push(input_expression[index]) # pushing operator into stack
		except:
			return "Error"
		try:
			temporary_storage.push(input_expression[index+1:]) # pushing the seconnd number, at the same time checking if it exists
		except:
			return "Error"

# ------------------ extracting the values from the temporary stack -----------------

		# checking for presence of 2 numbers
		try:
			number_1 = float(temporary_storage.pop()) 
			operator = temporary_storage.pop()
			number_2 = float(temporary_storage.pop())
		except:
			self.cache.push((input_expression, "Error"))
			return "Error"

# ------------------ evaluating the expression ------------------

		if operator in operators: # checking for presence of operator
			if operator == "+":
				self.cache.push((input_expression, (number_2 + number_1)))
				return number_2 + number_1
			elif operator == "-":
				self.cache.push((input_expression, (number_2 - number_1)))
				return number_2 - number_1
			elif operator == "*":
				self.cache.push((input_expression, (number_2 * number_1)))
				return number_2*number_1
			elif operator == "/":
				self.cache.push((input_expression, (number_2 / number_1)))
				return number_2/number_1
		else:
			self.cache.push((input_expression, "Error"))
			return "Error"
		
	def get_history(self):
		# temporary list for returning the values
		while self.cache.is_empty() == False: # fetching the values for the Stack
			self.history.append(self.cache.pop())

		return self.history[::-1]
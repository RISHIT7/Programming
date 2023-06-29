from stack import Stack

class SimpleCalculator:
    def __init__(self):
        self.cache = []

    def evaluate_expression(self,input_expression):
        expression = input_expression.replace(" ", "")

        num_str = ""
        result = 0
        last_operator = "+"
        sign = 1

        for char in expression:
            if char.isdigit():
                num_str += char
            elif char == "+":
                result += sign * int(num_str)
                num_str = ""
                sign = 1
                last_operator = "+"
            elif char == "-":
                result += sign * int(num_str)
                num_str = ""
                sign = -1
                last_operator = "-"
            else:
                raise ValueError("Invalid expression")

        result += sign * int(num_str)
        self.cache.append((input_expression, result))
        return result

    def get_history(self):
        return self.cache
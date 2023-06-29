from simple_calculator import SimpleCalculator
from stack import Stack


class AdvancedCalculator(SimpleCalculator):
    def __init__(self):
        super().__init__()
        self.cache = []

    def evaluate_expression(self, input_expression):
        list_tokens = AdvancedCalculator.tokenize(self, input_expression)
        result = AdvancedCalculator.evaluate_list_tokens(self, list_tokens)
        return result
        
    def tokenize(self, input_expression):

        tokens = []

        if input_expression == "":
            return []

        if input_expression.strip().isdigit():
            return [int(input_expression.strip())]

        for i in range(len(input_expression)):
            ch = input_expression[i]

            if ch in "+-/*(){}":
                if input_expression[:i].strip().isdigit():
                    tokens.append(int(input_expression[:i].strip()))
                elif input_expression[:i].strip() != "":
                    tokens.append(input_expression[:i].strip())
                
                tokens.append(ch)

                tokens.extend(self.tokenize(input_expression[i+1:].strip()))
                break

        return tokens


    def check_brackets(self, list_tokens):
        stack = []

        for char in list_tokens:
            try:
                if char in ['(', '{'] and char == '{' and stack[-1] == '(':
                    return False
            except:
                pass
            if char in ['(', '{']:
                stack.append(char)

            elif char in [')', '}']:
                if not stack:
                    return False
                opening_bracket = stack.pop()
                if char == ')' and opening_bracket != '(':
                    return False
                elif char == '}' and opening_bracket == '(':
                    return False

        for i in range(len(list_tokens)):
            if list_tokens[i] == "{":
                list_tokens[i] = "("
            elif list_tokens[i] == "}":
                list_tokens[i] = ")"


        if stack:
            return False

        return True

    def evaluate_list_tokens(self, list_tokens):
        if AdvancedCalculator.check_brackets(self, list_tokens):
            pass
        else:
            return "Error"
        def infix_to_postfix(expression):
            operator_precedence = {'+': 1, '-': 1, '*': 2, '/': 2}
            output = []
            operator_stack = []

            for token in expression:
                if str(token) not in "+-*/()}{":
                    output.append(token)
                elif token == '(':
                    operator_stack.append(token)
                elif token == ')':
                    while operator_stack and operator_stack[-1] != '(':
                        output.append(operator_stack.pop())
                    if operator_stack and operator_stack[-1] == '(':
                        operator_stack.pop()
                elif token in operator_precedence:
                    while operator_stack and operator_stack[-1] != '(' and operator_precedence[token] <= operator_precedence.get(operator_stack[-1], 0):
                        output.append(operator_stack.pop())
                    operator_stack.append(token)

            while operator_stack:
                output.append(operator_stack.pop())

            return evaluate_postfix(output)

        def evaluate_postfix(expression):
            stack = []

            for token in expression:
                if str(token) not in "+-/*)(}{":
                    stack.append(int(token))
                elif token in ['+', '-', '*', '/']:
                    operand2 = stack.pop()
                    operand1 = stack.pop()
                    result = perform_operation(token, operand1, operand2)
                    stack.append(result)

            return stack[0] if stack else None

        def perform_operation(operator, operand1, operand2):
            if operator == '+':
                return operand1 + operand2
            elif operator == '-':
                return operand1 - operand2
            elif operator == '*':
                return operand1 * operand2
            elif operator == '/':
                return operand1 / operand2
        return infix_to_postfix(list_tokens)

    def get_history(self):
        return self.cache
    
clac = AdvancedCalculator()
k = clac.tokenize("(2+3)")
print(clac.evaluate_list_tokens(k))
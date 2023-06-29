from simple_calculator import SimpleCalculator
from stack import Stack


class AdvancedCalculator(SimpleCalculator):
    def __init__(self):
        SimpleCalculator.__init__(self)
        cache = Stack()
        self.cache = cache  # creating the cache memory
        self.input_expression = None

    def error_handling(self, input_list):

        # to convert curly brackets to round brackets for ease of calculation after checking for their validity
        for i, el in enumerate(input_list):
            if el == "{":
                input_list[i] = "("
            elif el == "}":
                input_list[i] = ")"

        # to check for operators and brackets we create lists
        operators = ['+', '-', '*', '/']
        brackets = ['(', ')']

        # -------------- Error handling --------------------------

        # to check if brackets are appropriate
        if AdvancedCalculator.check_brackets(self, input_list):
            pass
        else:
            return False

        # to check if empty brackets are present
        for i in range(len(input_list)-1):
            if input_list[i] == '(' and input_list[i+1] == ')':
                return False

        # to check for cases like "2 3" or " 2 3 + 3"
        for i in range(len(input_list)):
            if input_list[i] not in operators and input_list[i] not in brackets:
                for j in range(i+1, len(input_list)):
                    if input_list[j] in operators:
                        break
                    if input_list[j] not in operators and input_list[j] not in brackets:
                        return False

        # return True if no errors found
        return True

    def notGreater(self, rest, i):
        # to check the precedence of the operators
        precedence = {'+': 1, '-': 1, '*': 2, '/': 2}
        try:
            a = precedence[i]
            b = precedence[rest.peek()]
            return True if a <= b else False
        except KeyError:
            return False

    def infix_to_postfix(self, input_tokens):
        if AdvancedCalculator.check_brackets(self, input_tokens):
            pass
        else:
            return "Error"
        output = Stack()  # stack to store the final output
        rest = Stack()  # stack to store the brackets and the operators

        operators = ["+", "-", "*", "/"]  # list to check for operators
        brackets = ["(", "{", "}", ")"]  # list to check for brackets

        # to convert curcly brackets to round brackets for ease of calculation after checking for their validity
        for i, el in enumerate(input_tokens):
            if el == "{":
                input_tokens[i] = "("
            elif el == "}":
                input_tokens[i] = ")"

        for el in input_tokens:
            # incase we encounter operands
            if el not in operators and el not in brackets:
                output.push(el)

            # if we encounter brackets
            elif el == "(":
                rest.push(el)

            elif el == ")":
                while len(rest) != 0 and rest.peek() != "(":
                    a = rest.pop()
                    output.push(a)
                if len(rest) != 0 and rest.peek() != "(":
                    return "Error"
                else:
                    rest.pop()

            # if we encounter operators
            else:
                # checking precedence
                while len(rest) != 0 and AdvancedCalculator.notGreater(self, rest, el):
                    output.push(rest.pop())
                rest.push(el)

        while len(rest) != 0:
            output.push(rest.pop())

        return output  # returns the postfix of the operation

    def evaluate_expression(self, input_expression):
        self.input_expression = input_expression
        input_list = AdvancedCalculator.tokenize(
            self, input_expression)  # tokenize the expression
        # then call evalute_list_token function
        return AdvancedCalculator.evaluate_list_tokens(self, input_list)

    def tokenize(self, input_expression):
        token_list = []  # list created to store all the tokens

        # --------------------- lists that we want too check ---------------------

        operators = ["+", "-", "/", "*"]
        brackets = ["{", "(", ")", "}"]
        space = " "

        # -------------------- appending tokens into the list --------------------

        # for marking the left index and right index of potential numbers
        index_right = index_left = 0
        while index_right < len(input_expression):
            if input_expression[index_right] in operators:
                # pushing the operators in
                token_list.append(input_expression[index_right])
                index_right += 1
            elif input_expression[index_right] in brackets:
                # pushing the brackets in
                token_list.append(input_expression[index_right])
                index_right += 1
            elif input_expression[index_right] == space:
                index_right += 1  # countinuing on the spaces
            else:
                index_left = index_right
                while index_left < len(input_expression) and input_expression[index_left] not in brackets and input_expression[index_left] not in operators and input_expression[index_left] != " ":
                    index_left += 1  # finding the length of number
                number = input_expression[index_right:index_left]
                try:
                    token_list.append(float(number))  # pushing the number in
                except:
                    pass
                index_right = index_left  # restting the index_right

        return token_list

    def check_brackets(self, list_tokens):

        # --------- Creating a stack to hold all the brackets ----------------

        brackets_stack = Stack()
        for token in list_tokens[::-1]:
            if token in ["{", "}", "(", ")"]:
                # to push all the brackets in the stack in the right order
                brackets_stack.push(token)

        # ----------------- Checking validity ----------------------

        round_bracket = 0  # maintaining counters for braackets
        curly_bracket = 0
        round_presence = False  # checking if there is a curly bracket inside a round bracket
        # string the length required for the iterations
        length_stack = len(brackets_stack)

        for _ in range(length_stack):

            if brackets_stack.peek() == "(":
                round_bracket += 1
                round_presence = True  # storing that a round bracket has been opened

            elif brackets_stack.peek() == "{":
                if round_presence == False:  # checking if curly bracket is in round bracket
                    curly_bracket += 1
                else:
                    return False

            elif brackets_stack.peek() == ")":
                round_bracket -= 1
                round_presence = False  # storing that a round bracket has been closed

            elif brackets_stack.peek() == "}":
                if round_presence == False:  # checking if curly bracket is in round bracket
                    curly_bracket -= 1
                else:
                    return False

            if round_bracket < 0 or curly_bracket < 0:  # for cases where a bracket has been closed without opening
                return False

            brackets_stack.pop()

        if round_bracket == 0 and curly_bracket == 0:
            return True

        return False

    def evaluate_list_tokens(self, list_tokens):

        # storing list of operators
        operators = ['+', '-', '*', '/']

        # ----------------- Checking for any errors in the input ------------------------

        if AdvancedCalculator.error_handling(self, list_tokens):
            pass
        else:
            return "Error"

        # ------------------------- Evaluation ----------------------------------

        # postfix of the calculation is postfis_reversed
        postfix = Stack()
        postfix_reversed = AdvancedCalculator.infix_to_postfix(
            self, list_tokens)
        output = Stack()  # output stack of the operands
        postfix = Stack()  # reversed order of the postfix
        while len(postfix_reversed) != 0:
            # populating postfix through postfix_reversed
            postfix.push(postfix_reversed.pop())
        while len(postfix) != 0:

            # if element is a number
            if postfix.peek() not in operators:
                # we push the number in output stack
                output.push(postfix.pop())
            # incase it is an operator
            else:
                # try to call for the last two integers
                try:
                    B = float(output.pop())
                    A = float(output.pop())
                # if not integers meaning it is a case like "++" or "()" for which we return "Error"
                except:
                    return "Error"
                # if not error, we compute the value
                C = postfix.pop()
                if C == '+':
                    output.push(A+B)
                if C == '-':
                    output.push(A-B)
                if C == '*':
                    output.push(A*B)
                if C == '/':
                    output.push(A/B)
                # store the value in output
        # after iteration we store the last value i.e. the result in cache and return it
        result = output.pop()
        self.cache.push((self.input_expression, result))
        return result

    def get_history(self):
        # temporary list for returning the values
        while self.cache.is_empty() == False:  # fetching the values for the Stack
            self.history.append(self.cache.pop())
        print(self.history)
        return self.history


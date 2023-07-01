from simple_calculator import SimpleCalculator
from advanced_calculator import AdvancedCalculator

class SimpleUI:
    def __init__(self):
        self.use_simple_calculator = True
        self.simple_calc = SimpleCalculator()
        self.advanced_calc = AdvancedCalculator()
        self.startup()

    def startup(self):
        while True:
            if self.use_simple_calculator:
                print('--Simple Calculator-- \nInput 1 to switch to Advanced Calculator')
            else:
                print('--Advanced Calculator-- \nInput 1 to switch to Simple Calculator')
            print('Input 2 to calculate an expression')
            print('Input 3 to print history')
            print('Input 4 to exit')
            print('Enter your input(1/2/3/4): ', end='')
            inp = int(input())
            if inp==4:
                break
            if inp==1:
                self.use_simple_calculator = not self.use_simple_calculator
                print()
                continue
            if inp==3:
                self.history_handler()
            if inp==2:
                self.calculate_handler()
               
    def calculate_handler(self):
        print('Enter an expression: ', end='')
        inp = input()
        if self.use_simple_calculator:
            output = self.simple_calc.evaluate_expression(inp)
        else:
            output = self.advanced_calc.evaluate_expression(inp)
        print('Output:', str(output))
        print('Enter to continue')
        input()

    def history_handler(self):
        if self.use_simple_calculator:
            history = self.simple_calc.get_history()
        else:
            history = self.advanced_calc.get_history()
        if len(history) == 0:
            print("---Empty---")
        for exp, out in history:
            print('Q: ' + str(exp))
            print('A: ' + str(out) + '\n')
        print('Enter to continue')
        input()

SimpleUI()
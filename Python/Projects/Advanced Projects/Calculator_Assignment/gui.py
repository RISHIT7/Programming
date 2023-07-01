import tkinter as tk
from simple_calculator import SimpleCalculator
from advanced_calculator import AdvancedCalculator

class GUI:
    def __init__(self):
        self.use_simple_calculator = True
        self.simple_calc = SimpleCalculator()
        self.advanced_calc = AdvancedCalculator()
        self.startup()

    def startup(self):
        win = tk.Tk()
        win.geometry("750x270")
        win.title("COL100 Calculator")
        
        f0, f1, f2 = tk.Frame(), tk.Frame(), tk.Frame()

        self.label = tk.Label(
            text='Simple Calculator',
            master=f0,
            fg="white",
            bg="black",
            height=2,
            width=28
        )
        self.switch = tk.Button(
            text="Switch To: Advanced Calculator",
            width=25,
            height=1,
            master=f0,
            bg='white'
        )
        self.label.pack(side='top')
        self.switch.pack(side='top')

        self.textbox = tk.Entry(
            master=f1,
            width=30
        )
        calc = tk.Button(
            text="Calculate!",
            width=10,
            height=1,
            master=f1,
            bg='green'
        )
        reset = tk.Button(
            text='Reset',
            width=10,
            height=1,
            master=f1,
            bg='red'
        )
        self.textbox.pack(side='left')
        calc.pack(side='left')
        reset.pack(side='left')

        hist = tk.Button(
            text='Fetch\nHistory',
            width=5,
            height=2,
            master=f2,
            bg='white'
        )
        f3 = tk.Frame(f2)
        scroll = tk.Scrollbar(f3)
        self.display = tk.Text(
            master=f3,
            relief=tk.RIDGE,
            width=30,
            height=5,
            yscrollcommand=scroll.set
        )
        self.display.insert(tk.END, "---Empty---")

        hist.pack(side='left')

        scroll.pack(side='right', fill='y')
        scroll.config(command=self.display.yview)
        self.display.pack()
        f3.pack(side='left')

        f0.pack(side='top', expand=True)
        f1.pack(side='top', expand=True)
        f2.pack(side='top', expand=True)

        self.switch.bind("<Button-1>", self.switch_handler)
        calc.bind("<Button-1>", self.calculate_handler)
        reset.bind("<Button-1>", self.reset_handler)
        hist.bind("<Button-1>", self.history_handler)

        win.mainloop()

    def switch_handler(self, event):
        if self.use_simple_calculator:
            self.label.config(text='Advanced Calculator')
            self.switch.config(text='Switch to: Simple Calculator')
            self.use_simple_calculator = False
        else:
            self.label.config(text='Simple Calculator')
            self.switch.config(text='Switch to: Advanced Calculator')
            self.use_simple_calculator = True

    def calculate_handler(self, event):
        inp = self.textbox.get()
        if self.use_simple_calculator:
            output = self.simple_calc.evaluate_expression(inp)
        else:
            output = self.advanced_calc.evaluate_expression(inp)
        self.textbox.delete(0, tk.END)
        self.textbox.insert(0, str(output))

    def reset_handler(self, event):
        self.textbox.delete(0, tk.END)

    def history_handler(self, event):
        if self.use_simple_calculator:
            history = self.simple_calc.get_history()
        else:
            history = self.advanced_calc.get_history()
        self.display.delete('1.0', tk.END)
        if len(history) == 0:
            self.display.insert(tk.END, "---Empty---")
        for exp, out in history:
            self.display.insert(tk.END, 'Q: ' + str(exp) + '\n')
            self.display.insert(tk.END, 'A: ' + str(out) + '\n\n')

GUI()
import random

MAX_LINES = 3
MAX_BET = 100
MIN_BET = 1

ROWS = 3
COLS = 3

symbolCount = {
    "A": 2,
    "B": 4,
    "C": 6,
    "D": 8,
}

symbolValue = {
    "A": 5,
    "B": 4,
    "C": 3,
    "D": 2,
}


def checkWinnings(columns, lines, bet, values):
    winnings = 0
    win_line = []
    for line in range(lines):
        symbol = columns[0][line]
        for column in columns:
            symbol_to_check = column[line]
            if symbol != symbol_to_check:
                break
        else:
            winnings += values[symbol]*bet
            win_line.append(line + 1)
    return winnings, win_line


def getSoltMachineSpin(rows, cols, symbols):
    allSymbols = []
    for symbol, symbolCount in symbols.items():
        for _ in range(symbolCount):
            allSymbols.append(symbol)

    columns = []
    for _ in range(cols):
        column = []
        currentSymbols = allSymbols[:]
        for _ in range(rows):
            value = random.choice(allSymbols)
            currentSymbols.remove(value)
            column.append(value)
        columns.append(column)
    return columns


def printSoltMachine(columns):
    for row in range(len(columns[0])):
        for i, column in enumerate(columns):
            if i != len(columns)-1:
                print(column[row], end="|")
            else:
                print(column[row], end="")
        print()


def deposit():
    while True:
        amount = input("What would you like to deposit? $")
        if amount.isdigit():
            amount = int(amount)
            if amount > 0:
                break
            else:
                print("amount must be greater than 0")
        else:
            print("Please enter a number")

    return amount


def getNumberofLines():
    while True:
        lines = input(f"enter the number of lines to be on (1-{MAX_LINES}) ")
        if lines.isdigit():
            lines = int(lines)
            if 1 <= lines <= MAX_LINES:
                break
            else:
                print("Plese enter a valid number of lines")
        else:
            print("Enter a number")
    return lines


def getBet():
    while True:
        amount = input("What would you like to bet on each line? $")
        if amount.isdigit():
            amount = int(amount)
            if MIN_BET <= amount <= MAX_BET:
                break
            else:
                print(f"Amount must be between (${MIN_BET} - ${MAX_BET})")
        else:
            print("Please enter a number")

    return amount

def spin(balance):
    lines = getNumberofLines()
    while True:
        bet = getBet()
        total_bet = bet*lines

        if total_bet > balance:
            print(
                f"You don not have enough to bet that amount, your current balance is ${balance}")
        else:
            break
    print(
        f"You are betting ${bet} on {lines} lines. Total bet is equal to ${bet * lines}")
    print(f"Now you balance is {balance - total_bet}")

    slots = getSoltMachineSpin(ROWS, COLS, symbolCount)
    printSoltMachine(slots)
    winnings, win_lines = checkWinnings(slots, lines, bet, symbolValue)
    if win_lines:
        print(f"You won ${winnings}.")
        print(f"You won on lines:", *win_lines)
    else:
        print("No luck this time, try again!")
    return winnings - total_bet

def main():
    balance = deposit()
    while True:
        print(f"Current balance is ${balance}")
        ans = input("Press enter to play (Q to quit) ")
        if ans == "Q":
            break
        balance += spin(balance)
    
    print(f"You left with ${balance}")


main()

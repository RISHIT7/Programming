import random

user_points = 0
comp_points = 0

def main(user_points, comp_points):
    keylist = ["Rock", "Paper", "Scissors"]
    perm = input("Do you want to continue the game?(Y/N): ").lower()
    while perm == "y":
        Input = input("Enter your choice here(rock/paper/scissors): ")
        n = random.randint(0, 2)
        comp_choice = keylist[n].lower()
        user_choice = Input
        print(f"The computer chose {comp_choice}")

        win = {"rock": "paper", "scissors": "rock", "paper": "scissors"}
        loose = {"rock": "scissors", "scissors": "paper", "paper": "rock"}

        if win[comp_choice] == user_choice:
            print("You won!")
            user_points += 1
        elif loose[comp_choice] == user_choice:
            print("The computer won this one")
            comp_points += 1
        else :
            print("Draw")

        perm = input("Do you want to continue the game?(Y/N): ").lower()
    print(f"The final scores are computer = {comp_points} and  user = {user_points}")
if __name__ == "__main__":
    main(user_points, comp_points)
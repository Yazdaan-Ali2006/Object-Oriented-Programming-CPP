import tkinter as tk
import random

# score
user_score = 0
computer_score = 0

choices = {1: "Rock 🪨", -1: "Paper 📄", 0: "Scissor ✂"}

def play(user):

    global user_score, computer_score

    computer = random.choice([1,-1,0])

    player_choice_label.config(text=f"You chose: {choices[user]}")
    computer_choice_label.config(text=f"Computer chose: {choices[computer]}")

    if user == computer:
        result_label.config(text="It's a Draw 🤝")

    elif (user == 1 and computer == 0) or \
         (user == -1 and computer == 1) or \
         (user == 0 and computer == -1):

        result_label.config(text="You Win 🎉")
        user_score += 1

    else:
        result_label.config(text="Computer Wins 💻")
        computer_score += 1

    score_label.config(text=f"Score  |  You: {user_score}  Computer: {computer_score}")


def reset_game():

    global user_score, computer_score
    user_score = 0
    computer_score = 0

    score_label.config(text="Score  |  You: 0  Computer: 0")
    player_choice_label.config(text="")
    computer_choice_label.config(text="")
    result_label.config(text="Game Reset")


# window
root = tk.Tk()
root.title("Rock Paper Scissors Game")
root.geometry("500x420")
root.configure(bg="#1e1e2f")

# title
title = tk.Label(
    root,
    text="Rock Paper Scissors",
    font=("Arial",24,"bold"),
    bg="#1e1e2f",
    fg="white"
)
title.pack(pady=15)

# score
score_label = tk.Label(
    root,
    text="Score  |  You: 0  Computer: 0",
    font=("Arial",14),
    bg="#1e1e2f",
    fg="#f1c40f"
)
score_label.pack(pady=5)

# choices display
player_choice_label = tk.Label(
    root,
    text="",
    font=("Arial",13),
    bg="#1e1e2f",
    fg="white"
)
player_choice_label.pack()

computer_choice_label = tk.Label(
    root,
    text="",
    font=("Arial",13),
    bg="#1e1e2f",
    fg="white"
)
computer_choice_label.pack(pady=5)

# result
result_label = tk.Label(
    root,
    text="Choose your move",
    font=("Arial",16,"bold"),
    bg="#1e1e2f",
    fg="#2ecc71"
)
result_label.pack(pady=15)

# buttons frame
frame = tk.Frame(root,bg="#1e1e2f")
frame.pack(pady=10)

rock_btn = tk.Button(
    frame,
    text="🪨 Rock",
    width=12,
    height=2,
    font=("Arial",12),
    bg="#3498db",
    fg="white",
    command=lambda:play(1)
)
rock_btn.grid(row=0,column=0,padx=10)

paper_btn = tk.Button(
    frame,
    text="📄 Paper",
    width=12,
    height=2,
    font=("Arial",12),
    bg="#2ecc71",
    fg="white",
    command=lambda:play(-1)
)
paper_btn.grid(row=0,column=1,padx=10)

scissor_btn = tk.Button(
    frame,
    text="✂ Scissor",
    width=12,
    height=2,
    font=("Arial",12),
    bg="#e74c3c",
    fg="white",
    command=lambda:play(0)
)
scissor_btn.grid(row=0,column=2,padx=10)

# reset button
reset_btn = tk.Button(
    root,
    text="Reset Game 🔄",
    font=("Arial",12),
    bg="#f39c12",
    fg="white",
    command=reset_game
)
reset_btn.pack(pady=20)

root.mainloop()
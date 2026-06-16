import random
'''
rock=1
paper=-1
scissor=0
'''
print( "|Select \"r\" for rock \"s\" for scissor and \"p\" for paper|")
computer=random.choice([-1,0,1])
youstr=input("Enter your choice ").lower()
youdict={"r":1,"p":-1,"s":0}
you=youdict[youstr]
reversedict={1:"Rock",-1:"Paper",0:"Scissor"}
print(f"You chose {reversedict[you]} and computer chose {reversedict[computer]}")
if(computer==you):
    print("The game is draw")
else:
    if(computer==1 and you==-1):
        print("You Win!")
    elif(computer==-1 and you==1):
        print("You lose!")
    elif(computer==-1 and you==1):
        print("You lose!")
    elif(computer==1 and you==0):
        print("You Lose")
    elif(computer==0 and you==1):
        print("You Win!") 
    elif(computer==0 and you==-1):
        print("You Lose!")             
    elif(computer==-1 and you==0):
        print("You Win!")
    else:
        print("Something Went Wrong")               

       
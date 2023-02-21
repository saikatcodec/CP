a=int(input("write number of member group a "))
b=int(input("write number of member group b "))
c=input("write new group name ")
l=[]
if a>b:

    for i in range(a):
        x=input("Enter group a member's name ")
        l.append(x)
else:        
    for i in range(b):
        x=input("Enter group b member's name ")    
        l.append(x)
        
print(c,l)
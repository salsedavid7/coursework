#from pdb import set_trace
x = input("Addition calculator: ")
x.split()
i = 0
sum = 0
t = [int(i) for i in x.split()]
for i in t:
    sum += int(i)
    #set_trace()
    i += 1
print(sum)

#'1 2 3 4' --> '1', '2', '3', '4'] --> [int(i) for i in x.split()] = [1, 2, 3, 4]
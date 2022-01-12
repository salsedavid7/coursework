phrase = input("Enter sentence: ")
numIterations = int(input("Enter how many times you would like this sentence repeated: "))
filename = open("CompletedPunishment.txt","w")
for i in range(0, numIterations):
    filename.write(phrase)
    filename.write("\n")
filename.close()
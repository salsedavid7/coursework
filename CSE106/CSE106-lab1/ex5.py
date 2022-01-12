import json

def writeToFile(dataDict, fileName):
    with open(fileName, 'w') as textFile:
        json.dump(dataDict, textFile)

if __name__ == '__main__':
    studentDataDict = dict()     
    fileName = input("\nPlease enter text file for grades: ")

    #opening file 
    try:
        with open(fileName) as f:
            studentDataDict = json.load(f)        
    except:
        print("\nFailed to open "+ fileName + "\n")     
        exit() 

    print("\nData successfully loaded from " + fileName + "\n")
    print("Menu: ")           
    while True:
        print("1. Add new student \n2. Search a student grade \n3. Edit grade \n4. Delete grade \n5. Exit")
        userChoice = input("\nWhat would you like to do?: ")

        if userChoice == "1": #adds new student to dictionary
            studentName = input("\nEnter student name to add: ")

            if studentName in studentDataDict: #checks if studentname already exists
                print("\nStudent with this name already exists, please enter a different name\n")

            else:
                grade = float(input("\nEnter student grade: "))
                studentDataDict[studentName] = grade      
                writeToFile(studentDataDict, fileName)
                print("\nNew Student got added to dictionary data, and text file "+fileName+" got updated.")

        #search student
        elif userChoice == "2":
            studentName = input("\nEnter student name to find: ")
            if studentName not in studentDataDict: #no student exists with this name
                print("\nNo student with this name was found. Please provide a valid student name\n")
            else:
                print(f"\nStudent Name: {studentName}\tGrade: {studentDataDict[studentName]}\n")

        #edit grade
        elif userChoice == "3":
            studentName = input("\nEnter student name to update: ")
            if studentName not in studentDataDict:
                print("\nNo student with this name was found. Please provide a valid student name\n")

            else:
                grade = float(input(f"\nEnter new student grade for {studentName}: "))
                studentDataDict[studentName] = grade      
                writeToFile(studentDataDict, fileName)
                print(f"\nGrade for student {studentName} has been updated.")

        #delete grade
        elif userChoice == "4":
            studentName = input("\nEnter student name to delete: ")
            if studentName not in studentDataDict:
                print("\nNo student with this name in the dictionary was found. Please provide a valid student name\n")
            else:
                studentDataDict.pop(studentName)        
                writeToFile(studentDataDict, fileName)
                print(f"\nGrade for student {studentName} has been deleted.")

        #exit program
        elif userChoice == "5":
            writeToFile(studentDataDict, fileName)
            print("\nProgram exited. Text file has been updated.")
            break

        else:
            print("\nInvalid input, please try again.\n")                    
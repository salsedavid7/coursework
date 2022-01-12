text_file = open('PythonSummary.txt', 'r')
text = text_file.read()
text = text.lower()
words = text.split()
words = [word.strip(".,!;()[]?'") for word in words]
words = [word.replace("'s", '') for word in words]
words = [word.replace("-related", '') for word in words]
userWord = input("Enter word you want to search in file: ")
word = userWord.lower()
k = 0
with text_file as f:      
    for i in words:
        if(i == word):
            k = k + 1

print("The word", userWord , "occurs" , k , "times")
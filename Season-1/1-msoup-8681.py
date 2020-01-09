#Coding Challenge - Longest word in a string
usr_input=input("Enter in your string\n")
x=[]
for ele in usr_input:
    if ord(ele)<=63 and ord(ele)>=33:
        continue
    else:
        x.append(ele)
zed=''.join(x)
splitString=zed.split()
sortedList=sorted(splitString,key=len,reverse=True)
print(" ".join(sortedList))
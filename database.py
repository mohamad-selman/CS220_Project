from os.path import dirname

f = open(dirname(__file__) + '/' + 'socket.txt', mode='w')

columns = int(input("Enter the number of columns: "))
print(columns, file=f)

for i in range(columns):
    columnName = input("Enter the name of column no. " + str(i+1) + ": ")
    columnType = int(input("Enter the type of column no. " + str(i+1) + '\n1.integer\t2.double\t3.character\t4.string\n: '))
    print(columnName, file=f)
    print(columnType, file=f)
print("\n")

print("Please choose an option ")
c = int(input("1. Insert row\n2. Delete cell\n3. Edit cell\n4. Exit and print table\n: "))
print("")

cntr = 1

while c != 4:
    if c == 1:
        s = input("Enter the values seperated by semicolon: ")
        s = "i;" + str(cntr)+ ";" + s
        print(s, file=f)
        cntr = cntr + 1
    
    elif c == 2:
        row = input("Enter the row number: ")
        column = input("Enter the column number: ")
        print("d;"+str(row)+";"+str(column), file=f)


    elif c == 3:
        row = input("Enter the row number: ")
        column = input("Enter the column number: ")
        new = input("Enter the new value: ")
        print("e;"+str(row)+";"+str(column)+";"+str(new), file=f)

    print("\nPlease choose an option ")
    c = int(input("1. Insert row\n2. Delete cell\n3. Edit cell\n4. Exit and print table\n: "))
    print("")
        
print("Table was printed to the file \"table.csv\"\n")

f.close()
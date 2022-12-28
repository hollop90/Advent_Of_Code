print("hello world")

# open file
f = open("input.txt")
# make a list of bingo tables
x = f.readline()
delim = ","
x = int(x.split(delim))
print(x[0] + x[1])
print(x)
# loop through tables
    # take first element in table and compare to every other element in table
    # if a match is found break the loop and announde "MATCH FOUND"
    # else countinue
# announce "NO MATCH FOUND"
# exit
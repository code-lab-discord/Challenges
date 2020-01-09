# challenge: find lowest common multiple of numbers 1 to specified number. bonus points for range and specific number
# capabilities.
from functools import reduce

# give the user some info
print("Input 't' for finding the LCM of 1 to the specified number,'r' for finding "
      "the LCM of all numbers in\n between the specified numbers, or 's' to find the LCM of multiple "
      "non-concurrent numbers.")
# choose their mode
mode = input("Which mode would you like to use? ")


# def lcm function for finding lcm
def lcm(a, b):
    a = int(a)
    b = int(b)
    if a > b:
        greater = a
    else:
        greater = b

    # good old brute forcing
    while True:
        if greater % a == 0 and greater % b == 0:
            current_lcm = greater
            break
        greater += 1
    # this is the lcm now, as it divides evenly with respect to both a and b
    return current_lcm


# apply aforementioned brute forcing to list of numbers to find their lcm
def get_lcm_for(your_list):
    return reduce(lambda x, y: lcm(x, y), your_list)


# first option
if str(mode) is "t":
    # specific for this mode
    up_to = int(input("Find the LCM of all numbers from 1 to what? Hint: its inclusive: "))
    # this will get the list of numbers
    lst = []
    for i in range(1, int(up_to + 1)):
        lst.append(i)
    # it's brute forcing time
    print("The LCM of " + str(lst) + " is " + str(get_lcm_for(lst)))
    exit()

# second option
if str(mode) is "r":
    # specific for this mode
    between = input("From what to what shall we find the LCM of? Hint: it's inclusive, and format your input in the "
                    "format x-x: ").split("-")
    # get the list
    lst = []
    for i in range(int(between[0]), int(between[1])+1):
        lst.append(i)
    # it's brute forcing time
    print("The LCM of " + str(lst) + " is " + str(get_lcm_for(lst)))
    exit()

# third option
if str(mode) is "s":
    # specific for this mode
    nums = input("What numbers do you want to find the LCM of? Hint: format your input separated by a comma and space, "
                 "like this: 'x, x, x, x': ").split(", ")
    lst = []
    for i in nums:
        lst.append(i)
    print("The LCM of " + str(lst) + " is " + str(get_lcm_for(lst)))
    exit()

# all requests have been fulfilled. if the program runs to here, then the user inputted the mode wrong.
print("Sorry, I couldn't understand what mode you were trying to use. Please try again.")
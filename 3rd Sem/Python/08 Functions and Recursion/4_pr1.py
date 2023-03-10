# def max(a, b, c):
#     return a if a>b and a>c else b if b>a and b>c else c

# m = max(7, 8, 3)
# print("The max number is " + str(m))

# print("Hello", end=" ")
# print("How", end=" ")
# print("Are", end=" ")
# print("You", end=" ")



# s=sum(5)
# print(s)


# def rec_sum(n):
#     if n<1:
#         return 0
#     else:
#         return rec_sum(n-1) + n

# n = rec_sum(5)
# print(n)

# def pattern(n):
#     if n<1:
#         return
#     else:
#         print("*" * pattern(n-1))

# pattern(6)

def remove_and_split(string, word):
    newStr = string.replace(word, "")
    return newStr.strip()

this = "    Himanshu is a good boy    "
n = remove_and_split(this, "Himanshu")
print(n)



# print(this)
# print(this.strip())






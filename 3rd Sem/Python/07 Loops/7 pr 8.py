# n=4
# for i in range(4):
#     # for j in range(i+1):
#     #     print("*")
#     print("*" * (i+1))

# n=3
# for i in range(3):
#         print(" "*(n-i-1), end="")
#         print("*"*(2*i+1), end="")
#         print(" "*(n-i-1))

n=int(input("Enter a number "))
for i in range(n):
    if(i==0 or i==n-1):
        print("*"*n)
    else:
        print("*", end="")
        print(" "*(n-2), end="")
        print("*")
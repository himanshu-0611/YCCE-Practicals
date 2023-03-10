# n = 5
# product = 1
# for i in range(n):
#     product = product*(i+1)
# print(product)

# def factorial_iter(n):
#     product = 1
#     for i in range(n):
#         product = product*(i+1)
#     return product

def fact_rec(n):
    if n==1 or n==0:
        return 1
    return n * fact_rec(n-1)

f=fact_rec(6)
print(f)
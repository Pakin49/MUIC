from tabulate import tabulate

price_list = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
memoization = []

def maximum_profit(length) :
  if memoization[length] != 0:
    return memoization[length]
  if length<=10:
    max = price_list[length]
    for i in range(1,length):
      temp = maximum_profit(length-i)+price_list[i]
      if temp>max:
        max = temp
    
    memoization[length] = max
    return max
  else:
    max = 0
    for i in range(1,11):
      temp = maximum_profit(length-i)+price_list[i]
      if temp>max:
        max = temp
    memoization[length] = max
    return max

data = [price_list[1:]]
header = [str(i) for i in range(1,11)]
print(tabulate(data,headers=header,tablefmt="fancy_grid",numalign = "center"))
print("----------------------------------")
n = int(input("Insert length of the log: "))
memoization = [0]*(n+1)
print("Table of max price for each length")
data = [[maximum_profit(i)] for i in range(n+1)]
print(tabulate(data, headers=["Max Price"], tablefmt="fancy_grid", showindex="always",numalign = "center"))
print("----------------------------------")
print(f"Maximum profit of length {n}:",maximum_profit(n))
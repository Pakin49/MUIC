def TD_Sack(i, j):
    if i == 0 or j == 0:
        return 0
    if m[i][j] is None:
        if j > weight[i]:
            m[i][j] = max(TD_Sack(i - 1, j), TD_Sack(i - 1, j - weight[i]) + value[i])
        else:
            m[i][j] = TD_Sack(i - 1, j)
    return m[i][j]

value = [0, 1, 2, 3, 3, 2]
weight = [0, 4, 5, 1, 2, 5]
capacity = 7
items = len(value) - 1
m = [[None for _ in range(capacity + 1)] for _ in range(items + 1)]

result = TD_Sack(items, capacity)
print("Maximum value:", result)

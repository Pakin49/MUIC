## this is the correct prediction count
count = 0;
for predict in predicts:
  if predict[0] > 0.5 and predict[2] == 'W':
    count = count + 1
  elif predict[1] > 0.5 and predict[2] == 'M':
    count = count + 1
print(len(predicts)-count)

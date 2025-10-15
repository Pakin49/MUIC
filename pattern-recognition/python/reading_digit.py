import pandas as pd
import numpy as np
# %% 
df = pd.read_csv("data/digit.csv",header=None)
print(df)
# %%
digit = np.reshape(np.array(df.iloc[:,:-1]),[10,50,784]) # ignore the last column since it is a label
print(digit)
# %%
import matplotlib.pyplot as plt
plt.imshow(np.reshape(digit[2,15,:],[28,28]),cmap='gray')
plt.savefig("digit2.png")
plt.show()

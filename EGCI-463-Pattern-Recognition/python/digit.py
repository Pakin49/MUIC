import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
import os
from sklearn.metrics import classification_report

# digit data 500 pictures 10 digit 0-9
# each digit has 50 sampels
df = pd.read_csv("~/workspace/current/pattern-recognition/python/data/digit.csv",header=None)
df.shape
digit_features = np.reshape(np.array(df.iloc[:,:-1]),[500,784]) # every row execpt last column
digit_features.shape
digit_label = np.array(df.iloc[:,-1])
digit_label.shape
# %%
# Train Test styeplit
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(digit_features, digit_label,random_state=123)
print(X_train)
X_train.shape

# %%
# Bayes Theorems
# calculate probability of each digit being 0 or 1
from sklearn.naive_bayes import MultinomialNB
bayes_model= MultinomialNB()
bayes_model.fit(X_train, y_train)
bayes_pred = bayes_model.predict(X_test)
print(bayes_pred)
print(classification_report(bayes_pred, y_test))
    
# %%
from sklearn.linear_model import LogisticRegression
model = LogisticRegression()
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
y_pred.shape
print(classification_report(y_pred,y_test))
# %%
# LDA
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
lda = LinearDiscriminantAnalysis()

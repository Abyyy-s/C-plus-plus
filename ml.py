import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures
from sklearn.metrics import r2_score, mean_absolute_error, mean_squared_error
 
# 1. Load data
data = pd.read_csv("data.csv")   # replace with your CSV file
print(data.head())
 
# Assume last column is target, rest are features
X = data.iloc[:, :-1].values
y = data.iloc[:, -1].values
 
# ---------------- Single Variable Regression ----------------
X_single = X[:, 0].reshape(-1, 1)
Xs_train, Xs_test, ys_train, ys_test = train_test_split(
    X_single, y, test_size=0.2, random_state=42)
 
single_model = LinearRegression()
single_model.fit(Xs_train, ys_train)
ys_pred = single_model.predict(Xs_test)
 
print("\n--- Single Variable Regression ---")
print("R2 Score :", r2_score(ys_test, ys_pred))
print("MAE      :", mean_absolute_error(ys_test, ys_pred))
print("MSE      :", mean_squared_error(ys_test, ys_pred))
 
plt.scatter(Xs_test, ys_test, color="blue", label="Actual")
plt.plot(Xs_test, ys_pred, color="red", label="Predicted")
plt.title("Single Variable Regression")
plt.legend()
plt.show()
 
# ---------------- Multi Variable Regression ----------------
Xm_train, Xm_test, ym_train, ym_test = train_test_split(
    X, y, test_size=0.2, random_state=42)
 
multi_model = LinearRegression()
multi_model.fit(Xm_train, ym_train)
ym_pred = multi_model.predict(Xm_test)
 
print("\n--- Multi Variable Regression ---")
print("R2 Score :", r2_score(ym_test, ym_pred))
print("MAE      :", mean_absolute_error(ym_test, ym_pred))
print("MSE      :", mean_squared_error(ym_test, ym_pred))
 
# ---------------- Polynomial Regression ----------------
poly = PolynomialFeatures(degree=2)
X_poly = poly.fit_transform(X_single)
Xp_train, Xp_test, yp_train, yp_test = train_test_split(
    X_poly, y, test_size=0.2, random_state=42)
 
poly_model = LinearRegression()
poly_model.fit(Xp_train, yp_train)
yp_pred = poly_model.predict(Xp_test)
 
print("\n--- Polynomial Regression (degree=2) ---")
print("R2 Score :", r2_score(yp_test, yp_pred))
print("MAE      :", mean_absolute_error(yp_test, yp_pred))
print("MSE      :", mean_squared_error(yp_test, yp_pred))
 
# Sort for smooth curve plotting
sort_idx = X_single[:, 0].argsort()
plt.scatter(X_single, y, color="blue", label="Actual")
plt.plot(X_single[sort_idx], poly_model.predict(X_poly)[sort_idx],
         color="green", label="Polynomial Fit")
plt.title("Polynomial Regression")
plt.legend()
plt.show()

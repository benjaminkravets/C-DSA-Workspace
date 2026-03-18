# from itertools import permutations, product
# from multiprocessing import Pool


# import matplotlib.pyplot as plt

# # Sample data
# x = [1, 2, 3, 4, 5]
# y = [1, 4, 9, 16, 25]

# plt.plot(x, y)

# # Add a vertical line at x=3
# plt.axvline(x=3, color='r', linestyle='--')

# plt.show()

import matplotlib.pyplot as plt

class KalmanFilter1D:
    def __init__(self, x0, P0, Q, R):
        self.x = x0      # initial estimate
        self.P = P0      # initial uncertainty
        self.Q = Q       # process noise variance
        self.R = R       # measurement noise variance
        
    def update(self, z):
        # Prediction
        self.P = self.P + self.Q

        # Kalman Gain
        K = self.P / (self.P + self.R)

        # Update estimate
        self.x = self.x + K * (z - self.x)

        # Update uncertainty
        self.P = (1 - K) * self.P

        return self.x


# --- Example usage ---
kf = KalmanFilter1D(
    x0=0.0,
    P0=1.0,
    Q=0.01,
    R=0.1
)

measurements = [0.9, 1.1, 1.0, 1.2, 0.95, .93, 1.0, 20, 40, .5, -1]
estimates = []

for z in measurements:
    estimate = kf.update(z)
    estimates.append(estimate)
    print(f"Measurement: {z:.2f}, Estimate: {estimate:.2f}, Uncertainty: {kf.P:.2f}")


# --- Plot ---
plt.plot(measurements, marker="o", label="Measurements")
plt.plot(estimates, marker="s", label="Kalman Estimate")
plt.xlabel("Time step")
plt.ylabel("Value")
plt.title("1D Kalman Filter")
plt.legend()
plt.grid(True)
plt.show()

import numpy as np

x = np.array([1, 3, 2, 5, 4, 6, 1])

local_max = np.where((x[1:-1] > x[:-2]) & (x[1:-1] > x[2:]))[0] + 1
local_min = np.where((x[1:-1] < x[:-2]) & (x[1:-1] < x[2:]))[0] + 1

print("Local maxima:", local_max)
print("Local minima:", local_min)

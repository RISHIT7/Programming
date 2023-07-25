# ------------------ Inverse FFT -------------------


import numpy as np

def Inverse_FFT(P):
    n = len(P)
    if n == 1:
        return P
    root = np.exp(2*np.pi*complex(0, 1))
    P_e = P[::2]
    P_o = P[1::2]

    y_e, y_o = Inverse_FFT(P_e), Inverse_FFT(P_o)
    y = [0]*n
    for j in range(n/2):
        y[j] = y_e[j] + (root**(j))*y_o[j]
        y[j+(n/2)] = y_e[j] - (root**(j))*y_o[j]
    return y
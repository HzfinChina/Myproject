import numpy as np
m0 = 1.282
m1 = 340.5/1000
m2 = 119.5/1000
g=9.7887
R0 = 9.318/100
r0 = 6.195/100
H = 46.31/100
T0 = 1.22 
T1 = 1.197
def calcJ_0(T):
    return m0 * g * R0 * r0 * (T ** 2)/(4 * (np.pi ** 2) * H)
J0 = calcJ_0(T0)
def calcJ_1():
    return g*R0*r0/(4*pow(np.pi, 2)*H)*((m1 + m0)*(T1**2) - m0 * (T0**2))

def calcJ_2(T2):
    return (m0 + 2*m2)*g*R0*r0/(4*np.pi**2 *H)*T2**2 - J0
    

T2list = [1.147,1.1862,1.275]
for T2 in T2list:
    print(calcJ_2(T2))


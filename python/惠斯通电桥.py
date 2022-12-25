import numpy as np
import matplotlib.pyplot as plt 
from scipy.interpolate import make_interp_spline

res = np.array([[0.2542, 1.167, 2.281,3.145,4.224,5.057,6.227,7.179,8.261,9.329,10.351,12.345,14.477,16.872,18.817,19.549],
       [0.255,1.182,2.310,3.188,4.282,5.129,6.316,7.283,8.384,9.471,10.517,12.553,14.731,17.193,19.203,19.984]])

diode = np.array([[0.1012, 0.1987,0.3027,0.3934,0.4105,0.4235,0.4429,0.4601,0.4828,0.5015,0.5202,0.5445,0.5652,0.5953,0.6297,0.6555,0.6827,0.7189,0.7519,0.7652],
         [0,0,0.0003,0.080, 0.0134,0.0195,0.0338,0.0538,0.0958,0.1503,0.2306,0.3961,0.6204,1.1824,2.448,4.264,7.746,17.3,37.4,52.4]])

def Draw(list2d,title):
    x = list2d[0]
    y = list2d[1]
    
    model = make_interp_spline(x, y)
    xs = np.linspace(x[0], x[-1], 500)
    ys = model(xs)
    plt.plot(x, y, 'ko',markersize = 10 )
    plt.plot(xs, ys, 'k-')
    plt.xticks(size = 20)
    plt.yticks(size = 20)
    plt.xlabel("U/V",size = 20)
    plt.ylabel("I/mA",size = 20)
    plt.title(title,family = 'simsun',size = 30)

Draw(res,"电阻伏安特性曲线")
plt.show()
Draw(diode, "二极管伏安特性曲线")
plt.show()




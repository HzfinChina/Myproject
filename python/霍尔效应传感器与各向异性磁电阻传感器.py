import numpy as np
import matplotlib.pyplot as plt
from numpy.ma import fabs
from scipy.interpolate import make_interp_spline
from scipy.interpolate import interp1d
from scipy.optimize import leastsq

retV_H = lambda list2d : np.array([[list2d[i][0], (list2d[i][1] - list2d[i][2] + list2d[i][3] - list2d[i][4])/4]for i in range(len(list2d))]).T
IM_V = retV_H(np.array(
        [[0.1, 0.77,-1.85,1.87,-0.75],
         [0.2,2.10,-3.20,3.21,-2.08],
         [0.3,3.44,-4.54,4.55,-3.42],
         [0.4,4.77,-5.87,5.88,-4.76],
         [0.5,6.11,-7.22,7.23,-6.09],
         [0.6,7.43,-8.55,8.56,-7.42],
         [0.7,8.76,-9.87,9.89,-8.75],
         [0.8,10.1,-11.21,11.22,-10.08],
         [0.9,11.42,-12.54,12.54,-11.39],
         [1.0,12.76,-13.84,13.86,-12.73]]))


IS_V = retV_H(np.array(
        [[0.94,1.14,-1.35,1.35,-1.14],
         [2.31,2.81,-3.33,3.33,-2.8],
         [3.26,3.96,-4.67,4.68,-3.95],
         [4.74,5.78,-6.78,6.8,-5.76],
         [5.81,7.08,-8.31,8.33,-7.07],
         [6.92,8.45,-9.91,9.91,-8.44],
         [8.49,10.39,-12.13,12.15,-10.37]]))



X_V = retV_H(np.array(
        [[10,2.13,-3.22,3.23,-2.11],
         [15,2.87,-3.98,4.00,-2.87],
         [21,3.97,-5.07,5.08,-3.94],
         [30,5.02,-6.12,6.13,-5.0],
         [38,5.47,-6.57,6.58,-5.46],
         [50,5.8,-6.89,6.91,-5.79],
         [85,6.05,-7.13,7.14,-6.03],
         [110,6.07,-7.15,7.17,-6.06],
         [135,6.07,-7.16,7.17,-6.05],
         [165,6.08,-7.17,7.18,-6.07],
         [200,6.05,-7.12,7.14,-6.03],
         [230,5.96,-7.03,7.05,-5.94],
         [250,5.77,-6.83,6.85,-5.75],
         [260,5.49,-6.58,6.59,-5.47],
         [270,4.92,-6.01,6.02,-4.92],
         [280,3.68,-4.75,4.77,-3.66],
         [290,1.86,-2.94,2.96,-1.84],
         [300,0.62,-1.71,1.72,-0.6]]))


Vout_IM = np.array(
        [[600,-13.4],[550,-16.8], [500, -21.0], [450,-29.5],[400, -30.1],[350, -28.1], [300,-25.1],
         [250,-21.3],[200,-16.7], [150,-12.0], [100, -7], [50,-1.7],[0,3.3],[-50,8.3],[-100, 13.5], [-150, 18.5],
         [-200, 23.1], [-250, 27.2], [-300, 30.7],[-350, 33.3], [-400, 34.6],[-450,30.8],[-500, 23.8],[-550, 19.8],[-600,16.6]]).T


Vout_Theta = np.array(
        [[0,-12.1], [5,-12.1],[10,-12.0],[15,-11.8],[20,-11.4],[25,-11],[30,-10.6],[35,-10.0],[40,-9.3],[45,-8.5],
        [50,-7.7],[55,-6.7],[60,-5.7],[65,-4.6],[70,-3.4],[75,-2.2],[80,-0.9],[85,-0.3],[90,1.6]]).T

def Draw(list2d,*, title,xlabel = "x", ylabel = "y", savefname):
    x = list2d[0]
    y = list2d[1]
    print(x)
    model = interp1d(x, y)
    xs = np.linspace(x[0], x[-1], 500)
    ys = model(xs)
    plt.plot(x, y, 'ko',markersize = 10 )
    plt.plot(xs, ys, 'k-')
    plt.grid()
    plt.xticks(size = 20)
    plt.yticks(size = 20)
    plt.xlabel(xlabel,size = 20)
    plt.ylabel(ylabel,size = 20)
    plt.title(title,family = 'simsun',size = 30)
    plt.savefig(savefname,bbox_inches = 'tight')


def coefficient():
    L = 0.3
    mu = 4 * np.pi * 1e-7
    N = 3200 
    D = 0.03 
    return (L * L + D * D)** 0.5 /(mu * N)

def getB(list1d, I = 1, flag = 0):
    """list1d: 如果flag = 0,那么默认是通过L^2 + d^2 计算，那么list1d就是I_M
             如果flag = 1,那么是通过KH/IS/VH计算，list1d就是V_H
             如果flag = 2, 那么是通过亥姆赫兹线圈公式计算
    """
    if flag == 0:
        return [coefficient() * item for item in list1d]
    if flag == 1:
        KH = 199.315
        return [item / (KH * I) for item in list1d]
    if flag == 2:
        return [IM * 8 * 4 * np.pi * 1e-7 * 310 /(5 ** 1.5 * 0.1) for IM in list1d]

def getKH(list2d, I = 1.):
    slope = np.polyfit(*list2d, 1)[0]      
    print(slope)
    KH = coefficient() * slope / I
    return KH 


KH = (getKH(IM_V, I = 0.005)/1000 + getKH(IS_V, I = 0.5))/2
print(KH)
#B = getB(X_V[1],I = 0.005, flag =1) #注意这时X-B的B
#Draw(list([X_V[0], B]), title = "$B-X$",xlabel = "$X/\\rm cm$",ylabel = "$B/\\rm mT$",savefname = "B-X.png" )
#print(getB(X_V, flag =1 ))
#print(getB(IS_V, 0.5))


#Draw(IM_V, title = "$V_H - I_M$",xlabel = "$I_M$",ylabel = "$V_H$",savefname = "V_H-I_M.png" )
#Draw(IS_V, title = "$V_H - I_S$",xlabel = "$I_S$",ylabel = "$V_H$",savefname = "V_H-I_S.png" )
#Draw(Vout_Theta,title = "$Vout-\\theta$",xlabel = "$\\theta$", ylabel ="Vout", savefname = "V-Theta")
AMR_B = getB(Vout_IM[0],flag = 2)
ls = [Vout_IM[1][i] / 5/ AMR_B[i] for i in range(len(Vout_IM))]
print(sum(ls)/len(ls))

#Draw(xlist = AMR_B, ylist = Vout_IM[1],title = "$Vout-B$",xlabel = "$B$", ylabel ="Vout", savefname ="temp")

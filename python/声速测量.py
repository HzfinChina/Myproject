import numpy as np
table1 = [[252.09,247.263,242.886,238.048,233.579,228.848,223.7,219.099,213.393,209.847], 24.7, 36.994]
table2 = [[192.674,187.992,183.233,178.588,173.811,169.231,164.349,159.586,154.752,150.238], 24.3,37.031]
table3 = [[136.021,126.504,116.693,107.173,97.714,88.127,78.619,69.174,59.663,50.295],24.3,37.031,]

table4 = np.array([[i for i in range(100, 191, 10)],
                  [409, 438, 466, 494, 524, 557, 603, 636, 665, 694]])

leadtable = [[10, 41], [30, 89], [50, 145], 23.9]
organicglasstable = [[10, 38], [30, 51], [50, 67], 23.9]

def calcerror(v):
    v_0 = 346.11
    return abs((v - v_0) / v_0)
def ddm(table, f): 
    '''逐差法'''
    oneoftwolbda = 1/25 * sum([table[i] - table[i+ 5] for i in range(0, 5)])
    calcv = oneoftwolbda * f 
    return [calcv, calcerror(calcv)]

print(ddm(table1[0], table1[2]))
print(ddm(table2[0], table2[2]))
print(ddm(table3[0], table3[2]))

def waveform(table):
    calcvlist = [10 / (table[i+1] - table[i]) for i in range(0, 9)]
    return calcvlist


# print(waveform(table4[0]))

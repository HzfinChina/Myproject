import numpy as np 
from decimal import *


class oildrop:
    def __init__(self, table):
        self.table = table 
    def average_q(self):
        def calc(Un, t):
            rho = 981
            g = 9.78
            nu = 1.83e-5
            v = 1.6e-3
            b = 8.22e-3 
            P = 1.0098e5 
            d = 5e-3
            return (18 * np.pi)/((2 * g * rho) ** 0.5) * d / Un * (nu * v/(t*(1+b/P*np.sqrt(2*g*rho*t/(9 * nu * v))))) ** 1.5
        calc_q_list = [calc(*unit) for unit in self.table]
        average_q = np.mean(calc_q_list)
        approximate_charge = average_q / 1.602176634e-19 
        return [calc_q_list, average_q, approximate_charge]
    def estimate_e(self):
        getlist = self.average_q()
        return getlist[1] / round(getlist[2])

table1 = [[116,58.54], [117,57.69], [116,58.24], [116,56.80]]
table2 = np.array([[153,152,151,153,152],[20.20,20.09,20.34,20.14,19.98]]).T 
table3 = np.array([[131,131,130,131,131],[19.29,19.14,19.94,19.10,19.64]]).T
oildrop1 = oildrop(table1)
oildrop2 = oildrop(table2)
oildrop3 = oildrop(table3)

# print(oildrop1.average_q())
# print(oildrop2.average_q())
# print(oildrop3.average_q())

estimate_e = np.mean([oneoildrop.estimate_e() for oneoildrop in [oildrop1, oildrop2, oildrop3]])
print((1.602176634e-19 - estimate_e) / estimate_e)

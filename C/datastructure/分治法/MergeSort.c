#include <stdio.h>
#include <stdlib.h>
#define MAXLEN  1000

void Merge(int *array, int left, int mid, int right, int *temp){
    int i = left;
    int j = mid + 1;
    int index = 0;
    while (i <= mid && j <= right){
        if (array[i] < array[j]){
            temp[index++] = array[i++];
        }
        else {
            temp[index++] = array[j++];
        }
    }
    while (i <= mid)
        temp[index++] = array[i++];
    while (j <= right)
        temp[index++] = array[j++];
    for (index = 0; left <= right;)
        array[left++] = temp[index++];
}

/* 这个函数就是将两个有序数组合为一个有序数组  */
void Merge_and_Sort(int *array, int left, int right, int *temp){
    if (left < right){
        /* 不要这样写：int mid = (left + right) / 2
         不用担心(left + right)太大溢出 */
        int mid = left + (right - left) / 2;
        Merge_and_Sort(array, left, mid, temp);
        Merge_and_Sort(array, mid + 1, right, temp);
        Merge(array, left, mid, right, temp);
    }
}


int main()
{
    int numarray[] = {
        -4287, 3212, 325, 9570, -3255, -3978, 7842, 8858, 3689, -6903, 6766, 712, -7878, -9031, -7905, 4983, -5100, 3576, -3975, -5063, -6702, -5429, 4639, 7219, -6756, -333, 5544, 1539, 7790, -352, -4795, 9194, -6760, -2374, -3825, 2500, -8249, -883, -1936, 3005, -2920, 561, -4755, 956, 8050, 1054, 6414, -6996, 4186, 9671, -4287, -5742, 6696, -9580, 4044, 1262, -3112, 7338, -2975, -7300, -671, 2047, -1327, -5531, -6934, -3716, 3502, -52, 8398, 7475, 2316, 3139, -3849, -9188, 843, -5677, 8499, -6347, -9642, 6586, -6728, 7224, -7803, 9067, -4766, -3199, -3270, -9241, 9271, 4272, -2060, 1083, -95, -9708, 653, -6, 4671, 3809, -4476, -7514, 1166, 5099, 7493, -1525, 4973, -9937, -8011, 1389, 322, 1547, 1882, 5097, 4460, 7378, 9391, -6487, -135, 1226, 6658, 836, 4256, -744, 7751, 305, -1155, -814, -4843, -3577, 3592, -6882, -1687, 6644, -4530, -1374, -842, -1095, -5382, -4137, 3697, -7231, 3050, 5563, -8880, 6786, -2069, -8112, -2131, -6587, 751, 7872, 6680, 930, -5414, 6854, -7398, -9953, 3571, -273, -4668, 4768, 429, 9494, -7759, -1638, 1205, 827, 3221, -7415, 9934, -836, 3772, -319, -73, 375, -3400, -3032, 3994, 9207, -8818, -7787, -7564, 9532, -1978, -3607, -6041, 3861, 3305, 5229, -1589, 7198, 352, -8482, -6310, 1424, 1104, 4799, -855, 2417, 8413, 3981, 9360, 3529, 9654, 150, 3651, -8040, -7498, -1288, 7266, -1254, -1229, 7666, 4689, 223, 64, 5687, -752, -297, 8725, 6171, -7005, -599, -4610, -3677, 5457, -8473, 2001, -7485, 8060, 3404, 9192, -6631, -9320, -8100, -9799, -8890, -4540, -9642, 7444, 6537, 70, -6077, 5788, -5495, 2351, 4203, -332, 681, -6369, 8164, -2100, -4198, 6876, -6681, 738, -6302, -2534, -8399, -3723, -8076, -6282, -7648, -6725, 782, -2283, 81, -2185, -1081, -949, -8572, -522, 5455, 6148, 8057, -4894, 7249, -3321, 5910, 4124, 8090, 9410, 6500, -1376, 7976, -4380, 628, -1246, -3359, 5331, -7011, -1900, 5167, -7687, 6629, 8564, 8645, -3902, 1921, 5316, -3078, -9234, -5538, 7940, 7994, 801, -3266, 7137, 7597, -3480, 2487, -4503, -5569, 8718, 8844, -5184, -8316, -3165, 5756, -6179, -9165, 8854, -6955, -560, 3776, 3835, 2775, 4694, 9689, -6119, 5120, 4179, -4832, -6964, -4816, -1508, 1956, -7023, -1787, 3220, -4306, -3583, -2911, 4427, 174, -1132, 9798, 9096, 5966, -8056, -9564, -1640, 5608, 4994, -9797, -1308, 1255, 2128, -2838, 1162, 6226, 8500, -2339, 1736, -3555, 1313, 1172, 9555, 822, 4493, 8377, 659, -9282, -4032, 1664, 1167, 4731, 5275, 9661, -7623, 9078, -8144, -1852, 3609, -5462, -5321, 6475, 4477, 5040, 9948, 2505, -9627, -5197, 9731, -5222, -8406, -9294, 7426, -3090, -8772, -419, -4158, -8882, 5347, 7787, -5756, -1723, 9362, -3897, -4222, 5832, 3909, -8262, 8402, 5801, 1985, 7459, -8396, 5652, -8925, -1773, 1668, -9576, 4766, 6411, -8670, -4032, -9885, 5205, -7329, 2632, -9053, -1364, -213, 9745, 9132, -7350, 5737, -1517, 4525, 7721, 4970, 4713, 2628, 6748, 5549, -8758, 7730, -1601, -5850, 3400, 8006, -3595, 2598, -2050, 5949, 8534, 3606, 2315, -8913, 4075, -1663, 1432, 2446, -3417, -814, -8170, -8925, -9829, -9732, -793, -5694, 7638, -4178, -2070, -7859, -4960, 6405, -4499, 1547, -8541, 7494, -4156, 4724, 1292, 7078, -3558, -2218, -1566, -9842, 6228, -8383, 2620, -5397, -6469, 9073, -5967, -1614, -5087, -7169, -3546, 1815, -6597, 2697, -1833, -1947, -90, 341, 5202, -9601, -349, -8529, 7766, -777, -4648, -5426, 6229, 3362, -5864, -2390, -7407, -3312, 4451, 870, -3775, -7928, -3717, -5803, -6851, 384, 1227, -5527, 1398, -9332, 7823, 5844, -8988, -5032, -8207, -2044, 6157, 8903, -1832, 770, 9065, 5683, -6248, 7607, -806, -8204, -632, 5931, 518, 5462, 3917, 168, 9245, 4693, 2227, -9158, 4798, 9435, -3156, -5916, 1136, 1099, -618, -5761, -8493, -7948, 4868, -6808, 7471, 3998, -3427, -7409, 2957, 1755, 5916, 278, -1472, 5831, -1224, -9670, -5708, -9164, -6242, 3144, -4293, -6942, -4961, -7352, -8535, 9164, 8683, -4761, -1195, -7763, 481, -9178, -87, -198, -113, -7983, -1671, -1753, -7288, 4300, -1481, 9077, -8249, -2588, -7103, -2554, -8664, -9723, 6694, 556, -1824, -8266, 7708, 5233, -9613, 5557, 6894, -8467, 3249, 7194, 1837, -3315, 5362, 9563, -7722, 8086, 6821, 3959, -8105, 3639, 793, 1562, 2255, 2313, 6501, -972, -6814, 9632, 1164, 1395, 9123, 2234, 1855, 8955, -3446, 887, -6733, 2553, -9504, 381, 1664, -3792, 97, -891, 4099, -6088, 4025, 1284, 8860, 6216, -8072, 2249, 9048, -904, 3812, 6980, 5722, -4021, 2977, 9676, 6404, 4208, -3382, 2154, -17, -7364, 8930, 7748, -2657, -3800, -3888, -5451, 1489, 7256, -6264, 9501, 9260, 693, 7926, -933, 2852, -515, -3829, -3079, -3455, -391, 3147, -2397, 7414, -2081, 8065, 8275, -1735, 4709, -7213, -2731, -3957, 6209, 8755, -3097, -4373, 9725, -3944, 9374, 528, -9186, 8727, 1668, -753, -7983, 930, 7859, -7564, -9041, -7019, -7758, 5174, -1565, 5634, 3903, -9013, -1182, -5320, -1157, 6257, 2494, -3193, -9888, -5207, -4921, 6726, 7759, -50, 2746, -9821, -9708, 2702, 921, 2056, -8159, 2044, 8830, -1693, 5641, -7002, 5781, 4767, -1183, 9421, -5260, 6883, 725, 9456, 9580, -9786, -791, 6857, 8413, 8799, -2005, 4327, 819, 8699, 6036, -8517, -3702, 4721, -185, -4687, -5335, 1895, -3945, 9423, 1050, -5219, -8356, -2524, 2966, 5697, -512, -6515, 5753, 5825, -7587, 7171, -1806, -1387, 1073, 2387, -4878, -4571, 7412, -5855, -1121, -7856, 901, -2954, -9988, -3233, 3188, 1150, -2277, -4090, 2194, 2837, 1496, -4175, 1425, -1370, 9640, 3313, 829, -2684, -2580, 800, 742, 2757, -1994, 8178, 9146, -9726, 5678, -3578, -2410, 1464, -3905, 5597, -2867, -6177, -6155, -1103, 2671, 9649, 3793, 7603, 6204, -3202, 625, 25, 1616, -1833, -9951, 6854, -3401, -2472, -967, 7065, -3238, -7604, 2445, -2618, -3041, 3861, 1535, -5846, -3707, -9922, -7542, 816, -6743, -3103, 4510, -310, -1063, -1293, 2032, -2666, 9804, 7532, 2677, -3832, 1668, -752, -5171, -8508, 5603, -9938, -6936, 5048, -394, 4749, 6702, -6897, -9000, 5894, 2817, -1660, -1533, -2125, 6536, -9095, -4287, 8743, -7360, 6113, 7391, -3405, 8579, -7714, 3198, 5171, -5835, -3088, -5493, -8623, -278, 7459, 516, -8807, 4976, -8615, -1384, 9443, 5334, -5327, -9112, -2467, 9637, 4501, -1628, -3003, -8257, -6698, -1967, 1652, 1965, -6717, -4818, -4922, -1885, -192, -6636, -774, -7253, 8167, -6435, -8696, 4918, -1701, -3007, 9267, -4142, -5014, -9921, 8642, 874, -7340, 7040, 587, 5931, 7120, 1243, -3856, -2553, -441, 3188, 8454, 8580, -7107, 6549, 7051, 9694, 6719, -1685, -8166, 7838, -310, 5652, -5248, 6196, 196, 8823, -8728, -2217, -5056, 3557, -719, -8326, 6186, 4734, -5766, -970, -7609
    };
    int *temp = malloc(sizeof(int) * 1000);
    Merge_and_Sort(numarray, 0, 999, temp);
    for (int i = 0; i < 999; i++){
        printf("%d ", numarray[i]);
    }
}

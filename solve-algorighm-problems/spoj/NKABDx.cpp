#include<iostream>
#define For(i,a,b) for(int i = a ;i<= b ;i ++)
#define Len 12394

using namespace std;
int ABD[]={12,18,20,24,30,36,40,42,48,54,56,60,66,70,72,78,80,84,88,90,96,100,102,104,108,112,114,120,126,132,138,140,144,150,156,160,162,168,174,176,180,186,192,196,198,200,204,208,210,216,220,222,224,228,234,240,246,252,258,260,264,270,272,276,280,282,288,294,300,304,306,308,312,318,320,324,330,336,340,342,348,350,352,354,360,364,366,368,372,378,380,384,390,392,396,400,402,408,414,416,420,426,432,438,440,444,448,450,456,460,462,464,468,474,476,480,486,490,492,498,500,504,510,516,520,522,528,532,534,540,544,546,550,552,558,560,564,570,572,576,580,582,588,594,600,606,608,612,616,618,620,624,630,636,640,642,644,648,650,654,660,666,672,678,680,684,690,696,700,702,704,708,714,720,726,728,732,736,738,740,744,748,750,756,760,762,768,770,774,780,784,786,792,798,800,804,810,812,816,820,822,828,832,834,836,840,846,852,858,860,864,868,870,876,880,882,888,894,896,900,906,910,912,918,920,924,928,930,936,940,942,945,948,952,954,960,966,968,972,978,980,984,990,992,996,1000,1002,1008,1014,1020,1026,1032,1036,1038,1040,1044,1050,1056,1060,1062,1064,1068,1074,1080,1086,1088,1092,1098,1100,1104,1110,1116,1120,1122,1128,1134,1140,1144,1146,1148,1152,1158,1160,1164,1170,1176,1180,1182,1184,1188,1190,1194,1200,1204,1206,1212,1216,1218,1220,1224,1230,1232,1236,1240,1242,1248,1254,1260,1266,1272,1278,1280,1284,1288,1290,1296,1300,1302,1308,1312,1314,1316,1320,1326,1330,1332,1338,1340,1344,1350,1352,1356,1360,1362,1368,1372,1374,1376,1380,1386,1392,1398,1400,1404,1408,1410,1416,1420,1422,1428,1430,1434,1440,1446,1452,1456,1458,1460,1464,1470,1472,1476,1480,1482,1484,1488,1494,1496,1500,1504,1506,1512,1518,1520,1524,1530,1536,1540,1542,1548,1554,1560,1566,1568,1572,1575,1578,1580,1584,1590,1596,1600,1602,1608,1610,1614,1620,1624,1626,1632,1638,1640,1644,1650,1652,1656,1660,1662,1664,1668,1672,1674,1680,1686,1692,1696,1698,1700,1704,1708,1710,1716,1720,1722,1728,1734,1736,1740,1746,1750,1752,1758,1760,1764,1768,1770,1776,1780,1782,1788,1792,1794,1800,1806,1812,1818,1820,1824,1830,1836,1840,1842,1848,1854,1856,1860,1866,1870,1872,1876,1878,1880,1884,1888,1890,1896,1900,1902,1904,1908,1914,1920,1926,1932,1936,1938,1940,1944,1950,1952,1956,1960,1962,1968,1974,1976,1980,1984,1986,1988,1992,1998,2000,2002,2004,2010,2016,2020,2022,2024,2028,2030,2034,2040,2044,2046,2052,2058,2060,2064,2070,2072,2076,2080,2082,2088,2090,2094,2100,2106,2112,2118,2120,2124,2128,2130,2136,2140,2142,2148,2154,2156,2160,2166,2170,2172,2176,2178,2180,2184,2190,2196,2200,2202,2205,2208,2210,2212,2214,2220,2226,2232,2238,2240,2244,2250,2256,2260,2262,2268,2274,2280,2286,2288,2292,2296,2298,2300,2304,2310,2316,2320,2322,2324,2328,2334,2340,2346,2352,2358,2360,2364,2368,2370,2376,2380,2382,2388,2392,2394,2400,2406,2408,2412,2418,2420,2424,2430,2432,2436,2440,2442,2448,2450,2454,2460,2464,2466,2470,2472,2478,2480,2484,2490,2492,2496,2500,2502,2508,2514,2520,2526,2530,2532,2538,2540,2544,2548,2550,2552,2556,2560,2562,2568,2574,2576,2580,2584,2586,2590,2592,2598,2600,2604,2610,2616,2620,2622,2624,2628,2632,2634,2640,2646,2652,2658,2660,2664,2670,2676,2680,2682,2688,2694,2700,2704,2706,2712,2716,2718,2720,2724,2728,2730,2736,2740,2742,2744,2748,2750,2752,2754,2760,2766,2772,2778,2780,2784,2790,2796,2800,2802,2808,2814,2816,2820,2826,2828,2832,2835,2838,2840,2844,2850,2856,2860,2862,2868,2870,2874,2880,2884,2886,2892,2898,2900,2904,2910,2912,2916,2920,2922,2928,2934,2940,2944,2946,2952,2958,2960,2964,2968,2970,2976,2980,2982,2988,2990,2992,2994,2996,3000,3006,3008,3010,3012,3016,3018,3020,3024,3030,3036,3040,3042,3048,3052,3054,3060,3066,3072,3078,3080,3084,3090,3096,3100,3102,3108,3114,3120,3126,3128,3132,3136,3138,3140,3144,3150,3156,3160,3162,3164,3168,3174,3180,3186,3190,3192,3198,3200,3204,3210,3216,3220,3222,3224,3228,3230,3234,3240,3246,3248,3250,3252,3256,3258,3260,3264,3270,3276,3280,3282,3288,3290,3294,3300,3304,3306,3312,3318,3320,3324,3328,3330,3332,3336,3340,3342,3344,3348,3354,3360,3366,3372,3378,3380,3384,3388,3390,3392,3396,3400,3402,3408,3410,3414,3416,3420,3426,3430,3432,3438,3440,3444,3450,3456,3460,3462,3465,3468,3472,3474,3480,3486,3492,3496,3498,3500,3504,3510,3516,3520,3522,3528,3534,3536,3540,3546,3552,3556,3558,3560,3564,3570,3576,3580,3582,3584,3588,3594,3600,3606,3608,3612,3618,3620,3624,3630,3636,3640,3642,3648,3654,3660,3666,3668,3672,3678,3680,3684,3690,3696,3700,3702,3708,3710,3712,3714,3720,3724,3726,3732,3738,3740,3744,3750,3752,3756,3760,3762,3768,3770,3774,3776,3780,3784,3786,3792,3798,3800,3804,3808,3810,3816,3820,3822,3828,3834,3836,3840,3846,3848,3850,3852,3858,3860,3864,3870,3872,3876,3880,3882,3888,3892,3894,3900,3904,3906,3912,3918,3920,3924,3930,3936,3940,3942,3944,3948,3952,3954,3960,3966,3968,3972,3976,3978,3980,3984,3990,3996,4000,4002,4004,4008,4014,4020,4026,4030,4032,4038,4040,4044,4048,4050,4056,4060,4062,4068,4070,4074,4080,4086,4088,4092,4095,4098,4100,4104,4110,4116,4120,4122,4128,4130,4134,4136,4140,4144,4146,4152,4158,4160,4164,4170,4172,4176,4180,4182,4188,4194,4200,4206,4212,4216,4218,4220,4224,4228,4230,4236,4240,4242,4248,4254,4256,4260,4264,4266,4270,4272,4278,4280,4284,4288,4290,4296,4300,4302,4308,4312,4314,4320,4326,4332,4338,4340,4344,4350,4352,4356,4360,4362,4368,4374,4380,4386,4392,4396,4398,4400,4404,4408,4410,4416,4420,4422,4424,4428,4434,4440,4446,4452,4458,4460,4464,4470,4472,4476,4480,4482,4488,4494,4500,4506,4508,4510,4512,4518,4520,4524,4530,4536,4540,4542,4544,4548,4550,4554,4560,4564,4566,4572,4576,4578,4580,4584,4590,4592,4596,4600,4602,4608,4614,4620,4624,4626,4632,4638,4640,4644,4648,4650,4656,4660,4662,4664,4668,4672,4674,4676,4680,4686,4690,4692,4698,4700,4704,4710,4712,4716,4720,4722,4725,4728,4730,4732,4734,4736,4740,4746,4752,4758,4760,4764,4770,4776,4780,4782,4784,4788,4794,4800,4806,4812,4816,4818,4820,4824,4830,4836,4840,4842,4844,4848,4854,4860,4864,4866,4872,4878,4880,4884,4888,4890,4896,4900,4902,4908,4914,4920,4926,4928,4932,4938,4940,4944,4950,4956,4960,4962,4968,4970,4974,4980,4984,4986,4992,4998,5000,5004,5010,5012,5016,5020,5022,5028,5032,5034,5040,5046,5052,5056,5058,5060,5064,5068,5070,5076,5080,5082,5088,5094,5096,5100,5104,5106,5110,5112,5118,5120,5124,5130,5136,5140,5142,5148,5152,5154,5160,5166,5168,5170,5172,5178,5180,5184,5190,5192,5196,5200,5202,5208,5214,5220,5226,5232,5236,5238,5240,5244,5248,5250,5256,5260,5262,5264,5268,5274,5280,5286,5292,5298,5300,5304,5310,5312,5316,5320,5322,5328,5334,5336,5340,5346,5348,5352,5355,5358,5360,5364,5368,5370,5376,5380,5382,5388,5390,5394,5400,5404,5406,5408,5412,5418,5420,5424,5430,5432,5436,5440,5442,5448,5454,5456,5460,5466,5472,5478,5480,5484,5488,5490,5496,5500,5502,5504,5508,5512,5514,5516,5520,5526,5530,5532,5538,5540,5544,5550,5556,5560,5562,5568,5572,5574,5576,5580,5586,5592,5598,5600,5604,5610,5616,5620,5622,5624,5628,5632,5634,5640,5646,5652,5656,5658,5660,5664,5670,5676,5680,5682,5684,5688,5694,5696,5700,5704,5706,5712,5718,5720,5724,5730,5736,5740,5742,5748,5754,5760,5766,5768,5772,5775,5776,5778,5780,5784,5790,5796,5800,5802,5808,5810,5814,5820,5824,5826,5830,5832,5838,5840,5844,5848,5850,5852,5856,5860,5862,5868,5874,5880,5886,5888,5892,5896,5898,5900,5904,5908,5910,5916,5920,5922,5928,5934,5936,5940,5946,5950,5952,5958,5960,5964,5970,5976,5980,5982,5984,5985,5988,5992,5994,6000,6006,6012,6016,6018,6020,6024,6030,6032,6036,6040,6042,6048,6050,6054,6060,6066,6072,6076,6078,6080,6084,6090,6096,6100,6102,6104,6108,6114,6120,6126,6132,6136,6138,6140,6144,6150,6156,6160,6162,6168,6174,6180,6186,6188,6192,6198,6200,6204,6208,6210,6216,6220,6222,6228,6230,6232,6234,6240,6244,6246,6248,6252,6256,6258,6260,6264,6270,6272,6276,6280,6282,6288,6292,6294,6300,6306,6312,6318,6320,6324,6328,6330,6336,6340,6342,6344,6348,6354,6356,6360,6366,6370,6372,6378,6380,6384,6390,6392,6396,6400,6402,6408,6412,6414,6420,6424,6426,6432,6435,6438,6440,6444,6448,6450,6456,6460,6462,6464,6468,6474,6480,6486,6492,6496,6498,6500,6504,6510,6512,6516,6520,6522,6524,6528,6534,6536,6540,6546,6552,6558,6560,6564,6570,6576,6580,6582,6588,6592,6594,6600,6606,6608,6612,6615,6618,6620,6624,6630,6636,6640,6642,6648,6650,6654,6656,6660,6664,6666,6672,6678,6680,6684,6688,6690,6692,6696,6700,6702,6708,6714,6720,6726,6732,6738,6740,6744,6748,6750,6756,6760,6762,6768,6774,6776,6780,6784,6786,6790,6792,6798,6800,6804,6808,6810,6816,6820,6822,6825,6828,6832,6834,6840,6846,6848,6852,6858,6860,6864,6870,6876,6880,6882,6888,6894,6900,6906,6912,6916,6918,6920,6924,6930,6936,6940,6942,6944,6948,6952,6954,6960,6966,6968,6972,6976,6978,6980,6984,6990,6992,6996,7000,7002,7008,7014,7020,7026,7028,7032,7038,7040,7044,7050,7056,7060,7062,7068,7070,7072,7074,7080,7084,7086,7092,7098,7100,7104,7110,7112,7116,7120,7122,7128,7134,7140,7144,7146,7150,7152,7158,7160,7164,7168,7170,7176,7180,7182,7188,7192,7194,7196,7200,7206,7208,7210,7212,7216,7218,7220,7224,7230,7232,7236,7240,7242,7245,7248,7252,7254,7260,7266,7272,7278,7280,7284,7290,7296,7300,7302,7304,7308,7314,7320,7326,7332,7336,7338,7340,7344,7350,7356,7360,7362,7364,7368,7374,7380,7384,7386,7392,7398,7400,7404,7410,7416,7420,7422,7424,7425,7428,7434,7436,7440,7446,7448,7452,7458,7460,7464,7470,7476,7480,7482,7488,7490,7494,7500,7504,7506,7512,7518,7520,7524,7530,7532,7536,7540,7542,7544,7548,7552,7554,7560,7566,7568,7572,7578,7580,7584,7588,7590,7592,7596,7600,7602,7608,7614,7616,7620,7626,7630,7632,7638,7640,7644,7650,7656,7660,7662,7668,7672,7674,7680,7686,7692,7696,7698,7700,7704,7710,7716,7720,7722,7728,7734,7740,7744,7746,7752,7756,7758,7760,7764,7770,7776,7780,7782,7784,7788,7794,7800,7806,7808,7812,7818,7820,7824,7830,7832,7836,7840,7842,7848,7854,7860,7866,7868,7872,7875,7878,7880,7884,7888,7890,7896,7900,7902,7904,7908,7910,7912,7914,7920,7924,7926,7932,7936,7938,7940,7944,7950,7952,7956,7960,7962,7968,7974,7980,7986,7992,7998,8000,8004,8008,8010,8016,8020,8022,8024,8028,8034,8036,8040,8046,8050,8052,8056,8058,8060,8064,8070,8076,8080,8082,8085,8088,8092,8094,8096,8100,8106,8112,8118,8120,8124,8130,8136,8140,8142,8148,8154,8160,8166,8172,8176,8178,8180,8184,8190,8196,8200,8202,8204,8208,8214,8216,8220,8226,8228,8232,8238,8240,8244,8250,8256,8260,8262,8268,8272,8274,8280,8286,8288,8292,8296,8298,8300,8304,8310,8316,8320,8322,8328,8330,8334,8340,8344,8346,8352,8358,8360,8364,8370,8372,8376,8380,8382,8388,8394,8400,8406,8412,8415,8418,8420,8424,8428,8430,8432,8436,8440,8442,8448,8450,8454,8456,8460,8464,8466,8470,8472,8478,8480,8484,8490,8496,8500,8502,8505,8508,8512,8514,8520,8526,8528,8532,8536,8538,8540,8544,8550,8556,8560,8562,8568,8574,8576,8580,8586,8592,8596,8598,8600,8604,8610,8616,8620,8622,8624,8628,8632,8634,8640,8646,8652,8658,8660,8664,8670,8676,8680,8682,8688,8694,8700,8704,8706,8708,8712,8718,8720,8724,8730,8736,8740,8742,8748,8750,8754,8760,8764,8766,8772,8778,8780,8784,8790,8792,8796,8800,8802,8808,8814,8816,8820,8826,8832,8838,8840,8844,8848,8850,8856,8860,8862,8868,8874,8876,8880,8886,8888,8890,8892,8898,8900,8904,8910,8916,8920,8922,8925,8928,8932,8934,8940,8944,8946,8952,8958,8960,8964,8968,8970,8976,8980,8982,8988,8994,9000,9006,9012,9016,9018,9020,9024,9030,9036,9040,9042,9044,9048,9054,9060,9064,9066,9072,9078,9080,9084,9088,9090,9096,9100,9102,9108,9112,9114,9120,9126,9128,9132,9135,9138,9140,9144,9150,9152,9156,9160,9162,9168,9170,9174,9180,9184,9186,9192,9196,9198,9200,9204,9210,9212,9216,9220,9222,9228,9234,9240,9246,9248,9252,9256,9258,9260,9264,9268,9270,9272,9276,9280,9282,9288,9294,9296,9300,9306,9310,9312,9318,9320,9324,9328,9330,9336,9340,9342,9344,9348,9350,9352,9354,9360,9366,9372,9378,9380,9384,9390,9396,9400,9402,9408,9414,9416,9420,9424,9426,9432,9436,9438,9440,9444,9450,9456,9460,9462,9464,9468,9472,9474,9480,9486,9492,9498,9500,9504,9510,9516,9520,9522,9528,9534,9540,9546,9548,9552,9555,9558,9560,9564,9568,9570,9576,9580,9582,9588,9590,9592,9594,9600,9604,9606,9612,9618,9620,9624,9630,9632,9636,9640,9642,9648,9654,9656,9660,9666,9672,9678,9680,9684,9688,9690,9696,9700,9702,9708,9714,9716,9720,9724,9726,9728,9730,9732,9738,9740,9744,9750,9756,9760,9762,9765,9768,9772,9774,9776,9780,9786,9792,9798,9800,9804,9810,9816,9820,9822,9828,9834,9840,9846,9852,9856,9858,9860,9864,9870,9876,9880,9882,9884,9888,9894,9900,9906,9912,9918,9920,9924,9928,9930,9936,9940,9942,9944,9948,9954,9960,9966,9968,9972,9978,9980,9984,9990,9996,10000} ;
//2488 phan tu


int Pos(int K){
	For(i,0,Len-1){
		if(ABD[i]>=K) return i;
	}
	
}

main(){
	
	int L,R,cnt=0; 
	cin >> L >> R; 
	
	int a = Pos	(L), b = Pos(R);
	
	For(i,a,b) {
		if(ABD[i]>= L && ABD[i]<=R) cnt++;
	}
	
	cout << cnt ; 


}






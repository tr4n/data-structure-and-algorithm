#include<stdio.h>
#include<conio.h>
#include<Math.h>
//Chuyen doi ngay
//Lay Ngày Julius
long getJulius(int intNgay, int intThang, int intNam)
{
int a, y, m, jd;
a = (int)((14 - intThang) / 12);
y = intNam + 4800 - a;
m = intThang + 12 * a - 3;
jd = intNgay + (int)((153 * m + 2) / 5) + 365 * y + (int)(y / 4)  - (int)(y / 100) + (int)(y / 400) - 32045;
if (jd < 2299161)
{
jd = intNgay + (int)((153 * m + 2) / 5) + 365 * y + (int)(y / 4)  - 32083;
}
return jd;
}
 
// Tinh ngay Soc
int getNewMoonDay(int k){
float PI = 3.14;
double T, T2, T3, dr, Jd1, M, Mpr, F, C1, deltat, JdNew;
T = k / 1236.85;
T2 = T * T;
T3 = T2 * T;
dr = PI / 180;
double timeZone = 7.0;
Jd1 = 2415020.75933 + 29.53058868 * k + 0.0001178 * T2 - 0.000000155 * T3;
// Mean new moon
Jd1 = Jd1 + 0.00033 * sin((166.56 + 132.87 * T - 0.009173 * T2) * dr);
// Sun's mean anomaly
M = 359.2242 + 29.10535608 * k - 0.0000333 * T2 - 0.00000347 * T3;
// Moon's mean anomaly
Mpr = 306.0253 + 385.81691806 * k + 0.0107306 * T2 + 0.00001236 * T3;
// Moon's argument of latitude
F = 21.2964 + 390.67050646 * k - 0.0016528 * T2 - 0.00000239 * T3;
C1 = (0.1734 - 0.000393 * T) * sin(M * dr) + 0.0021 * sin(2 * dr * M);
C1 = C1 - 0.4068 * sin(Mpr * dr) + 0.0161 * sin(dr * 2 * Mpr);
C1 = C1 - 0.0004 * sin(dr * 3 * Mpr);
C1 = C1 + 0.0104 * sin(dr * 2 * F) - 0.0051 * sin(dr * (M + Mpr));
C1 = C1 - 0.0074 * sin(dr * (M - Mpr)) + 0.0004 * sin(dr * (2 * F + M));
C1 = C1 - 0.0004 * sin(dr * (2 * F - M)) - 0.0006 * sin(dr * (2 * F + Mpr));
C1 = C1 + 0.0010 * sin(dr * (2 * F - Mpr)) + 0.0005 * sin(dr * (2 * Mpr + M));
if (T < -11)
{
deltat = 0.001 + 0.000839 * T + 0.0002261 * T2 - 0.00000845 * T3 - 0.000000081 * T * T3;
}
else
{
deltat = -0.000278 + 0.000265 * T + 0.000262 * T2;
}
JdNew = Jd1 + C1 - deltat;
return (int)(JdNew + 0.5 + timeZone / 24);
}
//Tính toa do mat troi
int getSunLongitude(int jdn){
double timeZone = 7.0;
float PI = 3.14;
double T, T2, dr, M, L0, DL, L;
// Time in Julian centuries from 2000-01-01 12:00:00 GMT
T = (jdn - 2451545.5 - timeZone / 24) / 36525;
T2 = T * T;
// degree to radian
dr = PI / 180;
// mean anomaly, degree
M = 357.52910 + 35999.05030 * T - 0.0001559 * T2 - 0.00000048 * T * T2;
// mean longitude, degree
L0 = 280.46645 + 36000.76983 * T + 0.0003032 * T2;
DL = (1.914600 - 0.004817 * T - 0.000014 * T2) * sin(dr * M);
DL = DL + (0.019993 - 0.000101 * T) * sin(dr * 2 * M) + 0.000290 * sin(dr * 3 * M);
L = L0 + DL; // true longitude, degree
L = L * dr;
// Normalize to (0, 2*PI)
L = L - PI * 2 * (int)(L / (PI * 2));
return (int)(L / PI * 6);
}
// Tìm ngày bat dau tháng 11 am lich
int getLunarMonthll(int intNam){
double k, off, nm, sunLong;
off = getJulius(31, 12, intNam) - 2415021;
k = (int)(off / 29.530588853);
nm = getNewMoonDay((int)k);
// sun longitude at local midnight
sunLong = getSunLongitude((int)nm);
if (sunLong >= 9)
{
nm = getNewMoonDay((int)k - 1);
}
return (int)nm;
}
//Xác dinh thang nhuan
int getLeapMonthOffset(double a11){
double last, arc;
int k, i;
k = (int)((a11 - 2415021.076998695) / 29.530588853 + 0.5);
last = 0;
// We start with the month following lunar month 11
i = 1;
arc = getSunLongitude((int)getNewMoonDay((int)(k + i)));
do
{
last = arc;
i++;
arc = getSunLongitude((int)getNewMoonDay((int)(k + i)));
} while (arc != last && i < 14);
return i - 1;
}
//Doi ra ngay am-duong
int convertSolar2Lunar(int intNgay, int intThang, int intNam){
double dayNumber, monthStart, a11, b11, lunarDay, lunarMonth, lunarYear;
//double lunarLeap;
int k, diff;
dayNumber = getJulius(intNgay,intThang,intNam);
k = (int)((dayNumber - 2415021.076998695) / 29.530588853);
monthStart = getNewMoonDay(k + 1);
if (monthStart > dayNumber)
{
monthStart = getNewMoonDay(k);
}
a11 = getLunarMonthll(intNam);
b11 = a11;
if (a11 >= monthStart)
{
lunarYear = intNam;
a11 = getLunarMonthll(intNam - 1);
}
else
{
lunarYear = intNam + 1;
b11 = getLunarMonthll(intNam + 1);
}
lunarDay = dayNumber - monthStart + 1;
diff = (int)((monthStart - a11) / 29);
//lunarLeap = 0;
lunarMonth = diff + 11;
if (b11 - a11 > 365)
{
int leapMonthDiff = getLeapMonthOffset(a11);
if (diff >= leapMonthDiff)
{
lunarMonth = diff + 10;
if (diff == leapMonthDiff)
{
//lunarLeap = 1;
}
}
}
if (lunarMonth > 12)
{
lunarMonth = lunarMonth - 12;
}
if (lunarMonth >= 11 && diff < 4)
{
lunarYear -= 1;
}
int Ngay = int(lunarDay);
int Thang = int(lunarMonth);
int Nam = int(lunarYear);
return printf("\n Ngay am: %d/%d/%d",Ngay, Thang, Nam);
}
main()
{
int intNgay, intThang, intNam;
printf("\n Nhap vao ngay: ");
scanf("%d",&intNgay);
printf("\n Nhap vao thang: ");
scanf("%d",&intThang);
printf("\n Nhap vao nam: ");
scanf("%d",&intNam);
convertSolar2Lunar(intNgay,intThang,intNam);
getch();
} 

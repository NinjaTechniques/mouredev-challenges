#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

class CustomDate {
private:
    int day;
    int month;
    int year;

public:
    CustomDate (){
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
   
    CustomDate (int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void setDay(int day){ this->day = day;}
    void setMonth(int month){ this->month = month;}
    void setYear(int year){ this->year = year;}

    int getDay () {return day;}
    int getMonth () {return month;}
    int getYear () {return year;}
};

/*Matriz de dias*/
int daysTable (int day, int month){
    int array[31][12];

    array[0][0] = 1;
    array[0][1] = 32;
    array[0][2] = 60;
    array[0][3] = 91;
    array[0][4] = 121;
    array[0][5] = 152;
    array[0][6] = 182;
    array[0][7] = 213;
    array[0][8] = 244;
    array[0][9] = 274;
    array[0][10] = 305;
    array[0][11] = 335;

    array[1][0] = 2;
    array[1][1] = 33;
    array[1][2] = 61;
    array[1][3] = 92;
    array[1][4] = 122;
    array[1][5] = 153;
    array[1][6] = 183;
    array[1][7] = 214;
    array[1][8] = 245;
    array[1][9] = 275;
    array[1][10] = 306;
    array[1][11] = 336;

    array[2][0] = 3;
    array[2][1] = 34;
    array[2][2] = 62;
    array[2][3] = 93;
    array[2][4] = 123;
    array[2][5] = 154;
    array[2][6] = 184;
    array[2][7] = 215;
    array[2][8] = 246;
    array[2][9] = 276;
    array[2][10] = 307;
    array[2][11] = 337;

    array[3][0] = 4;
    array[3][1] = 35;
    array[3][2] = 63;
    array[3][3] = 94;
    array[3][4] = 124;
    array[3][5] = 155;
    array[3][6] = 185;
    array[3][7] = 216;
    array[3][8] = 247;
    array[3][9] = 277;
    array[3][10] = 308;
    array[3][11] = 338;

    array[4][0] = 5;
    array[4][1] = 36;
    array[4][2] = 64;
    array[4][3] = 95;
    array[4][4] = 125;
    array[4][5] = 156;
    array[4][6] = 186;
    array[4][7] = 217;
    array[4][8] = 248;
    array[4][9] = 278;
    array[4][10] = 309;
    array[4][11] = 339;

    array[5][0] = 6;
    array[5][1] = 37;
    array[5][2] = 65;
    array[5][3] = 96;
    array[5][4] = 126;
    array[5][5] = 157;
    array[5][6] = 187;
    array[5][7] = 218;
    array[5][8] = 249;
    array[5][9] = 279;
    array[5][10] = 310;
    array[5][11] = 340;

    array[6][0] = 7;
    array[6][1] = 38;
    array[6][2] = 66;
    array[6][3] = 97;
    array[6][4] = 127;
    array[6][5] = 158;
    array[6][6] = 188;
    array[6][7] = 219;
    array[6][8] = 250;
    array[6][9] = 280;
    array[6][10] = 311;
    array[6][11] = 341;

    array[7][0] = 8;
    array[7][1] = 39;
    array[7][2] = 67;
    array[7][3] = 98;
    array[7][4] = 128;
    array[7][5] = 159;
    array[7][6] = 189;
    array[7][7] = 220;
    array[7][8] = 251;
    array[7][9] = 281;
    array[7][10] = 312;
    array[7][11] = 342;

    array[8][0] = 9;
    array[8][1] = 40;
    array[8][2] = 68;
    array[8][3] = 99;
    array[8][4] = 129;
    array[8][5] = 160;
    array[8][6] = 190;
    array[8][7] = 221;
    array[8][8] = 252;
    array[8][9] = 282;
    array[8][10] = 313;
    array[8][11] = 343;

    array[9][0] = 10;
    array[9][1] = 41;
    array[9][2] = 69;
    array[9][3] = 100;
    array[9][4] = 130;
    array[9][5] = 161;
    array[9][6] = 191;
    array[9][7] = 222;
    array[9][8] = 253;
    array[9][9] = 283;
    array[9][10] = 314;
    array[9][11] = 344;

    array[10][0] = 11;
    array[10][1] = 42;
    array[10][2] = 70;
    array[10][3] = 101;
    array[10][4] = 131;
    array[10][5] = 162;
    array[10][6] = 192;
    array[10][7] = 223;
    array[10][8] = 254;
    array[10][9] = 284;
    array[10][10] = 315;
    array[10][11] = 345;

    array[11][0] = 12;
    array[11][1] = 43;
    array[11][2] = 71;
    array[11][3] = 102;
    array[11][4] = 132;
    array[11][5] = 163;
    array[11][6] = 193;
    array[11][7] = 224;
    array[11][8] = 255;
    array[11][9] = 285;
    array[11][10] = 316;
    array[11][11] = 346;

    array[12][0] = 13;
    array[12][1] = 44;
    array[12][2] = 72;
    array[12][3] = 103;
    array[12][4] = 133;
    array[12][5] = 164;
    array[12][6] = 194;
    array[12][7] = 225;
    array[12][8] = 256;
    array[12][9] = 286;
    array[12][10] = 317;
    array[12][11] = 347;

    array[13][0] = 14;
    array[13][1] = 45;
    array[13][2] = 73;
    array[13][3] = 104;
    array[13][4] = 134;
    array[13][5] = 165;
    array[13][6] = 195;
    array[13][7] = 226;
    array[13][8] = 257;
    array[13][9] = 287;
    array[13][10] = 318;
    array[13][11] = 348;

    array[14][0] = 15;
    array[14][1] = 46;
    array[14][2] = 74;
    array[14][3] = 105;
    array[14][4] = 135;
    array[14][5] = 166;
    array[14][6] = 196;
    array[14][7] = 227;
    array[14][8] = 258;
    array[14][9] = 288;
    array[14][10] = 319;
    array[14][11] = 349;

    array[15][0] = 16;
    array[15][1] = 47;
    array[15][2] = 75;
    array[15][3] = 106;
    array[15][4] = 136;
    array[15][5] = 167;
    array[15][6] = 197;
    array[15][7] = 228;
    array[15][8] = 259;
    array[15][9] = 289;
    array[15][10] = 320;
    array[15][11] = 350;

    array[16][0] = 17;
    array[16][1] = 48;
    array[16][2] = 76;
    array[16][3] = 107;
    array[16][4] = 137;
    array[16][5] = 168;
    array[16][6] = 198;
    array[16][7] = 229;
    array[16][8] = 260;
    array[16][9] = 290;
    array[16][10] = 321;
    array[16][11] = 351;

    array[17][0] = 18;
    array[17][1] = 49;
    array[17][2] = 77;
    array[17][3] = 108;
    array[17][4] = 138;
    array[17][5] = 169;
    array[17][6] = 199;
    array[17][7] = 230;
    array[17][8] = 261;
    array[17][9] = 291;
    array[17][10] = 322;
    array[17][11] = 352;

    array[18][0] = 19;
    array[18][1] = 50;
    array[18][2] = 78;
    array[18][3] = 109;
    array[18][4] = 139;
    array[18][5] = 170;
    array[18][6] = 200;
    array[18][7] = 231;
    array[18][8] = 262;
    array[18][9] = 292;
    array[18][10] = 323;
    array[18][11] = 353;

    array[19][0] = 20;
    array[19][1] = 51;
    array[19][2] = 79;
    array[19][3] = 110;
    array[19][4] = 140;
    array[19][5] = 171;
    array[19][6] = 201;
    array[19][7] = 232;
    array[19][8] = 263;
    array[19][9] = 293;
    array[19][10] = 324;
    array[19][11] = 354;

    array[20][0] = 21;
    array[20][1] = 52;
    array[20][2] = 80;
    array[20][3] = 111;
    array[20][4] = 141;
    array[20][5] = 172;
    array[20][6] = 202;
    array[20][7] = 233;
    array[20][8] = 264;
    array[20][9] = 294;
    array[20][10] = 325;
    array[20][11] = 355;

    array[21][0] = 22;
    array[21][1] = 53;
    array[21][2] = 81;
    array[21][3] = 112;
    array[21][4] = 142;
    array[21][5] = 173;
    array[21][6] = 203;
    array[21][7] = 234;
    array[21][8] = 265;
    array[21][9] = 295;
    array[21][10] = 326;
    array[21][11] = 356;

    array[22][0] = 23;
    array[22][1] = 54;
    array[22][2] = 82;
    array[22][3] = 113;
    array[22][4] = 143;
    array[22][5] = 174;
    array[22][6] = 204;
    array[22][7] = 235;
    array[22][8] = 266;
    array[22][9] = 296;
    array[22][10] = 327;
    array[22][11] = 357;

    array[23][0] = 24;
    array[23][1] = 55;
    array[23][2] = 83;
    array[23][3] = 114;
    array[23][4] = 144;
    array[23][5] = 175;
    array[23][6] = 205;
    array[23][7] = 236;
    array[23][8] = 267;
    array[23][9] = 297;
    array[23][10] = 328;
    array[23][11] = 358;

    array[24][0] = 25;
    array[24][1] = 56;
    array[24][2] = 84;
    array[24][3] = 115;
    array[24][4] = 145;
    array[24][5] = 176;
    array[24][6] = 206;
    array[24][7] = 237;
    array[24][8] = 268;
    array[24][9] = 298;
    array[24][10] = 329;
    array[24][11] = 359;

    array[25][0] = 26;
    array[25][1] = 57;
    array[25][2] = 85;
    array[25][3] = 116;
    array[25][4] = 146;
    array[25][5] = 177;
    array[25][6] = 207;
    array[25][7] = 238;
    array[25][8] = 269;
    array[25][9] = 299;
    array[25][10] = 330;
    array[25][11] = 360;

    array[26][0] = 27;
    array[26][1] = 58;
    array[26][2] = 86;
    array[26][3] = 117;
    array[26][4] = 147;
    array[26][5] = 178;
    array[26][6] = 208;
    array[26][7] = 239;
    array[26][8] = 270;
    array[26][9] = 300;
    array[26][10] = 331;
    array[26][11] = 361;

    array[27][0] = 28;
    array[27][1] = 59;
    array[27][2] = 87;
    array[27][3] = 118;
    array[27][4] = 148;
    array[27][5] = 179;
    array[27][6] = 209;
    array[27][7] = 240;
    array[27][8] = 271;
    array[27][9] = 301;
    array[27][10] = 332;
    array[27][11] = 362;

    array[28][0] = 29;
    array[28][1] = 0;
    array[28][2] = 88;
    array[28][3] = 119;
    array[28][4] = 149;
    array[28][5] = 180;
    array[28][6] = 210;
    array[28][7] = 241;
    array[28][8] = 272;
    array[28][9] = 302;
    array[28][10] = 333;
    array[28][11] = 363;

    array[29][0] = 30;
    array[29][1] = 0;
    array[29][2] = 89;
    array[29][3] = 120;
    array[29][4] = 150;
    array[29][5] = 181;
    array[29][6] = 211;
    array[29][7] = 242;
    array[29][8] = 273;
    array[29][9] = 303;
    array[29][10] = 334;
    array[29][11] = 364;

    array[30][0] = 31;
    array[30][1] = 0;
    array[30][2] = 90;
    array[30][3] = 0;
    array[30][4] = 151;
    array[30][5] = 0;
    array[30][6] = 212;
    array[30][7] = 243;
    array[30][8] = 0;
    array[30][9] = 304;
    array[30][10] = 0;
    array[30][11] = 365;

    return array[day - 1][month - 1];
}

/*Validar si hay años bisiestos*/
bool isLeapYear (int year) {
        if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0){
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}


/*Cantidad de dias bisiestos (adicionales) encontrados entre las 2 fechas*/
int leapDaysBetweenDates (int highestYear, int lowestYear){ //year 1(mayor) - year 2(menor)
    int counter;
    int leapDays = 0;

    for (int i = lowestYear; i <= highestYear; counter) {
        counter = 0;
        if (i % 4 == 0) {
            if (isLeapYear(i)) { leapDays++; }
            counter += 4;
        }
        counter++;
    }
}


/*Calcular el total de dias entre 2 fechas*/
int totalDays (CustomDate highestDate, CustomDate lowestDate) { //date 1(mayor) - date 2(menor)
    const int DAYS_PER_YEAR = 365;
    int total = 0;

    //Cantidad de dias que transcurre desde el inicio del año hasta la fecha 1 menos los 365 dias del año
    //-> Este año no se contabiliza al sacar el "total", es decir, se debe restar 1.
    int dayshighestDate = DAYS_PER_YEAR - daysTable(highestDate.getDay(), highestDate.getMonth());

    //Cantidad de dias que transcurre desde el inicio del año hasta la fecha 2
    int dayslowestDate = daysTable(lowestDate.getDay(), lowestDate.getMonth());

    total = dayshighestDate + dayslowestDate + (((highestDate.getYear() - lowestDate.getYear()) - 1) * DAYS_PER_YEAR);

    return total;
}




map<int, pair<string, CustomDate>> theLengendOfZeldaGames (){
    map<int, pair<string, CustomDate>> games; 

    games[1] = {"The Legend of Zelda: Tears of the Kingdom", CustomDate(12, 5, 2023)};
    games[2] = {"The Legend of Zelda: Skyward Sword HD", CustomDate(16,7,2021)};
    games[3] = {"The Legend of Zelda: Link's Awakening", CustomDate(20,9,2019)};
    games[4] = {"Cadence of Hyrule - Crypt of the NecroDancer featuring The Legend of Zelda", CustomDate(13,6,2019)};
    games[5] = {"The Legend of Zelda: Breath of the Wild", CustomDate(3,3,2017)};
    games[6] = {"The Legend of Zelda: Skyward Sword Wii", CustomDate(1,9,2016)};
    games[7] = {"The Legend of Zelda: Twilight Princess HD", CustomDate(4,3,2016)};
    games[8] = {"The Legend of Zelda: Tri Force Heroes", CustomDate(23,10,2015)};
    games[9] = {"The Legend of Zelda: Majora's Mask 3D", CustomDate(13,2,2015)};
    games[10] = {"The Legend of Zelda: A Link Between Worlds", CustomDate(22,11,2013)};
    games[11] = {"The Legend of Zelda: The Wind Waker HD", CustomDate(4,10,2013)};

    return games;
}


int main (){
    system("cls");
    cout << "Legend of Zelda" << endl;

    cout << endl;
    return 0;
}
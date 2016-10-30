// SHIP
// Runs on TM4C123
// TREVOR UND NEIL
// Last modification date: TODAY
// Last Modified: TODAY

// Analog Input connected to PE0-PE3, ADC0, Sequencer 2
// displays on Sitronox ST7735

#include <stdint.h>
#include "ST7735.h"
#include "TExaS.h"
#include "ADC.h"
#include "print.h"
#include "tm4c123gh6pm.h"
#include "LCD.h"
#include "Systick.h"
#include "DrawCommands.h"
#include "ShipVariableStuff.h"
#include <stdlib.h>
#include "Collisions.h"
#include "Notes.h"
#include "Sound.h"

int Direction = 0;						//Used to control ship Bitmap
int CompareDirection = 0;				//Used to determine if erasing exhaust pixels is neccissary
int Exhaust = 0;							//Used for Making the fire look cool
int ExhaustToggle = 0;				//Used for turning the fire off
int Flying = 0;								//Used to determine if direction is being asserted for ship
int Shooting = 0;							//Used to determine if direction is being asserted for shooting
int ShootingDelay = 0;				//Used to half the number of bullets/tick
int PositionUpdateStatus = 0;
int NormalSquare = 0;
int MaxScore = 300;
int Score = 0;
short BeenHit = 0;
int LastScore = 0;
int UsedBomb = 0;
short BombsLeft = 3;
const unsigned short HighText[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x07DF,
 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000,
 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF,
 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x07DF,
 0x07DF, 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x0000,
 0x0000, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07DF, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,

};
const unsigned short LastText[] = {
 0x07DF, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x07DF,
 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x07DF, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x07DF,
 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,


};

const unsigned short MaxText[] = {
 0x07DF, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000,
 0x07DF, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000,
 0x0000, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000,
 0x0000, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x07DF, 0x0000,
 0x07DF, 0x0000, 0x0000, 0x07DF,

};


const unsigned short ScoreText[] = {
 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000,
 0x0000, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x07DF, 0x0000,
 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x07DF, 0x0000,
 0x07DF, 0x0000, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x0000,
 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x07DF,
 0x07DF, 0x07DF, 0x0000, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,

};
const unsigned short BombsText[] = {
 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000,
 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000,
 0x07DF, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x07DF,
 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x0000,
 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x07DF, 0x07DF, 0x07DF, 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x0000, 0x07DF, 0x07DF,
 0x0000, 0x0000, 0x07DF, 0x07DF, 0x0000, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000,
 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x07DF, 0x07DF, 0x07DF, 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x07DF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,

};

	const unsigned short SquareRootTable[301] = {
	50,100,141,173,200,224,245,265,283,300,316,
	332,346,361,374,387,400,412,424,436,447,
	458,469,480,490,500,510,520,529,539,548,
	557,566,574,583,592,600,608,616,624,632,
	640,648,656,663,671,678,686,693,700,707,
	714,721,728,735,742,748,755,762,768,775,
	781,787,794,800,806,812,819,825,831,837,
	843,849,854,860,866,872,877,883,889,894,
	900,906,911,917,922,927,933,938,943,949,
	954,959,964,970,975,980,985,990,995,1000,
	1005,1010,1015,1020,1025,1030,1034,1039,1044,1049,
	1054,1058,1063,1068,1072,1077,1082,1086,1091,1095,
	1100,1105,1109,1114,1118,1122,1127,1131,1136,1140,
	1145,1149,1153,1158,1162,1166,1170,1175,1179,1183,
	1187,1192,1196,1200,1204,1208,1212,1217,1221,1225,
	1229,1233,1237,1241,1245,1249,1253,1257,1261,1265,
	1269,1273,1277,1281,1285,1288,1292,1296,1300,1304,
	1308,1311,1315,1319,1323,1327,1330,1334,1338,1342,
	1345,1349,1353,1356,1360,1364,1367,1371,1375,1378,
	1382,1386,1386,1393,1396,1400,1404,1407,1411,1414,
	1418,1421,1425,1428,1432,1435,1439,1442,1446,1449,
	1453,1456,1459,1463,1466,1470,1473,1476,1480,1483,
	1487,1490,1493,1497,1500,1503,1507,1510,1513,1517,
	1520,1523,1526,1530,1533,1536,1539,1543,1546,1549,
	1552,1556,1559,1562,1565,1568,1572,1575,1578,1581,
	1584,1587,1591,1594,1597,1600,1603,1606,1609,1612,
	1616,1619,1622,1625,1628,1631,1634,1637,1640,1643,
	1646,1649,1652,1655,1658,1661,1664,1667,1670,1673,
	1676,1679,1682,1685,1688,1691,1694,1697,1700,1703,
	1706,1709,1712,1715,1718,1720,1723,1726,1729,1732
};

Vector	PositionStick[2];
Vector  ADCAveraging[6];  // placeholder for averaging adc
Vector  PositionReal[2];
Vector 	NormalShootingVelocity = {0,0};

Entity Grid = {{0,0},{0,0},{0,0},{0,0},1};														//Floating Point (100)
Entity Shoot[MAXSHOOT];
Entity Asteroid[MAXASTEROID];
Entity Star[MAXSTAR];
Entity Fire[MAXFIRE];
Entity Point[MAXPOINT];
Entity Diamond[MAXDIAMOND];

Interaction Collision[MAXCOLLISION];

//==================================================
//Internal Function Definitions
//Used along with
//DrawCommands.c for outputting Entity bitmaps
//ST7735.c for communicating with LCD
//ADC.c for reading thumbsticks
//Systick.c for init
//Assembly files Print.s and LCD.s are used by ST7735.c for low-level operations
//--------------------------------------------------
//SysTick mainly for updating Positions using Velocity
void SysTick_Handler(void){
	Exhaust = (Exhaust+1)%8; //Make the fire look cool
	
	if(UsedBomb>0){
		switch(UsedBomb%2){
			case 0:
				ST7735_InvertDisplay(1);
				break;
			case 1:
				ST7735_InvertDisplay(0);
				break;
		}
		UsedBomb--;
	}
	
	if(Direction==8){Flying = FALSE;} //Flying yes or no, doesnt update positions with grid Velocities if no.
	else{Flying = TRUE;}								
	
	if(Shooting == TRUE){
		if(ShootingDelay==TRUE){SpawnShoot(); ShootingDelay=FALSE;}
		else{ShootingDelay=TRUE;}
	}
	if(ENEMYSPAWN == TRUE){
		if( (rand()%LEGENDARYSCORE+ASTEROIDFREQUENCY ) > (LEGENDARYSCORE)){
			SpawnAsteroid();
		}
		//if( (rand()%(LEGENDARYSCORE+DIAMONDFREQUENCY)) > (LEGENDARYSCORE)){
		//	SpawnDiamond();
		//}
	}
	SpawnStar();
	MailUpdate();
	
	PositionUpdateStatus = 1;
	NVIC_ST_CTRL_R &= ~(0x00010000);
}

//---------------------------------------------------------------
//Moves data every game tick to update positions and bitmaps
void PositionUpdate(void){
	
		CompareDirection = Direction;																							//saves Direction
		Direction = PositionReal[1].x * PositionReal[1].y;													//Updates Direction	
	
		if(Direction != CompareDirection){ST7735_FillRect(71,56,18,17,0x0);}		
				//deletes left-over pixels from the exhaust with a black square	
		if(Direction == 8){ExhaustToggle = 0;}		//turns off exhaust if direction is not asserted
		else{ExhaustToggle = 1;}
		
	//=====================
	//Start of entity position update
	if(PositionUpdateStatus == 1){   //Update Positions only if systick has been called
		//Grid Position Update, Only used for Drawing the grid if debug is on and a direction is asserted		
		if(Debug>=1){							
		Grid.OldPosition = Grid.Position;
		Grid.Position = Grid.Mail;
		DrawGrid(Grid.Position.x/100,Grid.Position.y/100,Grid.OldPosition.x/100,Grid.OldPosition.y/100);
		}
		//-----------------------------------------------
		CollisionCheck();			//Check Collisions and delete Particles and set velocities
		if(Collision[0].k > 0){CollisionExecute();}
		//----------------------------------------
		//Update and draw Stars
		for(int i=0;i<MAXSTAR;i++){
			if(Star[i].Life==1){
				Star[i].OldPosition = Star[i].Position;
				Star[i].Position = Star[i].Mail;
				DrawStar(Star[i].Position.x/100,Star[i].Position.y/100,Star[i].OldPosition.x/100,Star[i].OldPosition.y/100);
			}
		}
		//----------------------------------------
		/*Update and draw Alien
		Alien.OldPosition = Alien.Position; 
		
		if(Alien.Mail.x < 0){Alien.Position.x = 16000+Alien.Mail.x;}	//Correct for negative positions
		else{Alien.Position.x = Alien.Mail.x;}
		if(Alien.Mail.y < 0){Alien.Position.y = 12800+Alien.Mail.y;}
		else{Alien.Position.y = Alien.Mail.y;}
		
		DrawAlien(Alien.Position.x/100,Alien.Position.y/100,Alien.OldPosition.x/100,Alien.OldPosition.y/100);*/
		
		
		//----------------------------------------
		//Update and draw Shoots
		for(int i=0;i<MAXSHOOT;i++){
			if(Shoot[i].Life==1){
				Shoot[i].OldPosition = Shoot[i].Position;
				Shoot[i].Position = Shoot[i].Mail;
				DrawShoot(Shoot[i].Position.x/100,Shoot[i].Position.y/100,Shoot[i].OldPosition.x/100,Shoot[i].OldPosition.y/100);
			}
		}
		//-----------------------------------------
		//Update and draw Asteroids
		for(int i=0;i<MAXASTEROID;i++){
			if(Asteroid[i].Life==1){
				Asteroid[i].OldPosition = Asteroid[i].Position;
				Asteroid[i].Position = Asteroid[i].Mail;
				DrawAsteroid(Asteroid[i].Position.x/100,Asteroid[i].Position.y/100,Asteroid[i].OldPosition.x/100,Asteroid[i].OldPosition.y/100);
			}
		}
		//---------------------------------------
		//Update and draw Fire from colisions
		for(int i =0;i<MAXFIRE;i++){
			if(Fire[i].Life == 1){
				DrawFire(Fire[i].Position.x/100,Fire[i].Position.y/100);
				if(Fire[i].SpecCode.x <0){
					Fire[i].Life = 0;
					ST7735_FillRect(Fire[i].Position.x/100,Fire[i].Position.y/100-FIRESIDELENGTH,FIRESIDELENGTH+1,FIRESIDELENGTH+2,0x00);
				}
			}
		}
		//--------------------------------------
		//Update and draw points
		for(int i = 0;i<MAXPOINT;i++){
			if(Point[i].Life == 1){
				Point[i].OldPosition = Point[i].Position;
				Point[i].Position = Point[i].Mail;
				
				DrawPoint(Point[i].Position.x/100,Point[i].Position.y/100,Point[i].OldPosition.x/100,Point[i].OldPosition.y/100);
				if(Point[i].SpecCode.y <0){
					Point[i].Life = 0;
					ST7735_FillRect(Point[i].Position.x/100-1,Point[i].Position.y/100-POINTSIDELENGTH-1,POINTSIDELENGTH+2,POINTSIDELENGTH+2,0x00);
				}
			}
		}
		//--------------------
		//Update and draw Diamond
		/*for(int i = 0;i<MAXDIAMOND;i++){
			if(Diamond[i].Life == 1){
				Diamond[i].OldPosition = Diamond[i].Position;
				Diamond[i].Position = Diamond[i].Mail;
				
				DrawDiamond(Diamond[i].Position.x/100,Diamond[i].Position.y/100,Diamond[i].OldPosition.x/100,Diamond[i].OldPosition.y/100);
				if(Diamond[i].SpecCode.x <=0){
					Diamond[i].Life = 0;
					ST7735_FillRect(Diamond[i].Position.x/100-1,Diamond[i].Position.y/100-DIAMONDSIDELENGTH-1,DIAMONDSIDELENGTH+2,DIAMONDSIDELENGTH+2,0x00);
				}
			}
		}*/
		PositionUpdateStatus = 0;
	}
}

void InitializeStars(void){
		for(int i = 0; i<MAXSTAR; i++){
				Star[i].Position.x = rand()%(EDGEXMAX*100+1);
				Star[i].Position.y = rand()%(EDGEYMAX*100+1);
				Star[i].OldPosition = Star[i].Position;
				Star[i].SpecCode.x = (rand()%STARDISTANCE)+1;
				Star[i].Life = 1;
				DrawStar(Star[i].Position.x/100,Star[i].Position.y/100,0,0);
		}
}
void Bomb(void){
	static short Latch = FALSE;
	int Counter = 0;
	if((GPIO_PORTE_DATA_R&0x10)>0){
		if(Latch == FALSE){
			if(BombsLeft>0){
				for(int i=0;i<MAXASTEROID;i++){
					if(Asteroid[i].Life ==1){
						Counter++;
						Collision[Counter].i = 0;
						Collision[Counter].j = i;
						Collision[Counter].k = 1;
					}
				}
				Collision[0].k = Counter;
				CollisionExecute();
				Latch = TRUE;
				UsedBomb = BOMBFLASH;
				BombsLeft--;
			}
		}
	}
  else{Latch = FALSE;}
}
void OutStats(void){
	ST7735_DrawBitmap(0,5,ScoreText,22,5);
	ST7735_SetCursor(5,0); ST7735_OutUDec(Score);
	ST7735_DrawBitmap(0,16,LastText,16,7);
  ST7735_SetCursor(5,1); ST7735_OutUDec(LastScore);
	ST7735_DrawBitmap(0,28,HighText,19,9);
	ST7735_SetCursor(5,2); ST7735_OutUDec(MaxScore);
	ST7735_DrawBitmap(99,6,BombsText,24,7);
  ST7735_SetCursor(15,0); ST7735_OutUDec(BombsLeft);
}
//Main
//Runs Constantly
//--------------------------------------------------
int main(void){
	srand(SEED);
	DisableInterrupts();
  TExaS_Init();
	ADC_Init();
	DAC_Init();
	SysTick_Init(Period);
	ST7735_InitR(INITR_REDTAB);
	ST7735_SetRotation(3);				//Everything is counting on this orientation.
	InitializeStars();
	EnableInterrupts();
	
	while(1){
		
		Bomb();
		if(Debug >= 2){DebugThumbsticks();}
		AverageADCIn();
		ConvertRawADC();
		PositionUpdate();
		DrawShip(Direction);
		if(DRAWSCORE == TRUE){OutStats();}
	}
}





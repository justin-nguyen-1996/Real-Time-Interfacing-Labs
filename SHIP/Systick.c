#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "ExternVariables.h"
#include <stdlib.h>
#include "ST7735.h"

void SysTick_Init(int period){
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_CTRL_R = 0x6;
	NVIC_ST_RELOAD_R = period;
	NVIC_ST_CURRENT_R = 0;
	NVIC_SYS_PRI3_R |= 0x80000000;     //Priority 4
	NVIC_ST_CTRL_R |= 0x1;
}


//Called by SysTick to update Mail Positions and kill entities off screen
//Definitions to loop the grid to make it look as though always moving
#define GRIDXLOOP 3000
#define GRIDYLOOP 3000
void MailUpdate(void){
	if(BeenHit>0){Flying = 0;}
	//------------------
	//Grid Position update
	if(Debug>=1){																					//Only need to update grid position if drawing it.
		Grid.Mail.x = (Grid.Position.x - Grid.Velocity.x*Flying)%GRIDXLOOP;	
		Grid.Mail.y = (Grid.Position.y - Grid.Velocity.y*Flying)%GRIDYLOOP;
	}
	
	//Alien.Mail.x = (Alien.Position.x + Alien.Velocity.x + Grid.Velocity.x*Flying)%16000;	//little testing Alien
	//Alien.Mail.y = (Alien.Position.y + Alien.Velocity.y + Grid.Velocity.y*Flying)%12800;
	
	//------------------
	//Shoot Update
	for(int i=0;i<MAXSHOOT;i++){
		if(Shoot[i].Life==1){
			Shoot[i].Mail.x = (Shoot[i].Position.x - Shoot[i].Velocity.x + Grid.Velocity.x*Flying);	
			Shoot[i].Mail.y = (Shoot[i].Position.y - Shoot[i].Velocity.y + Grid.Velocity.y*Flying);
			
			if(Shoot[i].Mail.x<(EDGEXMIN*100)){Shoot[i].Life=0;}	//Kill the Shoot if it is offscreen
			if(Shoot[i].Mail.x>(EDGEXMAX*100)){Shoot[i].Life=0;}
			if(Shoot[i].Mail.y<(EDGEYMIN*100)){Shoot[i].Life=0;}
			if(Shoot[i].Mail.y>(EDGEYMAX*100)){Shoot[i].Life=0;}
		}
	}
	//-------------------
	//Asteroid Update
	for(int i=0;i<MAXASTEROID;i++){
		if(Asteroid[i].Life==1){
			Asteroid[i].Mail.x = (Asteroid[i].Position.x - Asteroid[i].Velocity.x + Grid.Velocity.x*Flying);	
			Asteroid[i].Mail.y = (Asteroid[i].Position.y - Asteroid[i].Velocity.y + Grid.Velocity.y*Flying);
			
			if(Asteroid[i].Mail.x<(EDGEXMIN*100)){Asteroid[i].Life=0;}	//Kill the Asteroid if it is offscreen
			if(Asteroid[i].Mail.x>(EDGEXMAX*100)){Asteroid[i].Life=0;}
			if(Asteroid[i].Mail.y<(EDGEYMIN*100)){Asteroid[i].Life=0;}
			if(Asteroid[i].Mail.y>(EDGEYMAX*100)){Asteroid[i].Life=0;}
		}
	}
	//---------------------
	//Star Update
	for(int i=0;i<MAXSTAR;i++){
		if(Star[i].Life==1){
			Star[i].Mail.x = (Star[i].Position.x + (Grid.Velocity.x*Flying)/(Star[i].SpecCode.x+1));	
			Star[i].Mail.y = (Star[i].Position.y + (Grid.Velocity.y*Flying)/(Star[i].SpecCode.x+1));
			
			if(Star[i].Mail.x<(EDGEXMIN*100)){Star[i].Life=0;}	//Kill the Star if it is offscreen
			if(Star[i].Mail.x>(EDGEXMAX*100)){Star[i].Life=0;}
			if(Star[i].Mail.y<(EDGEYMIN*100)){Star[i].Life=0;}
			if(Star[i].Mail.y>(EDGEYMAX*100)){Star[i].Life=0;}
		}
	}
	//----------------------
	//Fire Update
	for(int i=0;i<MAXFIRE;i++){
		if(Fire[i].Life == 1){
			Fire[i].SpecCode.x --;
			}
		}
	//----------------------
	//Point Update
		for(int i = 0;i<MAXPOINT;i++){
			if(Point[i].Life == 1){
				
				signed int a, b;
				a= SHIPXCENTER*100 - (Point[i].Position.x+POINTSIDELENGTH*50);
				b= SHIPYCENTER*100 - (Point[i].Position.y-POINTSIDELENGTH*50);
				
				if(Point[i].SpecCode.x == 1){
						Point[i].Velocity.x = POINTMAXVELOCITY*a/(SquareRootTable[(a*a+b*b)/10000]);
						Point[i].Velocity.y = POINTMAXVELOCITY*b/(SquareRootTable[(a*a+b*b)/10000]);
				}
				else{
					Point[i].Velocity.x -= Point[i].Velocity.x/POINTVELOCITYDECAY;
					Point[i].Velocity.y -= Point[i].Velocity.y/POINTVELOCITYDECAY;
					Point[i].SpecCode.y --;
				}
				
			//	if(Point[i].Velocity.x >	POINTMAXVELOCITY||Point[i].Velocity.x < -POINTMAXVELOCITY){Point[i].Velocity.x = POINTMAXVELOCITY*a/SquareRootTable[(a*a+b*b)/10000];}
			//	if(Point[i].Velocity.y >	POINTMAXVELOCITY||Point[i].Velocity.y < -POINTMAXVELOCITY){Point[i].Velocity.y = POINTMAXVELOCITY*b/SquareRootTable[(a*a+b*b)/10000];}
				Point[i].Mail.x = (Point[i].Position.x + Point[i].Velocity.x + Grid.Velocity.x*Flying);
				Point[i].Mail.y = (Point[i].Position.y + Point[i].Velocity.y + Grid.Velocity.y*Flying);
				
				
				if(
						Point[i].Mail.x<(EDGEXMIN*100) ||
						Point[i].Mail.x>(EDGEXMAX*100) ||
						Point[i].Mail.y<(EDGEYMIN*100) ||
						Point[i].Mail.y>(EDGEYMAX*100) ){
							Point[i].SpecCode.y =-1;
				}
		}
	}
		//---------------------------
	//Diamond Update
	/*for(int i = 0;i<MAXDIAMOND;i++){
		if(Diamond[i].Life == 1){
				
				signed int a, b;
				a= SHIPXCENTER*100 - (Diamond[i].Position.x+DIAMONDSIDELENGTH*50);
				b= SHIPYCENTER*100 - (Diamond[i].Position.y-DIAMONDSIDELENGTH*50);
			
				a=a*100/b;
				b=100;
				
				Point[i].Velocity.x = DIAMONDMAXVELOCITY*a/(SquareRootTable[(a*a+b*b)/10000]);
				Point[i].Velocity.y = DIAMONDMAXVELOCITY*b/(SquareRootTable[(a*a+b*b)/10000]);

				Diamond[i].Mail.x = (Diamond[i].Position.x + Diamond[i].Velocity.x + Grid.Velocity.x*Flying);
				Diamond[i].Mail.y = (Diamond[i].Position.y + Diamond[i].Velocity.y + Grid.Velocity.y*Flying);
				
				
				if(
						Diamond[i].Mail.x<(EDGEXMIN*100) ||
						Diamond[i].Mail.x>(EDGEXMAX*100) ||
						Diamond[i].Mail.y<(EDGEYMIN*100) ||
						Diamond[i].Mail.y>(EDGEYMAX*100) ){
							Diamond[i].Life = 0;
				}
		}
	}*/
}

//=====================================================
//=====================================================
//Called by SysTick every-other triggering for the Spawning of shoots
void SpawnShoot(void){
			for(int i=0;i<MAXSHOOT;i++){
				if(Shoot[i].Life==0){
					Shoot[i].Position.x = 8000;
					Shoot[i].Position.y = 6400;
					Shoot[i].Velocity.x = NormalShootingVelocity.x*SHOOTVELOCITY + Grid.Velocity.x*Flying/2;
					Shoot[i].Velocity.y = NormalShootingVelocity.y*SHOOTVELOCITY + Grid.Velocity.y*Flying/2;
					Shoot[i].Life = 1;
					i = MAXSHOOT;
				}
			}
		}
//--------------------------------------------------
//Called by systick as defined by ASTEROIDFREQUENCY to spawn asteroids
void SpawnAsteroid(void){
	Vector V;
	int Normal;
		for(int i = 0; i<MAXASTEROID; i++){
			if(Asteroid[i].Life == 0){
				switch(rand()%4){
					case 0: //Spawn above
						Asteroid[i].Position.x = rand()%(EDGEXMAX*100+1);
						Asteroid[i].Position.y = (EDGEYMIN + 1)*100;
					
						V.x = (rand()%2001-1000);
						V.y = -500;
						break;
					case 1: //Spawn to right
						Asteroid[i].Position.x =  (EDGEXMAX - 1)*100;
						Asteroid[i].Position.y = rand()%(EDGEYMAX*100+1);
			
						V.x = 500;
						V.y = (rand()%2000-1000);
						break;
					case 2:	//Spawn below
						Asteroid[i].Position.x =  rand()%(EDGEXMAX*100+1);
						Asteroid[i].Position.y = (EDGEYMAX - 1)*100;
			
						V.x = (rand()%2000-1000);
						V.y = 500;

						break;
					case 3: //Spawn to left
						Asteroid[i].Position.x =  (EDGEXMIN + 1)*100;
						Asteroid[i].Position.y = rand()%(EDGEYMAX*100+1);
			
						V.x = -500;
						V.y = (rand()%2000-1000);

						break;
				}
				Normal = SquareRootTable[(V.x*V.x+V.y*V.y)/10000];						
				Asteroid[i].Velocity.x = V.x*ASTEROIDVELOCITY/Normal;
				Asteroid[i].Velocity.y = V.y*ASTEROIDVELOCITY/Normal;
				Asteroid[i].Life = 1;
				i = MAXASTEROID;
			}
		}
}
//-------------------------------------------------------
//Spawns stars
void SpawnStar(void){
		for(int i = 0; i<MAXSTAR; i++){
			if(Star[i].Life == 0){
				switch(rand()%4){
					case 0: //Spawn above
						Star[i].Position.x = rand()%(EDGEXMAX*100+1);
						Star[i].Position.y = (EDGEYMIN + 1)*100;
						break;
					case 1: //Spawn to right
						Star[i].Position.x =  (EDGEXMAX - 1)*100;
						Star[i].Position.y = rand()%(EDGEYMAX*100+1);
						break;
					case 2:	//Spawn below
						Star[i].Position.x =  rand()%(EDGEXMAX*100+1);
						Star[i].Position.y = (EDGEYMAX - 1)*100;
						break;
					case 3: //Spawn to left
						Star[i].Position.x =  (EDGEXMIN + 1)*100;
						Star[i].Position.y = rand()%(EDGEYMAX*100+1);
						break;
				
				}
				Star[i].SpecCode.x = (rand()%STARDISTANCE)+1;
				Star[i].Life = 1;
				

			}
		}
}
//------------------------
//Spawn Fire at collisions
void SpawnFire(signed int X,signed int Y){
	for(int i = 0; i<MAXFIRE; i++){
			if(Fire[i].Life == 0){
				Fire[i].Life = 1;
				Fire[i].Position.x = X;
				Fire[i].Position.y = Y;
				Fire[i].Mail.x = X;
				Fire[i].Mail.y = Y;
				Fire[i].Velocity.x = 0;
				Fire[i].Velocity.y = 0;
				Fire[i].SpecCode.x = 7;
				i=MAXFIRE;
			}
		}
}
void SpawnPoint(signed int X, signed int Y){
	for(int i = 0; i<MAXPOINT; i++){
		if(Point[i].Life == 0){
			Point[i].Life = 1;
			Point[i].Position.x = X;
			Point[i].Position.y = Y;
			Point[i].Mail.x = X;
			Point[i].Mail.y = Y;
			if(rand()%2 == 0){Point[i].Velocity.x = (rand()%MAXPOINTSPAWNVELOCITY+MINPOINTSPAWNVELOCITY);}
			else{Point[i].Velocity.x = -(rand()%MAXPOINTSPAWNVELOCITY+MINPOINTSPAWNVELOCITY);}
			if(rand()%2 == 0){Point[i].Velocity.y = (rand()%MAXPOINTSPAWNVELOCITY+MINPOINTSPAWNVELOCITY);}
			else{Point[i].Velocity.y = -(rand()%MAXPOINTSPAWNVELOCITY+MINPOINTSPAWNVELOCITY);}
			Point[i].SpecCode.x = 0;
			Point[i].SpecCode.y = rand()%POINTLIFEMAX+POINTLIFEMIN;
			i = MAXPOINT;
			
		}
	}
	
}
/*void SpawnDiamond(void){
	for(int i = 0; i<MAXDIAMOND; i++){
			if(Asteroid[i].Life == 0){
				switch(rand()%4){
					case 0: //Spawn above
						Diamond[i].Position.x = rand()%(EDGEXMAX*100+1);
						Diamond[i].Position.y = (EDGEYMIN + 1)*100;
					
						break;
					case 1: //Spawn to right
						Diamond[i].Position.x =  (EDGEXMAX - 1)*100;
						Diamond[i].Position.y = rand()%(EDGEYMAX*100+1);
					
						break;
					case 2:	//Spawn below
						Diamond[i].Position.x =  rand()%(EDGEXMAX*100+1);
						Diamond[i].Position.y = (EDGEYMAX - 1)*100;

						break;
					case 3: //Spawn to left
						Diamond[i].Position.x =  (EDGEXMIN + 1)*100;
						Diamond[i].Position.y = rand()%(EDGEYMAX*100+1);

						break;
				}
				Diamond[i].SpecCode.x = DIAMONDLIFE;
				Diamond[i].Life = 1;
				i = MAXDIAMOND;
			}
		}
}*/


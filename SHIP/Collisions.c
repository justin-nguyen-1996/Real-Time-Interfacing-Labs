#include "ExternVariables.h"
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "DrawCommands.h"
#include "Systick.h"

void CollisionCheck(void){
	int Counter = 0;
	//--------------------
	//Check Asteroids against ship
	for(int i=0;i<MAXASTEROID;i++){
		Vector Ci = {Asteroid[i].Mail.x+ASTEROIDSIDELENGTH*50,Asteroid[i].Mail.y-ASTEROIDSIDELENGTH*50};
		Vector Cj	= {SHIPXCENTER*100,SHIPYCENTER*100};
		if(			//Asteroid[i].Mail.x >= (SHIPXPOSITION-SHIPSIDELENGTH*3)*100 &&
						//Asteroid[i].Mail.x <= (SHIPXPOSITION+SHIPSIDELENGTH*3)*100 &&
						//Asteroid[i].Mail.y >= (SHIPYPOSITION-SHIPSIDELENGTH*3)*100 &&
						//Asteroid[i].Mail.y <= (SHIPYPOSITION+SHIPSIDELENGTH*3)*100
					( (((Ci.x-Cj.x)<=500)&&((Ci.x-Cj.x)>=-500)) || (((Cj.x-Ci.x)<=500)&&((Cj.x-Ci.x)>=-500)) ) &&
					( (((Ci.y-Cj.y)<=500)&&((Ci.y-Cj.y)>=-500)) || (((Cj.y-Ci.y)<=500)&&((Cj.y-Ci.y)>=-500)) )
						){
				if(Asteroid[i].Life ==1 &&
						((Asteroid[i].SpecCode.x == 1 && Asteroid[i].SpecCode.y != -1) || (Asteroid[i].SpecCode.x == 0))){
							if(SquareRootTable[(( (Ci.x-Cj.x)*(Ci.x-Cj.x) )+( (Ci.y-Cj.y)*(Ci.y-Cj.y) ))/10000] <= SHIPHITBOX){  //Distance Formula
									Counter ++;
									Collision[Counter].i = i;
									Collision[Counter].k = 0; //0 stands for Asteroid -> SHIP collision
									Asteroid[i].SpecCode.x = 1;
									Asteroid[i].SpecCode.y = -1;
						 	}
				}
				
		 }
		 else{if(Asteroid[i].SpecCode.x==1&&Asteroid[i].SpecCode.y==-1){Asteroid[i].SpecCode.x=0;}}
	}
	//--------------------
	//Check Bullets against Asteroids
	for(int i=0;i<MAXSHOOT;i++){
		if(Shoot[i].Life == 1){
			for(int j=0;j<MAXASTEROID;j++){
				if(Asteroid[j].Life ==1 &&
					 Shoot[i].Mail.x >=(Asteroid[j].Mail.x-SHOOTSIDELENGTH*100) &&
					 Shoot[i].Mail.x <=(Asteroid[j].Mail.x+ASTEROIDSIDELENGTH*100) &&
					 Shoot[i].Mail.y >=(Asteroid[j].Mail.y-ASTEROIDSIDELENGTH*100) &&
					 Shoot[i].Mail.y <=(Asteroid[j].Mail.y+SHOOTSIDELENGTH*100)
					){
						Counter ++;
						Collision[Counter].i = i;
						Collision[Counter].j = j;
						Collision[Counter].k = 1; //1 stands for Shoot -> Asteroid interaction

					}
			}
		}
	}
	//-------------------
	//Check Asteroids vs Asteroids
	for(int i=0;i<MAXASTEROID;i++){
		if(Asteroid[i].Life ==1)
			for(int j = i+1;j<MAXASTEROID;j++){
				Vector Ci = {Asteroid[i].Mail.x+ASTEROIDSIDELENGTH*50,Asteroid[i].Mail.y-ASTEROIDSIDELENGTH*50};
				Vector Cj	= {Asteroid[j].Mail.x+ASTEROIDSIDELENGTH*50,Asteroid[j].Mail.y-ASTEROIDSIDELENGTH*50};
				if( ( (((Ci.x-Cj.x)<=500)&&((Ci.x-Cj.x)>=-500)) || (((Cj.x-Ci.x)<=500)&&((Cj.x-Ci.x)>=-500)) ) &&
					( (((Ci.y-Cj.y)<=500)&&((Ci.y-Cj.y)>=-500)) || (((Cj.y-Ci.y)<=500)&&((Cj.y-Ci.y)>=-500)) )
						){
					if(Asteroid[j].Life ==1 &&
						((Asteroid[i].SpecCode.x == 1 && Asteroid[i].SpecCode.y != j) || (Asteroid[i].SpecCode.x == 0))){
								if(SquareRootTable[(( (Ci.x-Cj.x)*(Ci.x-Cj.x) )+( (Ci.y-Cj.y)*(Ci.y-Cj.y) ))/10000] <= ASTEROIDHITBOX){  //Distance Formula
									Counter ++;
									Collision[Counter].i = i;
									Collision[Counter].j = j;
									Collision[Counter].k = 2; //2 stands for Asteroid -> Asteroid collision
									Asteroid[i].SpecCode.x = 1;
									Asteroid[i].SpecCode.y = j;
								}
					}				
				}
				else{if(Asteroid[i].SpecCode.x==1&&Asteroid[i].SpecCode.y==j){Asteroid[i].SpecCode.x=0;}}
		   }
	   }
	//-------------------------
	//Check Points vs Ship
	for(int i=0;i<MAXPOINT;i++){
		if(Point[i].Life ==1){
				Vector Ci = {Point[i].Position.x+POINTSIDELENGTH*50,Point[i].Position.y-POINTSIDELENGTH*50};
				Vector Cj	= {SHIPXCENTER*100,SHIPYCENTER*100};
				if( ( (((Ci.x-Cj.x)<=POINTMAGNETRANGE)&&((Ci.x-Cj.x)>=-POINTMAGNETRANGE)) || (((Cj.x-Ci.x)<=POINTMAGNETRANGE)&&((Cj.x-Ci.x)>=-POINTMAGNETRANGE)) ) &&
					( (((Ci.y-Cj.y)<=POINTMAGNETRANGE)&&((Ci.y-Cj.y)>=-POINTMAGNETRANGE)) || (((Cj.y-Ci.y)<=POINTMAGNETRANGE)&&((Cj.y-Ci.y)>=-POINTMAGNETRANGE)) )
						){
								Point[i].SpecCode.x = 1;
								Point[i].SpecCode.y = POINTLIFEMIN+POINTLIFEMAX;
								if(SquareRootTable[(( (Ci.x-Cj.x)*(Ci.x-Cj.x) )+( (Ci.y-Cj.y)*(Ci.y-Cj.y) ))/10000] <= SHIPHITBOX/2){  //Distance Formula
									Counter ++;
									Collision[Counter].i = i;
									Collision[Counter].j = 0;
									Collision[Counter].k = 3; //3 stands for Point -> Ship collision
								
					}				
				}
				else{Point[i].SpecCode.x = 0;}
		   }
	   }
	Collision[0].k = Counter; //First element is how many collisions there are this run.
}

void CollisionExecute(void){
		for(int Counter = Collision[0].k;Counter>0;Counter--){
			
			int i = Collision[Counter].i; //make everything easier to type
			int j = Collision[Counter].j;
			int k = Collision[Counter].k;
			
			int a,b,c,d; //used as value holders in calculations; mainly asteroid -> asteroid collisions
			Vector Temp1;
			Vector Temp2;
			Vector Calc1;
			Vector Calc2;
			
			switch(k){
	//--------------------------------------------------
				case 0:						 //Asteroid to ship collision
					if(Score >=20){LastScore = Score;
													ST7735_SetCursor(0,1);
													ST7735_OutString("           ");}
					if(Score>MaxScore){MaxScore=Score;}
					Score = 0;
					BombsLeft = 3;
					ST7735_SetCursor(0,0);
					ST7735_OutString("          ");
					BeenHit = 100;
					//Asteroid[i].Life = 0; 												//asteroid dies 
					//ST7735_FillRect(Asteroid[i].Position.x/100, Asteroid[i].Position.y/100-ASTEROIDSIDELENGTH,ASTEROIDSIDELENGTH+1, ASTEROIDSIDELENGTH+1, 0x0);
					 Calc1.x = Asteroid[i].Position.x + ASTEROIDSIDELENGTH*50;
					 Calc1.y = Asteroid[i].Position.y - ASTEROIDSIDELENGTH*50;
				   Calc2.x = SHIPXCENTER*100;
				   Calc2.y = SHIPYCENTER*100;
				
					 a = (Calc1.x-Calc2.x)*(Calc1.x-Calc2.x)+(Calc1.y-Calc2.y)*(Calc1.y-Calc2.y);						// ||P1-P2||^2
					
					 c = ((Asteroid[i].Velocity.x-Grid.Velocity.x*Flying)*(Calc1.x-Calc2.x) +		// <(v1-v2),(P1-P2)>
							 (Asteroid[i].Velocity.y-Grid.Velocity.y*Flying)*(Calc1.y-Calc2.y));
	
					 Temp1.x = Asteroid[i].Velocity.x - ( (c)*(Calc1.x-Calc2.x)/a) ;              //fp10000*fp100/fp10000 = fp100
					 Temp1.y = Asteroid[i].Velocity.y - ( (c)*(Calc1.y-Calc2.y)/a);
					 
					 Asteroid[i].Velocity.x = (Temp1.x*ASTEROIDVELOCITY)/SquareRootTable[((Temp1.x*Temp1.x)+(Temp1.y*Temp1.y))/10000]+Grid.Velocity.x*Flying;
					 Asteroid[i].Velocity.y = (Temp1.y*ASTEROIDVELOCITY)/SquareRootTable[((Temp1.x*Temp1.x)+(Temp1.y*Temp1.y))/10000]+Grid.Velocity.y*Flying;
					 
					 SpawnFire(Calc1.x-FIRESIDELENGTH*50,Calc1.y+FIRESIDELENGTH*50);		
					break;
//---------------------------------------------------
				case 1:            //Shoot to Asteroid collision
					Shoot[i].Life = 0;
					Asteroid[j].Life = 0;
					ST7735_FillRect(Shoot[i].Position.x/100, Shoot[i].Position.y/100-SHOOTSIDELENGTH,SHOOTSIDELENGTH+1, SHOOTSIDELENGTH+1, 0x0);
					ST7735_FillRect(Asteroid[j].Position.x/100, Asteroid[j].Position.y/100-ASTEROIDSIDELENGTH,ASTEROIDSIDELENGTH+1, ASTEROIDSIDELENGTH+1, 0x0);
				
											
					SpawnPoint(Asteroid[j].Position.x,Asteroid[j].Position.y);
					SpawnPoint(Asteroid[j].Position.x,Asteroid[j].Position.y);
					SpawnPoint(Asteroid[j].Position.x,Asteroid[j].Position.y);
					SpawnPoint(Asteroid[j].Position.x,Asteroid[j].Position.y);
					break;
//-----------------------------------------------------
				case 2:						 //Asteroid to Asteroid collision
					 Calc1.x = Asteroid[i].Position.x + ASTEROIDSIDELENGTH*50;
					 Calc1.y = Asteroid[i].Position.y - ASTEROIDSIDELENGTH*50;
				   Calc2.x = Asteroid[j].Position.x + ASTEROIDSIDELENGTH*50;
				   Calc2.y = Asteroid[j].Position.y - ASTEROIDSIDELENGTH*50;
				
					 a = (Calc1.x-Calc2.x)*(Calc1.x-Calc2.x)+(Calc1.y-Calc2.y)*(Calc1.y-Calc2.y);						// ||P1-P2||^2
					 b = (Calc2.x-Calc1.x)*(Calc2.x-Calc1.x)+(Calc2.y-Calc1.y)*(Calc2.y-Calc1.y);						// ||P2-P1||^2
					
					 c = ((Asteroid[i].Velocity.x-Asteroid[j].Velocity.x)*(Calc1.x-Calc2.x) +		// <(v1-v2),(P1-P2)>
							 (Asteroid[i].Velocity.y-Asteroid[j].Velocity.y)*(Calc1.y-Calc2.y));
					 d = ((Asteroid[j].Velocity.x-Asteroid[i].Velocity.x)*(Calc2.x-Calc1.x) +		// <(v2-v1),(P2-P1)>
							 (Asteroid[j].Velocity.y-Asteroid[i].Velocity.y)*(Calc2.y-Calc1.y));
				
					 Temp1.x = Asteroid[i].Velocity.x - ( (c)*(Calc1.x-Calc2.x)/a);               //fp10000*fp100/fp10000 = fp100
					 Temp1.y = Asteroid[i].Velocity.y - ( (c)*(Calc1.y-Calc2.y)/a);
					 
					 Temp2.x = Asteroid[j].Velocity.x - ( (d)*(Calc2.x-Calc1.x)/b);
					 Temp2.y = Asteroid[j].Velocity.y - ( (d)*(Calc2.y-Calc1.y)/b);
						if(MOMENTUMDISABLE == TRUE){
							Asteroid[i].Velocity.x = (Temp1.x*ASTEROIDVELOCITY)/SquareRootTable[((Temp1.x*Temp1.x)+(Temp1.y*Temp1.y))/10000];
							Asteroid[i].Velocity.y = (Temp1.y*ASTEROIDVELOCITY)/SquareRootTable[((Temp1.x*Temp1.x)+(Temp1.y*Temp1.y))/10000];
							Asteroid[j].Velocity.x = (Temp2.x*ASTEROIDVELOCITY)/SquareRootTable[((Temp2.x*Temp2.x)+(Temp2.y*Temp2.y))/10000]; 
							Asteroid[j].Velocity.y = (Temp2.y*ASTEROIDVELOCITY)/SquareRootTable[((Temp2.x*Temp2.x)+(Temp2.y*Temp2.y))/10000];
						}
						else{
							Asteroid[i].Velocity.x = Temp1.x;
							Asteroid[i].Velocity.y = Temp1.y;
							Asteroid[j].Velocity.x = Temp2.x; 
							Asteroid[j].Velocity.y = Temp2.y;
						}
					 break;
//-------------------------------------------------------
					case 3:						//Point to Ship collision
						Point[i].Life = 0;
						ST7735_FillRect(Point[i].Position.x/100-1,Point[i].Position.y/100-POINTSIDELENGTH-1,POINTSIDELENGTH+2,POINTSIDELENGTH+2,0x00);
						Score ++;
						if(Score%BOMBGAINSCORE == 0){BombsLeft++;}
				
				default:
				break;
			}
		}
		Collision[0].k = 0;
}

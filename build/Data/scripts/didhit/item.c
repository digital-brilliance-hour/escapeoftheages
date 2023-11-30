#include "data/scripts/levelup/lvup.c"

void main() {
	void self = getlocalvar("self"); //get the self var
	void hit = getlocalvar("damagetaker"); // get target entity
	char Name = getentityproperty(self,"name"); // get target's name
	void power = getentityproperty(hit,"mp"); // get target's current mp
    int P1 = getplayerproperty(0, "entity");
    int P2 = getplayerproperty(1, "entity");
	int SFX2 = loadsample("data/sounds/life-up.wav");
	int SFX3 = loadsample("data/sounds/full-power.wav");
	int SFX4 = loadsample("data/sounds/full-life.wav");
	int SFX5 = loadsample("data/sounds/power-life.wav");

	switch(Name) {
		case "Apple":
		int SFX2 = loadsample("data/sounds/life-up.wav");
        playsample(SFX2, 0, 120, 120, 100, 0);
		spawnAni("aitemFX",0,30,0,"ANI_IDLE",NULL(),NULL(),NULL());		
			break;
		case "Meal":
		int SFX4 = loadsample("data/sounds/full-life.wav");
        playsample(SFX4, 0, 120, 120, 100, 0);
		spawnAni("aitemFX",0,30,0,"ANI_FOLLOW3",NULL(),NULL(),NULL());		
			break;
		case "tutorialmeat":
			jumptobranch("",1);
			break;
		case "powerupitem1":
		case "powerupitem2":
		case "powerupitem3":
		int SFX1 = loadsample("data/sounds/powerup.wav");
		void bg = "data/music/powerup.ogg";
		spawnTextAni("poweruptext",1,1,0,"ANI_IDLE",NULL(),NULL(),NULL());
		playsample(SFX1, 0, 120, 120, 100, 0);
 		playmusic(bg, 0);
 		if(P1) {
	    	lvup(P1);
	    }
	    if(P2) {
	    	lvup(P2);

	    }
			break;
		default:
			break;
	}

}

void spawnAni(void vName, float fX, float fY, float fZ, void Ani, float Vx, float Vy, float Vz)
{
	//spawnB (Generic spawner) + Specific animation + velocities
	//Damon Vaughn Caskey + Douglas Baldan
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing left?                  
          fX = -fX; //Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
    performattack(vSpawn, openborconstant(Ani)); 
	changeentityproperty(vSpawn, "velocity", Vx, Vy, Vz);

	return vSpawn; //Return spawn.
}

void spawnTextAni(void vName, float fX, float fY, float fZ, void Ani, float Vx, float Vy, float Vz)
{
	//spawnB (Generic spawner) + Specific animation + velocities
	//Damon Vaughn Caskey + Douglas Baldan
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");
    loadmodel(vName); // name of the entity to be loaded

	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", vName); //Acquire spawn entity by name.
    //setspawnentry("coords", 1,1,1); // set the position of the entity

      fX = openborvariant("xpos"); //Get X location and add adjustment.
      //fY = openborvariant("ypos"); //Get Y location and add adjustment.
      fZ = openborvariant("ypos"); //Get Z location and add adjustment.
      log(fX);
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	//changeentityproperty(vSpawn, "direction", 1); //Set direction.
    performattack(vSpawn, openborconstant(Ani)); 
	//changeentityproperty(vSpawn, "velocity", Vx, Vy, Vz);

	return vSpawn; //Return spawn.
}

void spawnAniMap(void vName, float fX, float fY, float fZ, void Ani, int iControl)
{
	//spawnB (Generic spawner) + Specific animation + velocities + map
	//Damon Vaughn Caskey + Douglas Baldan
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");
    int  iMap = getentityproperty(self, "map"); // Get caller's remap.

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing left?                  
          fX = -fX; //Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	//changeentityproperty(vSpawn, "direction", iDirection); //Set direction.

	if (iControl){
	changeentityproperty(vSpawn, "map", iMap); //Set map.
	}
    performattack(vSpawn, openborconstant(Ani)); 
	//changeentityproperty(vSpawn, "velocity", Vx, Vy, Vz);

	return vSpawn; //Return spawn.
}

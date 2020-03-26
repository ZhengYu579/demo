#include "music.h"

void ka_nong(void){
	int hp[] = {0,C1,D1,E1,F1,G1,A1,B1};
	int mp[] = {0,C2,D2,E2,F2,G2,A2,B2};
	int lp[] = {0,C3,D3,E3,F3,G3,A3,B3};
	speaker_pwm_config();
	play(hp[3],T/4);
	mdelay(T/4);
	play(hp[2],T/4);
	mdelay(T/4);
	
	play(hp[1],T/4);
	mdelay(T/4);
	play(mp[7],T/4);
	mdelay(T/4);
	
	play(mp[6],T/4);
	mdelay(T/4);
	play(mp[5],T/4);
	mdelay(T/4);
	
	play(mp[6],T/4);
	mdelay(T/4);
	play(mp[7],T/4);
	mdelay(T/4);
	
	play(hp[1],T/4);
	mdelay(T/4);
	play(mp[7],T/4);
	mdelay(T/4);
	
	play(mp[6],T/4);
	mdelay(T/4);
	play(mp[5],T/4);
	mdelay(T/4);
	
	play(mp[4],T/4);
	mdelay(T/4);
	play(mp[3],T/4);
	mdelay(T/4);
	
	play(mp[4],T/4);
	mdelay(T/4);
	play(mp[2],T/4);
	mdelay(T/4);
	
	play(hp[1],T/8);
	play(mp[7],T/8);
	play(hp[1],T/8);
	play(mp[1],T/8);
	
	play(lp[7],T/8);
	play(mp[5],T/8);
	play(mp[2],T/8);
	play(mp[3],T/8);
	
	play(mp[1],T/8);
	play(hp[1],T/8);
	play(mp[7],T/8);
	play(mp[6],T/8);
	
	play(mp[7],T/8);
	play(hp[3],T/8);
	play(hp[5],T/8);
	play(hp[6],T/8);
	
	play(hp[4],T/8);
	play(hp[3],T/8);
	play(hp[2],T/8);
	play(hp[4],T/8);
	
	play(hp[4],T/8);
	play(hp[3],T/8);
	play(hp[1],T/8);
	play(mp[7],T/8);
	
	play(mp[6],T/8);
	play(mp[5],T/8);
	play(mp[4],T/8);
	play(mp[3],T/8);
	
	play(mp[2],T/8);
	play(mp[4],T/8);
	play(mp[3],T/8);
	play(mp[2],T/8);
	
	play(mp[1],T/8);
	play(mp[2],T/8);
	play(mp[3],T/8);
	play(mp[4],T/8);
	
	play(mp[5],T/8);
	play(mp[2],T/8);
	play(mp[5],T/8);
	play(mp[4],T/8);
	
	play(mp[3],T/8);
	play(mp[6],T/8);
	play(mp[5],T/8);
	play(mp[4],T/8);

	play(mp[5],T/8);
	play(mp[4],T/8);
	play(mp[3],T/8);
	play(mp[2],T/8);
	
	play(mp[1],T/8);
	play(lp[6],T/8);
	play(mp[6],T/8);
	play(mp[7],T/8);
	
	play(hp[1],T/8);
	play(mp[7],T/8);
	play(mp[6],T/8);
	play(mp[5],T/8);
	
	play(mp[4],T/8);
	play(mp[3],T/8);
	play(mp[2],T/8);
	play(mp[6],T/8);
	
	play(mp[5],T/8);
	play(mp[6],T/8);
	play(mp[5],T/8);
	play(mp[4],T/8);
	
	play(mp[3],T/4);
	play(hp[3],T/4);
	play(hp[2],T/4);
	mdelay(T/4);
	
	play(hp[1],T/4);
	mdelay(T/4);
	play(hp[2],T/4);
	mdelay(T/4);
	
	play(hp[1],T/4);
	play(hp[3],T/4);
	play(hp[2],T/4);
	play(hp[4],T/4);
	
	
	play(hp[5],T/8);
	play(hp[3],T/16);
	play(hp[4],T/16);
	
	play(hp[5],T/8);
	play(hp[3],T/16);
	play(hp[4],T/16);
	
	play(hp[5],T/16);
	play(mp[5],T/16);
	play(mp[6],T/16);
	play(mp[7],T/16);
	
	play(hp[1],T/16);
	play(hp[2],T/16);
	play(hp[3],T/16);
	play(hp[4],T/16);
	
	
	play(hp[3],T/8);
	play(hp[1],T/16);
	play(hp[2],T/16);
	
	play(hp[3],T/8);
	play(mp[3],T/16);
	play(mp[4],T/16);
	
	play(mp[5],T/16);
	play(mp[6],T/16);
	play(mp[5],T/16);
	play(mp[4],T/16);
	
	play(mp[5],T/16);
	play(mp[3],T/16);
	play(mp[4],T/16);
	play(mp[5],T/16);
	
	
	play(mp[4],T/8);
	play(mp[6],T/16);
	play(mp[5],T/16);
	
	play(mp[4],T/8);
	play(mp[3],T/16);
	play(mp[2],T/16);
	
	play(mp[3],T/16);
	play(mp[2],T/16);
	play(mp[1],T/16);
	play(mp[2],T/16);
	
	play(mp[3],T/16);
	play(mp[4],T/16);
	play(mp[5],T/16);
	play(mp[6],T/16);
	
	
	
}


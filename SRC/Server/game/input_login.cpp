/*

The next part it's if you have Conqueror System, if you do not have skip the part and go to the next file.

*/



//Search

#include "log.h"

//Add after

#ifdef ENABLE_QUEEN_NETHIS
#include "SnakeLair.h"
#endif

//Search

	if (g_noticeBattleZone)
	{
		if (FN_is_battle_zone(ch))
		{
			[...]
		}
	}

//Add after


#ifdef ENABLE_QUEEN_NETHIS
	if (SnakeLair::CSnk::instance().IsSnakeMap(ch->GetMapIndex()) && ch->IsPC())
	{
		ch->PointChange(POINT_MAX_HP, 0);
		ch->PointChange(POINT_MOV_SPEED, 0);

		const BYTE bSTR = SnakeLair::CSnk::instance().GetSungmaValueAffectDungeon(ch, AFFECT_SUNGMA_STR);
		const BYTE bHP = SnakeLair::CSnk::instance().GetSungmaValueAffectDungeon(ch, AFFECT_SUNGMA_HP);
		const BYTE bMOVE = SnakeLair::CSnk::instance().GetSungmaValueAffectDungeon(ch, AFFECT_SUNGMA_MOVE);
		const BYTE bINMUNE = SnakeLair::CSnk::instance().GetSungmaValueAffectDungeon(ch, AFFECT_SUNGMA_INMUNE);
		TPacketGCSungmaAttrUpdate p;

		p.bHeader = HEADER_GC_SUNGMA_ATTR_UPDATE;
		p.bSTR = bSTR;
		p.bHP = bHP;
		p.bMOVE = bMOVE;
		p.bINMUNE = bINMUNE;
		ch->GetDesc()->Packet(&p, sizeof(p));
	}
#endif

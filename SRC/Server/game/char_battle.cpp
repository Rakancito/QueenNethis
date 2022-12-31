//Search

#include "threeway_war.h"

//Add after

#ifdef ENABLE_QUEEN_NETHIS
#include "SnakeLair.h"
#endif

//Search

	if (true == IsMonster() && 2493 == GetMobTable().dwVnum)
	{
		if (NULL != pkKiller && NULL != pkKiller->GetGuild())
		{
			CDragonLairManager::instance().OnDragonDead( this, pkKiller->GetGuild()->GetID() );
		}
		else
		{
			sys_err("DragonLair: Dragon killed by nobody");
		}
	}

//Add after

#ifdef ENABLE_QUEEN_NETHIS
	if ((IsStone()) || (IsMonster()))
	{
		if (pkKiller && pkKiller->IsPC())
		{
			if (SnakeLair::CSnk::instance().IsSnakeMap(pkKiller->GetMapIndex()))
				SnakeLair::CSnk::instance().OnKill(this, pkKiller);
		}
	}
#endif

//Search

void CHARACTER::UpdateAlignment(int iAmount)
{
	bool bShow = false;

//Add after

#ifdef ENABLE_QUEEN_NETHIS
	if (IsSnakeMap() && iAmount < 0)
		return;
#endif

/*

The next part it's if you have Conqueror System, if you do not have skip the part and go to the next file.

*/


//Search

		if ((pAttacker->IsConquerorMap(pAttacker->GetMapIndex())))
		{
			if(!IsPC())
			{
				int value = pAttacker->GetPoint(POINT_SUNGMA_STR); 
				int aValue = SECTREE_MANAGER::instance().GetSungmaValueAffectByRegion(pAttacker->GetMapIndex(), AFFECT_SUNGMA_STR);
				if(value < aValue)
				{
					dam /= 2;
				}

				if (pAttacker->GetConquerorLevel() == 0)
					dam = 0;
			}
		}

//Add after

#ifdef ENABLE_QUEEN_NETHIS
		if (SnakeLair::CSnk::instance().IsSnakeMap(pAttacker->GetMapIndex()) && IsPC())
		{
			if(!IsPC())
			{
				int value = pAttacker->GetPoint(POINT_SUNGMA_STR); 
				int aValue =  SnakeLair::CSnk::instance().GetSungmaValueAffectDungeon(pAttacker, AFFECT_SUNGMA_STR);
				if(value < aValue)
				{
					dam /= 2;
				}

				if (pAttacker->GetConquerorLevel() == 0)
					dam = 0;
			}
		}
#endif
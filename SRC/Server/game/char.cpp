//Search

#include "DragonSoul.h"


//Add before or after

#ifdef ENABLE_QUEEN_NETHIS
#include "SnakeLair.h"
#endif

//Search

	m_pkChrTarget = NULL;
	m_pkMuyeongEvent = NULL;

//Add after

#ifdef ENABLE_QUEEN_NETHIS
	m_pkSnakeSkillEvent = NULL;
#endif

//Search

void CHARACTER::OnClick(LPCHARACTER pkChrCauser)
{
	if (!pkChrCauser)
	{
		sys_err("OnClick %s by NULL", GetName());
		return;
	}

	DWORD vid = GetVID();
	sys_log(0, "OnClick %s[vnum %d ServerUniqueID %d, pid %d] by %s", GetName(), GetRaceNum(), vid, GetPlayerID(), pkChrCauser->GetName());

//Add after

#ifdef ENABLE_QUEEN_NETHIS
	if ((IsNPC()) && (GetRaceNum() == (WORD)(SnakeLair::PORTAL_VNUM)) && (SnakeLair::CSnk::instance().IsSnakeMap(pkChrCauser->GetMapIndex())))
	{
		SnakeLair::CSnk::instance().Start(pkChrCauser);
		return;
	}
#endif

//Add in the end file

#ifdef ENABLE_QUEEN_NETHIS
bool CHARACTER::IsSnakeMap()
{
	return SnakeLair::CSnk::instance().IsSnakeMap(GetMapIndex());
}
#endif

/*

The next part it's if you have Conqueror System, if you do not have skip the part and go to the next file.

*/

				if (IsConquerorMap(GetMapIndex()) && IsPC())
				{
					int value = 0; 
					int aValue = 0;

					value = GetPoint(POINT_SUNGMA_HP);
					aValue = SECTREE_MANAGER::instance().GetSungmaValueAffectByRegion(GetMapIndex(), AFFECT_SUNGMA_HP); 
					if(value < aValue)
						SetMaxHP(hp + add_hp/2);
				}

//Add after

#ifdef ENABLE_QUEEN_NETHIS
				if (SnakeLair::CSnk::instance().IsSnakeMap(GetMapIndex()) && IsPC())
				{
					int value = 0; 
					int aValue = 0;

					value = GetPoint(POINT_SUNGMA_HP);
					aValue = SnakeLair::CSnk::instance().GetSungmaValueAffectDungeon(this, AFFECT_SUNGMA_HP); 
					if(value < aValue)
						SetMaxHP(hp + add_hp/2);
				}
#endif

//Search

			if (IsConquerorMap(GetMapIndex()) && IsPC())
			{
				int value = 0; 
				int aValue = 0;
				value = GetPoint(POINT_SUNGMA_MOVE);
				aValue = SECTREE_MANAGER::instance().GetSungmaValueAffectByRegion(GetMapIndex(), AFFECT_SUNGMA_MOVE); 
				if(value < aValue)
					SetPoint(type, 100);
				else
					SetPoint(type, 209);
			}

//Add after

#ifdef ENABLE_QUEEN_NETHIS
			if (SnakeLair::CSnk::instance().IsSnakeMap(GetMapIndex()) && IsPC())
			{
				int value = 0; 
				int aValue = 0;
				value = GetPoint(POINT_SUNGMA_MOVE);
				aValue = SnakeLair::CSnk::instance().GetSungmaValueAffectDungeon(this, AFFECT_SUNGMA_MOVE); 
				if(value < aValue)
					SetPoint(type, 100);
				else
					SetPoint(type, 209);
			}
#endif

//Search

bool CHARACTER::IsConquerorMap(int iMapIndex)
{
	[...]
}

//Add after
#ifdef ENABLE_QUEEN_NETHIS
int CHARACTER::GetSungmaValueAffectDungeon(int iAffect)
{
	return SnakeLair::CSnk::instance().GetSungmaValueAffectDungeon(this, iAffect);
}
#endif
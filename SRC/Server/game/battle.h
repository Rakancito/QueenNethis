//If you do not have my system Conqueror of Yohara you can skip this file.

//Search


	if (pkAttacker->GetPoint(att_point) && !pkVictim->IsAffectFlag(affect_flag))
	{

//Add after


#ifdef ENABLE_CONQUEROR_LEVEL
		if(pkAttacker->GetMobRank() >= MOB_RANK_BOSS)
		{
			if (pkVictim)
			{
				if (pkVictim->IsConquerorMap(pkVictim->GetMapIndex()) && pkVictim->IsPC())
				{

					int value = 0; 
					int aValue = 0;
					value = pkVictim->GetPoint(POINT_SUNGMA_INMUNE);
#ifdef ENABLE_QUEEN_NETHIS
					if (pkVictim->IsSnakeMap())
						aValue = pkVictim->GetSungmaValueAffectDungeon(AFFECT_SUNGMA_INMUNE);
#ifdef ENABLE_WHITE_DRAGON
					else if (pkVictim->IsWhiteMap())
						aValue = pkVictim->GetSungmaValueAffectWhiteDungeon(AFFECT_SUNGMA_INMUNE);
#endif
					else
						aValue = SECTREE_MANAGER::instance().GetSungmaValueAffectByRegion(pkVictim->GetMapIndex(), AFFECT_SUNGMA_INMUNE);
#else
					aValue = SECTREE_MANAGER::instance().GetSungmaValueAffectByRegion(pkVictim->GetMapIndex(), AFFECT_SUNGMA_INMUNE);
#endif 
					if(value < aValue)
					{
						if (number(1, 100) <= 50)
						{
							pkVictim->AddAffect(affect_idx, affect_point, affect_amount, affect_flag, time, 0, true);
		
							if (test_server)
							{
								pkVictim->ChatPacket(CHAT_TYPE_PARTY, "%s %s(%ld%%) SUCCESS", pkAttacker->GetName(), name, pkAttacker->GetPoint(att_point));
							}
						}
					}	
				}
			}
		}
		else
		{
#endif


//Search

		else if (test_server)
		{
			pkVictim->ChatPacket(CHAT_TYPE_PARTY, "%s %s(%ld%%) FAIL", pkAttacker->GetName(), name, pkAttacker->GetPoint(att_point));
		}

//Add after

#ifdef ENABLE_CONQUEROR_LEVEL
		}
#endif
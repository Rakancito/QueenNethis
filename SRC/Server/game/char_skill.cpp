//Search

int CHARACTER::ComputeSkill(DWORD dwVnum, LPCHARACTER pkVictim, BYTE bSkillLevel)

//Add before

#ifdef ENABLE_QUEEN_NETHIS
struct FuncSnakeSplashDamage
{
	FuncSnakeSplashDamage(int x, int y, LPCHARACTER pkChr, BYTE bUseSkillPower)
		:
		m_x(x), m_y(y), m_pkChr(pkChr), m_iCount(0), m_bUseSkillPower(bUseSkillPower)
		{
		}

	void operator () (LPENTITY ent)
	{
		if (!ent->IsType(ENTITY_CHARACTER))
		{
			return;
		}

		LPCHARACTER pkChrVictim = (LPCHARACTER) ent;

		if (DISTANCE_APPROX(m_x - pkChrVictim->GetX(), m_y - pkChrVictim->GetY()) > 500)
		{
			if(test_server)
				sys_log(0, "XXX target too far %s", m_pkChr->GetName());
			return;
		}

		if (!pkChrVictim->IsPC())
			return;

		++m_iCount;

		int iDam;

		iDam = pkChrVictim->GetMaxHP()*0.2;

		EDamageType dt = DAMAGE_TYPE_MELEE;
		if (!pkChrVictim->Damage(m_pkChr, iDam, dt) && !pkChrVictim->IsStun())
		{
			float fCrushSlidingLength = 200;

			if (m_pkChr->IsNPC())
				fCrushSlidingLength = 400;

			float fx, fy;
			float degree = GetDegreeFromPositionXY(m_pkChr->GetX(), m_pkChr->GetY(), pkChrVictim->GetX(), pkChrVictim->GetY());

			GetDeltaByDegree(degree, fCrushSlidingLength, &fx, &fy);
			sys_log(0, "CRUSH! %s -> %s (%d %d) -> (%d %d)", m_pkChr->GetName(), pkChrVictim->GetName(), pkChrVictim->GetX(), pkChrVictim->GetY(), (long)(pkChrVictim->GetX()+fx), (long)(pkChrVictim->GetY()+fy));
			long tx = (long)(pkChrVictim->GetX()+fx);
			long ty = (long)(pkChrVictim->GetY()+fy);

			pkChrVictim->Sync(tx, ty);
			pkChrVictim->Goto(tx, ty);
			pkChrVictim->CalculateMoveDuration();

			pkChrVictim->SyncPacket();
		}
	}

	int		m_x;
	int		m_y;
	LPCHARACTER	m_pkChr;
	int		m_iCount;
	BYTE m_bUseSkillPower;
};

EVENTINFO(r_snakeskill_info)
{
	int	x;
	int	y;
	LPCHARACTER pkVictim;
	BYTE bUseSkillPower;
};

EVENTFUNC(r_snakeskill_event)
{
	r_snakeskill_info* pEventInfo = dynamic_cast<r_snakeskill_info*>(event->info);

	if (!pEventInfo)
		return 0;

	if (!pEventInfo->pkVictim)
		return 0;

	FuncSnakeSplashDamage f(pEventInfo->x, pEventInfo->y, pEventInfo->pkVictim, 1);
	if (pEventInfo->pkVictim->GetSectree())
		pEventInfo->pkVictim->GetSectree()->ForEachAround(f);

	return 0;
}

int CHARACTER::ComputeSnakeSkill(DWORD dwVnum, LPCHARACTER pkVictim, BYTE bSkillLevel)
{
	if (!pkVictim)
		return BATTLE_NONE;

	if (m_pkSnakeSkillEvent != NULL)
		event_cancel(&m_pkSnakeSkillEvent);
	m_pkSnakeSkillEvent = NULL;

	int iAG = 0;

	r_snakeskill_info* pEventInfo = AllocEventInfo<r_snakeskill_info>();

	pEventInfo->x =pkVictim->GetX();
	pEventInfo->y =pkVictim->GetY();
	pEventInfo->pkVictim =this;
	pEventInfo->bUseSkillPower = 1;
	m_pkSnakeSkillEvent = event_create(r_snakeskill_event, pEventInfo, PASSES_PER_SEC(2));

	return BATTLE_NONE;	
}
#endif


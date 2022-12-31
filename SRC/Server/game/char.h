//Search

void				ComputePassiveSkill(DWORD dwVnum);

//Add after

#ifdef ENABLE_QUEEN_NETHIS
		int					ComputeSnakeSkill(DWORD dwVnum, LPCHARACTER pkVictim, BYTE bSkillLevel);
#endif

//Search

		LPEVENT				m_pkMuyeongEvent;

//Add after

#ifdef ENABLE_QUEEN_NETHIS
		LPEVENT				m_pkSnakeSkillEvent;
#endif

//Search

};

ESex GET_SEX(LPCHARACTER ch);

#endif

//Add before

#ifdef ENABLE_QUEEN_NETHIS
	public:
		bool			IsSnakeMap();
#endif

/*

The next part it's if you have Conqueror System, if you do not have skip the part and go to the next file.

*/

//Search

		bool			IsConquerorMap(int iMapIndex);

//Add after
#ifdef ENABLE_QUEEN_NETHIS
		int			GetSungmaValueAffectDungeon(int iAffect);
#endif
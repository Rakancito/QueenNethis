// Just if you do not have the struct "FCountMonsters" add before the function "size_t SECTREE_MANAGER::GetMonsterCountInMap"

struct FCountMonsters
{
	std::map<VID, VID> m_map_Monsters;

	void operator() (LPENTITY ent)
	{
		if ( ent->IsType(ENTITY_CHARACTER) == true )
		{
			LPCHARACTER lpChar = (LPCHARACTER)ent;

			if ( lpChar->IsMonster() == true )
			{
				m_map_Monsters[lpChar->GetVID()] = lpChar->GetVID();
			}
		}
	}
};



/*

Search and replace the function "GetMonsterCountInMap" for this:

*/

size_t SECTREE_MANAGER::GetMonsterCountInMap(long lMapIndex, DWORD dwVnum, bool bForceVnum)
{
	LPSECTREE_MAP sectree = SECTREE_MANAGER::instance().GetMap(lMapIndex);

	if (NULL != sectree)
	{
		struct FCountSpecifiedMonster f(dwVnum, bForceVnum);

		sectree->for_each( f );

		return f.cnt;
	}

	return 0;
}

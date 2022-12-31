//If you have this function like this:

		size_t		GetMonsterCountInMap(long lMapIndex, DWORD dwVnum);

//Replace with:

		size_t		GetMonsterCountInMap(long lMapIndex, DWORD dwVnum, bool bForceVnum = false);

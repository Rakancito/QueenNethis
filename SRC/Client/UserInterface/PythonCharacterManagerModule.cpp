//Search

	PyModule_AddIntConstant(poModule, "EFFECT_LOVE_PENDANT_EQUIP",		CInstanceBase::EFFECT_LOVE_PENDANT_EQUIP);

//Add after

#ifdef ENABLE_QUEEN_NETHIS
	PyModule_AddIntConstant(poModule, "EFFECT_SNAKE_REGEN", CInstanceBase::EFFECT_SNAKE_REGEN);
#endif
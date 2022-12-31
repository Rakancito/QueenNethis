//Search

		case SE_EQUIP_LOVE_PENDANT:
			effect = CInstanceBase::EFFECT_LOVE_PENDANT_EQUIP;
			break;

//Add after

#ifdef ENABLE_QUEEN_NETHIS
		case SE_EFFECT_SNAKE_REGEN:
			effect = CInstanceBase::EFFECT_SNAKE_REGEN;
			bAttachEffect = false;
			break;
#endif
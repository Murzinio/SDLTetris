#include "..\headers\Background.h"



Background::Background()
{
}


Background::~Background()
{
}

void Background::FillTexture()
{
	switch (type)
	{
	case EBackground::HONG_KONG:
		texture = textures.background_HongKong.GetSDLTexture();
		break;
	case EBackground::SUNSET:
		texture = textures.background_Sunset.GetSDLTexture();
		break;
	case EBackground::WATER:
		texture = textures.background_Water.GetSDLTexture();
		break;
	}
}
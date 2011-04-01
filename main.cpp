#include <stdio.h>
#include <stdlib.h>
#include "Map.hpp"

const char* gMapData = 
	"ssssssss\n"
	"s000000s\n"
	"ss01110s\n"
	"ss01210s\n"
	"ss01210s\n"
	"ss01110s\n"
	"ss0000ss\n"
	"ssssssss\n";

int main(int argc, char* argv[])
{
	if (argc < 3) {
		printf("usage: %s mapname depth\n", argv[0]);
		return 0;
	}

	int level = atoi(argv[2]);
	Map map("hoge", gMapData);

	map.heightcat_view(level);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "Map.hpp"

char* readFile(const char* filename)
{
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("con't open %s\n", filename);
		exit(0);
	}

	int size;
	char* ret;
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	ret = new char[size];
	if (fread(ret, sizeof(char), size, fp) != size) {
		printf("i/o error while reading %s\n", filename);
		fclose(fp);
		exit(0);
	}
	fclose(fp);
	return ret;
}

int main(int argc, char* argv[])
{
	if (argc < 3) {
		printf("usage: %s mapname depth\n", argv[0]);
		return 0;
	}

	char* map_data = readFile(argv[1]);
	int level = atoi(argv[2]);
	Map map("hoge", map_data);

	map.heightcat_view(level);

	delete[] map_data;
	return 0;
}

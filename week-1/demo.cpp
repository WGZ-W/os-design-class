
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>
#include <pthread.h>
#include <stdlib.h>

using namespace std;


int cnt;
map <string, int> mp;
int main(int argc, char *argv[])
{
	FILE *fp = fopen(argv[1], "r");
	char c;
	c = fgetc(fp);
	string w = "";
	int i = 0;
	while (c != EOF){
		if (isalpha(c))
			w += c;
		else {
			if (w == ""){
				c = fgetc(fp);
				continue;
			}
			mp[w]++;
			cnt++;
			w = "";
		}
		c = fgetc(fp);
	}
	fclose(fp);
	
	cout << "hello" << endl;
	cout << cnt << endl;
	return 0;
}



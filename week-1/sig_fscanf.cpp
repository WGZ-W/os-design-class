#include <iostream>
#include <fstream>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

using namespace std;

struct node{
	string str;
	int nu;
};

bool cmp(node &p1, node &p2)
{
	return p1.nu > p2.nu;
}

int cnt;
map <string, int> mp;
void count(void *filename)
{
	FILE *fp;
	if ((fp = fopen((char *)filename, "r")) == NULL ){
			fprintf(stderr, "Can't open %s\n", (char *)filename);
			exit(EXIT_FAILURE);
	}
	char c;
	string w = "";
	while (fscanf(fp, "%c", &c) != EOF){
		if (isalpha(c))
			w += c;
		else {
			if (w == "")
				continue;
			
			mp[w]++;
			cnt++;
			w = "";
		}
	}
	fclose(fp);

}


int main(int argc, char *argv[])
{
	clock_t start_clock = clock();

	cnt = 0;
	for (int i = 1; i < argc; i++){
		count(argv[i]);
	}
	printf("total number of words: %d\n", cnt);

	vector<node> v;
	node tmp;
	for (auto i : mp){
		tmp.str = i.first;
		tmp.nu = i.second;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);

//	for (int i = 0; i <= v.size(); i++){
	for (int i = 0; i <= 10; i++){
		cout << v[i].str << " " << v[i].nu << endl; 
	}				

	printf("Processor time used: %g sec.\n",
			(clock() - start_clock) / (double) CLOCKS_PER_SEC);

	return 0;
	
}	

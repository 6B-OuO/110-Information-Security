#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//decrypt
int main(int argc, char* argv[])
{
	//Method: caesar/playfair/vernam/railfence/row
	
	
	string method;
	string key;
	string cytext;
	string pltext;

	method = argv[2];
	cytext = argv[4];
	key = argv[6];

	//cin >> method >> cytext >> key;

	pltext.resize(cytext.length());
	//////////////////////////////////////////////////////
	if (method == "caesar") {
		//shift back
		int Ckey = stoi(key);
		
		for (int i = 0; i < cytext.length(); i++) {
			pltext[i] = (cytext[i] - 'A' + 26 - Ckey) % 26 + 'a';
		}
	}
	////////////////////////////////////////////////////////
	else if (method == "playfair") {
		//no j
		string Mkey;
		vector <bool> Mcheck(30,false); // used = true
		for (int i = 0; i < cytext.length(); i++) {
			cytext[i] = cytext[i] - 'A' + 'a';
		}
		Mkey = key;
		Mkey.resize(30);
		int Nalp;
		//check key alph
		for (int i = 0; i < key.length(); i++) {
			Mcheck[key[i] - 'a'] = true;//used
			Mcheck[9] = true;
		}
		for (int i = 0; i < 25; i++) {
			if (Mcheck[i] == 0) {
				Nalp = i;
				break;
			}
		}
		for (int i = key.length(); i < 25; i++) {
			while (Mcheck[Nalp] == true) {
				Nalp++;
			}
			Mkey[i] = Nalp + 'a';
			Mcheck[Nalp] = true;
		}
		// Mkey OK
		
		for (int i = 0; i < cytext.length(); i += 2) {
			int c1, c2;
			for (int j = 0; j < 25; j++) {
				if (cytext[i] == Mkey[j]) {
					c1 = j;
					break;
				}
			}
			for (int j = 0; j < 25; j++) {
				if (cytext[i + 1] == Mkey[j]) {
					c2 = j;
					break;
				}
			}
			if ((c1 % 5) == (c2 % 5)) {//same col ^
				c1 = (c1 + 25 - 5) % 25;
				c2 = (c2 + 25 - 5) % 25;
			}
			else if ((c2 / 5) == (c1 / 5)) {//same row <
				if ((c1 % 5) == 0) {
					c1 += 4;
				}
				else {
					c1 -= 1;
				}
				if ((c2 % 5) == 0) {
					c2 += 4;
				}
				else {
					c2 -= 1;
				}
			}
			else {//rect
				int ad;
				ad = c1 % 5 - c2 % 5;
				c1 -= ad;
				c2 += ad;
			}
			
			pltext[i] = Mkey[c1];
			pltext[i + 1] = Mkey[c2];
		}
		int len = pltext.length();
		for (int i = 0; i < len; i++) {
			if (pltext[i] == 'x') {
				pltext.erase(i, 1);
				len--; i--;
			}
		}
	}
	////////////////////////////////////////////////////////
	else if (method == "vernam") {
		for (int i = 0; i < cytext.length(); i++) {
			pltext[i] = ((cytext[i] - 'A') ^ (key[i] - 'a')) + 'a';
		}
	}
	////////////////////////////////////////////////////////
	else if (method == "railfence") {//zigzag
		int Rkey = stoi(key);
		vector <vector <int> > subpl(Rkey);

		bool dir = 1;
		for (int i = 0, Nsub = 0; i < cytext.length(); i++) {
			subpl[Nsub].push_back(i);
			if (Nsub == (Rkey - 1))
				dir = 0;
			else if (Nsub == 0)
				dir = 1;
			if (dir)
				Nsub++;
			else
				Nsub--;
		}
		vector <int> combine;
		for (int i = 0; i < Rkey; i++) {
			combine.insert(combine.end(), subpl[i].begin(), subpl[i].end());
		}

		for (int i = 0; i < cytext.length(); i++) {
			pltext[combine[i]] = cytext[i] - 'A' + 'a';
		}
	}
	////////////////////////////////////////////////////////
	else if (method == "row") {
		vector <vector <int> > subpl(key.length());
		int Nsub = 0;
		for (int i = 0; i < key.length(); i++) {
			key[i]--;
		}
		for (int i = 0; i < cytext.length(); i++) {
			subpl[(int)(key[(i % (key.length()))]-'0')].push_back(i);
		}
		vector <int> combine;
		for (int i = 0; i < key.length(); i++) {
			combine.insert(combine.end(), subpl[i].begin(), subpl[i].end());
		}

		for (int i = 0; i < cytext.length(); i++) {
			pltext[combine[i]] = cytext[i] - 'A' + 'a';
		}

	}

	cout << pltext << endl;
	return 0;
}
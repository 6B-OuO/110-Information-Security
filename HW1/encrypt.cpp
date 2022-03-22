
# include <iostream>
# include <iomanip>
# include <vector>
# include <string>
using namespace std;

int main(int argc, char* argv[])
{

	string method;
	method = argv[2];
	//input = argv[4];
	//key = argv[6];
	/////////////////////////////////////////////////
	if (method == "playfair")
	{
		string s;
		//getline(cin, s);
		s = argv[6];
		vector<vector<char>> v;
		v.resize(5);
		for (int count = 0; count < 5; count++)
		{
			v[count].resize(5);
		}
		int i = 0;
		int ii = 0;
		//vector<char> c;
		//c.resize(26);
		char c[26];
		for (int count = 'a'; count <= 'z'; count++)
		{
			c[count - 'a'] = count;
		}

		for (int count = 0; count < s.size(); count++)
		{
			if (s[count] == ' ')
			{
				count++;
			}
			if ((s[count] == 'j') && (c['i' - 'a'] != 0))
			{
				v[i][ii] = 'i';
				c['j' - 'a'] = 0;
				c['i' - 'a'] = 0;
				ii++;
			}
			else if ((s[count] == c[s[count] - 'a']) && (s[count] != 'j'))
			{
				v[i][ii] = s[count];
				c[s[count] - 'a'] = 0;
				ii++;
			}

			if (ii == 5)
			{
				i++;
				ii = 0;
			}
		}

		for (int count = 0; count < 26; count++)
		{
			if (c[count] != 0 && c[count] != 'j')
			{
				v[i][ii] = c[count];
				ii++;
				if (ii == 5)
				{
					ii = 0;
					i++;
				}
				if (i == 5)
				{
					break;
				}
			}
		}

		string code;
		//getline(cin, code);
		code = argv[4];
		for (int count = 0; count < code.size();)
		{
			char num1 = 0, num2 = 0;
			if (code[count] == ' ')
			{
				count++;
				//cout << " ";
			}
			if ((code[count] != ' ') && (num1 == 0) && (count < code.size()))
			{
				num1 = code[count];
				count++;
			}
			if (code[count] == ' ')
			{
				count++;
			}
			if ((code[count] != ' ') && (num1 != 0) && (count < code.size()))
			{
				num2 = code[count];
				count++;
			}
			else if (count == code.size())
			{
				num2 = 'x';
			}

			if (num1 == num2)
			{
				num2 = 'x';
			}
			//cout << num1 << num2 << endl;

			int forNum11, forNum12, forNum21, forNum22;
			for (int count1 = 0; count1 < 5; count1++)
			{
				for (int count2 = 0; count2 < 5; count2++)
				{
					if (v[count1][count2] == num1)
					{
						forNum11 = count1;
						forNum12 = count2;
					}
					if (v[count1][count2] == num2)
					{
						forNum21 = count1;
						forNum22 = count2;
					}
				}
			}
			if (forNum11 == forNum21)
			{
				if (forNum12 + 1 <= 4 && forNum22 + 1 <= 4)
				{
					cout << (char)(v[forNum11][forNum12 + 1] - 'a' + 'A') << (char)(v[forNum21][forNum22 + 1] - 'a' + 'A');
				}
				else if (forNum12 + 1 > 4 && forNum22 + 1 > 4)
				{
					cout << (char)(v[forNum11][0] - 'a' + 'A') << (char)(v[forNum21][0] - 'a' + 'A');
				}
				else if (forNum22 + 1 > 4)
				{
					cout << (char)(v[forNum11][forNum12 + 1] - 'a' + 'A') << (char)(v[forNum21][0] - 'a' + 'A');
				}
				else if (forNum12 + 1 > 4)
				{
					cout << (char)(v[forNum11][0] - 'a' + 'A') << (char)(v[forNum21][forNum22 + 1] - 'a' + 'A');
				}
			}
			else if (forNum12 == forNum22)
			{
				if (forNum11 + 1 <= 4 && forNum21 + 1 <= 4)
				{
					cout << (char)(v[forNum11 + 1][forNum12] - 'a' + 'A') << (char)(v[forNum21 + 1][forNum22] - 'a' + 'A');
				}
				else if (forNum11 + 1 > 4 && forNum21 + 1 > 4)
				{
					cout << (char)(v[0][forNum12] - 'a' + 'A') << (char)(v[0][forNum22] - 'a' + 'A');
				}
				else if (forNum21 + 1 > 4)
				{
					cout << (char)(v[forNum11 + 1][forNum12] - 'a' + 'A') << (char)(v[0][forNum22] - 'a' + 'A');
				}
				else if (forNum11 + 1 > 4)
				{
					cout << (char)(v[0][forNum12] - 'a' + 'A') << (char)(v[forNum21 + 1][forNum22] - 'a' + 'A');
				}
			}
			else if ((forNum11 != forNum21) && (forNum12 != forNum22))
			{
				cout << (char)(v[forNum11][forNum22] - 'a' + 'A') << (char)(v[forNum21][forNum12] - 'a' + 'A');
			}
			//cout << endl;
		}
	}
	/////////////////////////////////////////////////
	else if (method == "caesar")
	{
		int key;
		string s;

		s = argv[4];
		key = stoi(argv[6]);
		// cin >> key;
		// (cin >> s)

		for (int count = 0; count < s.size(); count++)
		{
			char c;
			c = s[count] + key;
			if (c > 'z')
			{
				c = ((c - 'z') + 'a') - 1;
			}
			c = c - 'a' + 'A';
			cout << c;
		}
		cout << endl;

	}
	/////////////////////////////////////////////////
	else if (method == "vernam")
	{
		string m;
		string key;
		string ans = "";
		m = argv[4];
		key = argv[6];
		//cin >> m;
		//cin >> key;
		int lengthOfKey = key.size();
		int j = 0;
		for (int i = 0; i < m.length(); i++) {
			cout << (char)(((m[i] - 'a') ^ (key[i] - 'a')) + 'A');
		}
	}
	/////////////////////////////////////////////////
	else if (method == "railfence")
	{
		string s;
		int key = stoi(argv[6]);
		s = argv[4];
		vector <vector <char > > subcy(key);
		bool dir = 1;
		for (int i = 0, Nsub = 0; i < s.length(); i++) {
			subcy[Nsub].push_back(s[i]);
			if (Nsub == (key - 1))
				dir = 0;
			else if (Nsub == 0)
				dir = 1;
			if (dir)
				Nsub++;
			else
				Nsub--;
		}
		for (int i = 0; i < key; i++) {
			for (int count = 0; count < subcy[i].size(); count++)
			{
				cout << (char)(subcy[i][count]-'a'+'A');
			}
		}


		/*for (int count1 = 0; count1 < key; count1++)
		{
			for (int count = 0; count * key < s.size(); count++)
			{
				cout << s[count * key + count1];
			}
		}

		cout << endl;*/

	}
	/////////////////////////////////////////////////
	else if (method == "row")
	{
		string text;
		string key;
		text = argv[4];
		key = argv[6];
		//getline(cin, text);
		//cin >> key;

		vector<vector<char>> v;

		v.resize(key.size());
		for (int count = 0; count < v.size(); count++)
		{
			v[count].push_back(key[count]);
		}
		int countText = 0;
		for (int count = 0; countText < text.size(); countText++)
		{
			v[count].push_back(text[countText]);
			count++;
			if (count == key.size())
			{
				count = 0;
			}
		}
		if ((v[0].size() > v[key.size() - 1].size()))
		{
			for (int count = 1; count < v.size(); count++)
			{
				if (v[0].size() > v[count].size())
				{
					v[count].push_back('-');
				}
			}
		}
		//cout << v[0][0];
		int theNext = 126;
		int theOutput;
		for (int countOutput = 0; countOutput < v.size(); countOutput++)
		{
			for (int count = 0; count < v.size(); count++)
			{
				if (theNext >= v[count][0] && v[count][0] != 0)
				{
					theNext = v[count][0];
					theOutput = count;
				}
			}
			for (int count = 1; count < v[theOutput].size(); count++)
			{
				cout << (char)(v[theOutput][count] -'a'+'A');
			}
			v[theOutput][0] = 0;
			theNext = 126;
		}
	}
	return 0;
}
#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class clsString {

private:
	string _Value;

public:
	clsString() {

		_Value = "";
	}
	clsString(string Value) {

		_Value = Value;
	}
	
	void SetString(string Value) {

		_Value = Value;
	}
	string GetString() {

		return _Value;
	}

	__declspec(property(get = GetString, put = SetString)) string value;

	//Count number of words in string.
	static short CountWords(string S1) {

		short pos = 0;
		string Word = "";
		string Delim = " ";
		short CountWord = 0;

		while ((pos = S1.find(Delim)) != S1.npos) {

			Word = S1.substr(0, pos);
			if (Word != "") {

				CountWord++;
			}
			S1.erase(0, pos + Delim.length());
		}
		if (S1 != "") {

			CountWord++;
		}
		return CountWord;
	}
	short CountWords() {

		return CountWords(_Value);
	}

	//Print first Letter of each word.
	static void FirstLetterOfEachWord(string S1) {

		bool IsFirstLetter = true;

		for (short i = 0; i < S1.length(); i++) {

			if (IsFirstLetter && S1[i] != ' ') {

				cout << S1[i] << " ";
			}
			IsFirstLetter = (S1[i] == ' ') ? true : false;
		}
	}
	void FirstLetterOfEachWord() {

		FirstLetterOfEachWord(_Value);
	}

	//Upper first litter in string.
	static string UpperFirstLetterOfEachWord(string S1) {

		bool IsFirstLetter = true;

		for (short i = 0; i < S1.length(); i++) {

			if (IsFirstLetter && S1[i] != ' ') {

				S1[i] = toupper(S1[i]);
			}
			IsFirstLetter = (S1[i] == ' ') ? true : false;
		}
		return S1;
	}
	string UpperFirstLetterOfEachWord() {

		return UpperFirstLetterOfEachWord(_Value);
	}

	//lower first litter in string.
	static string LowerFirstLetterOfEachWord(string S1) {

		bool IsFirstLetter = true;

		for (short i = 0; i < S1.length(); i++) {

			if (IsFirstLetter && S1[i] != ' ') {

				S1[i] = tolower(S1[i]);
			}
			IsFirstLetter = (S1[i] == ' ') ? true : false;
		}
		return S1;
	}
	string LowerFirstLetterOfEachWord() {

		return LowerFirstLetterOfEachWord(_Value);
	}

	//Upper all letter in string.
	static string UpperAllString(string S1) {

		for (short i = 0; i < S1.length(); i++) {

			S1[i] = toupper(S1[i]);
		}
		return S1;
	}
	string UpperAllString() {

		return UpperAllString(_Value);
	}

	//Lower all letter in string.
	static string LowerEachWordLetter(string S1) {

		for (short i = 0; i < S1.length(); i++) {

			S1[i] = tolower(S1[i]);
		}
		return S1;
	}
	string LowerEachWordLetter() {

		return LowerEachWordLetter(_Value);
	}

	//Invert Letter case.
	static char invertLetterCase(char c) {

		return (isupper(c)) ? tolower(c) : toupper(c);
	}

	//Invert all letters of string.
	static string InvertAllLetters(string S1) {

		for (short i = 0; i < S1.length(); i++) {

			S1[i] = invertLetterCase(S1[i]);
		}
		return S1;
	}
	string InvertAllLetters() {

		return InvertAllLetters(_Value);
	}

	//Count Capital Letters.
	static short CountCapitalLetters(string S1) {

		short CapitalCoun = 0;

		for (short i = 0; i < S1.length(); i++) {

			if (isupper(S1[i])) {

				CapitalCoun++;
			}
		}
		return CapitalCoun;
	}
	short CountCapitalLetters() {

		return CountCapitalLetters(_Value);
	}

	//Count Lower Letters.
	static short CountSmallLetters(string S1) {

		short SmallCoun = 0;

		for (short i = 0; i < S1.length(); i++) {

			if (islower(S1[i])) {

				SmallCoun++;
			}
		}
		return SmallCoun;
	}
	short CountSmallLetters() {

		return CountSmallLetters(_Value);
	}

	//Count Punctuations.
	static short CountPunctuation(string S1) {

		short PunctCoun = 0;

		for (short i = 0; i < S1.length(); i++) {

			if (ispunct(S1[i])) {

				PunctCoun++;
			}
		}
		return PunctCoun;
	}
	short CountPunctuation() {

		return CountPunctuation(_Value);
	}

	//Count Chosed Letter.
	static short CountChoosedLetter(string S1,char Character, bool MatchCase) {

		short ChoosedLetterCoun = 0;

		for (short i = 0; i < S1.length(); i++) {

			if (MatchCase) {
				}
	
				if (S1[i]==Character) {

					ChoosedLetterCoun++;
		}
			else {

				if (toupper(S1[i]) == toupper(Character)) {

					ChoosedLetterCoun++;
				}
			}
		}
		return ChoosedLetterCoun;
	}
	short CountChoosedLetter(char Character, bool MatchCase) {

		return CountChoosedLetter(_Value, Character, MatchCase);
	}

	//Is vowel.
	static bool IsVowel(char C) {

		C = tolower(C);
		return ((C == 'a') || (C == 'e') || (C == 'i') || (C == 'o') || (C == 'u'));
	}

	//Count Vowels.
	static short VowelCount(string S1) {

		short VowelCounter = 0;
		for (short i = 0; i < S1.length(); i++) {

			if (IsVowel(S1[i]))
				VowelCounter++;
		}
		return VowelCounter;
	}
	short VowelCount() {

		return VowelCount(_Value);
	}

	//Print vowels.
	static void PrintVowels(string S1) {

		for (short i = 0; i < S1.length(); i++) {

			if (IsVowel(S1[i]))
				cout << S1[i] << " ";
		}
	}
	void PrintVowels() {

		PrintVowels(_Value);
	}

	//Split string function; store words on vector.
	static vector <string> Split(string S1, string Delim) {

		short pos = 0;
		string Word = "";
		vector <string> vString;

		while ((pos = S1.find(Delim)) != S1.npos) {

			Word = S1.substr(0, pos);
			if (Word != "") {

				vString.push_back(Word);
			}
			S1.erase(0, pos + Delim.length());
		}
		if (S1 != "") {

			vString.push_back(S1);
		}
		return vString;
	}
	vector <string> Split(string Delim) {

		return Split(_Value, Delim);
	}

	//Trim left.
	static string TrimLeft(string S1) {

		for (short i = 0; i < S1.length(); i++) {

			if (S1[i] != ' ') {

				return S1.substr(i, S1.length() - i);
			}
		}
	}
	string TrimLeft() {

		return TrimLeft(_Value);
	}

	//Trim right.
	static string TrimRight(string S1) {

		for (short i = S1.length() - 1; i >= 0; i--) {

			if (S1[i] != ' ' && !ispunct(S1[i])) {

				return S1.substr(0, i + 1);
			}
		}
	}
	string TrimRight() {

		return TrimRight(_Value);
	}

	//Trim Both sides.
	static string Trim(string S1) {

		return TrimLeft(TrimRight(S1));
	}
	string Trim() {

		return Trim(_Value);
	}

	//Join string.
	static string JoinString(vector <string> vS1Data, string Delim) {

		string Word;
		for (string& vWord : vS1Data) {

			Word += vWord + Delim;
		}
		return Word.substr(0, Word.length() - Delim.length());
	}
	string JoinString(string Delim) {

		vector <string> vS1Data = Split(" ");
		return JoinString(vS1Data, Delim);
	}

	//Reverse string.
	static string ReverseString(string S1, string Delim) {

		vector <string> vS1Data = Split(S1, Delim);
		string RevS1;

		vector <string>::iterator iter = vS1Data.end();

		while (iter != vS1Data.begin()) {

			--iter;
			RevS1 += *iter + Delim;
		}
		return RevS1.substr(0, RevS1.length() - Delim.length());
	}
	string ReverseString(string Delim) {

		return ReverseString(Trim(_Value), Delim);
	}
	
	//Replace word.
	static string ReplaceWordBuiltInF(string S1, string WordToReplace, string ReplaceTo) {

		short pos;
		while ((pos = S1.find(WordToReplace)) != S1.npos) {

			S1.replace(pos, WordToReplace.length(), ReplaceTo);
		}
		return S1;
	}
	string ReplaceWordBuiltInF(string WordToReplace, string ReplaceTo) {

		return ReplaceWordBuiltInF(Trim(_Value), WordToReplace, ReplaceTo);
	}

	//Replace word without built in function.
	static string ReplaceWord(string S1, string WordToReplace, string ReplaceTo, string Delim, bool MatchCase = true) {

		vector <string> vS1Data;

		vS1Data = Split(S1, Delim);

		for (string& vWord : vS1Data) {

			if (MatchCase) {

				if (vWord == WordToReplace) {

					vWord = ReplaceTo;
				}
			}
			else {

				if (LowerEachWordLetter(vWord) == LowerEachWordLetter(WordToReplace)) {

					vWord = ReplaceTo;
				}
			}
		}

		return JoinString(vS1Data, Delim);
	}
	string ReplaceWord(string WordToReplace, string ReplaceTo, string Delim, bool MatchCase = true) {

		return ReplaceWord(Trim(_Value), WordToReplace, ReplaceTo, Delim, MatchCase);
	}

	//Remove all punctuation from string.
	static string RemoveAllPunct(string S1) {

		string Word;

		for (short i = 0; i < S1.length(); i++) {

			if (!ispunct(S1[i])) {

				Word += S1[i];
			}
		}
		return Word;
	}
	string RemoveAllPunct() {

		return RemoveAllPunct(Trim(_Value));
	}

};


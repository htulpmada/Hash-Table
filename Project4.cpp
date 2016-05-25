// project4.cpp : main project file.

//#include "stdafx.h"//remove before submit!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "HashTable.h"
using namespace std;

//helper functions
Record getTweet(){
	std::vector<std::string> newtweet;
	std::string line;
	std::cout<<"\nTweet: ";
	std::cin>>line;
	newtweet.push_back(line);
	std::cout<<"\nUsername: ";
	std::cin>>line;
	newtweet.push_back(line);
	Record r=Record(".",newtweet[0],newtweet[1]);
	return r;
}


std::vector<string> ReadInTweets(int argc, char* argv[]){
	
   if (argc != 2) {
      std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
      exit(1);}
    std::ifstream fin;
	std::string line;
	std::vector<string> words;
	

	if (argc<2){std::cout << "sorry you need to enter a file as command line argument"; exit(0);}
	fin.open(argv[1]);
    if (fin!=NULL){
		while (!fin.eof()){
			getline(fin,line);
			std::string Line= std::string(line);
			words.push_back(line);
		}
		fin.close();
		return words;
	}
}

std::vector<Record> makeRecords(std::vector<string> words){
	std::vector<Record> recs;
		words.push_back("");

	for(int i=0;words.size()-1>static_cast<std::vector<int>::size_type>(i);i++){
		std::vector<string> word;
		if(words[i].size()>static_cast<std::vector<int>::size_type>(5)){continue;}
		word.push_back(words[i+1].substr(14,19));
		word.push_back(words[i+2].substr(8,words[i+2].size()-10));
		if(words[i+4][0]=='{'){word.push_back(words[i+3].substr(15,words[i+3].size()-18));;}
		else{word.push_back(words[i+3].substr(15,words[i+3].size()-17));}
		Record r1=Record(word[0],word[1],word[2]);
		recs.push_back(r1);
	}
	return recs;
}

void Menu(HashTable h){
	while(1){
		char choice;
		std::string line;
		Record s;
		//int i;
		std::cout<<"\n1. Enter new Tweeet\n";
		std::cout<<"2. Delete all tweets for a given screen_name\n";
		std::cout<<"3. View Tweets\n";
		std::cout<<"4. Quit\n";
		choice=std::getchar();
		switch(choice)
		{
			case('1'):
				s=getTweet();
				h.Put(s);
				h.upCount();
			//	i=h.Count();
				break;
			case('2'):
				std::cout<<"\nUsername: ";
				std::cin>>line;
				h.Remove(line);
				h.downCount();
			//	i=h.Count();
				break;
			case('3'):
				std::cout<<"\nUsername: ";
				std::cin>>line;
				h.PrintTable(line);
			//	i=h.Count();
				break;
			case('4'):
			//	i=h.Count();
				exit(0);	
		}
	}
}

int main(int argc, char* argv[]) {
	std::vector<string> tweetlist;
    std::vector<Record> Records;
	HashTable hash;
	int numOfRecs=0;
	tweetlist=ReadInTweets(argc,argv);
	Records=makeRecords(tweetlist);   
	for(numOfRecs;Records.size()!=static_cast<std::vector<int>::size_type>(numOfRecs);numOfRecs++){hash.Put(Records[numOfRecs]);}
	Menu(hash);
    return 0;
}

#include <vector>
#include <ctime>
#include <iterator>
#include <iostream>

class Record {
public:
	void Add(std::string);

	std::vector<std::string> tweets;
	std::string screen_name;
	std::vector<std::string> created_at;
Record(std::string time="",std::string text="", std::string name="")
{
	created_at.push_back(time);
	tweets.push_back(text);
	screen_name=name;
}

int compareTime(std::string s){
	int index;
	for(int i=0;created_at.size()!=static_cast<std::vector<int>::size_type>(i);i++){//every entry
		for(int j=0;created_at[i].size()!=static_cast<std::vector<int>::size_type>(j);j++){//every letter
			if(s[j]>created_at[i][j]){
				continue;
			}
			else{
				index=i;
			}
		}
	}
	return index;
}
void Add(std::string s,std::string t){
	int c=compareTime(t);
	if(static_cast<std::vector<int>::size_type>(c)<tweets.size())
	{
		tweets.insert(tweets.begin()+c,s);
		created_at.insert(created_at.begin()+c,t);
	}
	else
	{
	tweets.push_back(s);
	created_at.push_back(t);
	}
}


void Delete(){
	std::vector<std::string> tweet;
	std::vector<std::string> created;
	tweets=tweet;
	created_at=created;
	std::cout<<"\n All tweets deleted:\n";
}

void Print(){
	std::cout<<"\nname: "<<screen_name<<"\n";
	for(int i=0;tweets.size()!=static_cast<std::vector<int>::size_type>(i);i++){
		std::cout<<"tweet: "<<tweets[i]<<"\n";
	}	
}


};
